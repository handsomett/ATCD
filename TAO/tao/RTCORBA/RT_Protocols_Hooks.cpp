#include "RT_Protocols_Hooks.h"

#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0

#include "RT_Policy_i.h"
#include "Priority_Mapping_Manager.h"
#include "RT_Stub.h"

#include "tao/Stub.h"
#include "tao/ORB_Core.h"
#include "tao/MProfile.h"
#include "tao/Service_Context.h"
#include "tao/Acceptor_Registry.h"
#include "tao/Thread_Lane_Resources.h"
#include "tao/Protocol_Factory.h"
#include "tao/Transport_Acceptor.h"
#include "tao/Transport_Connector.h"
#include "tao/Policy_Set.h"
#include "tao/IIOP_Transport.h"
#include "tao/debug.h"

#include "ace/Dynamic_Service.h"
#include "ace/OS_NS_string.h"


ACE_RCSID (RTCORBA,
           RT_Protocols_Hooks,
           "$Id$")


TAO_RT_Protocols_Hooks::Client_Protocols_Hook
  TAO_RT_Protocols_Hooks::client_protocols_hook_ = 0;
TAO_RT_Protocols_Hooks::Server_Protocols_Hook
  TAO_RT_Protocols_Hooks::server_protocols_hook_ = 0;

TAO_RT_Protocols_Hooks::TAO_RT_Protocols_Hooks (void)
{
}

TAO_RT_Protocols_Hooks::~TAO_RT_Protocols_Hooks (void)
{
}

void
TAO_RT_Protocols_Hooks::init_hooks (TAO_ORB_Core *orb_core
                                    ACE_ENV_ARG_DECL)
{
  this->orb_core_ = orb_core;

  // Save a reference to the priority mapping manager.
  CORBA::Object_var obj =
    orb_core->object_ref_table ().resolve_initial_references (
                                      TAO_OBJID_PRIORITYMAPPINGMANAGER
                                      ACE_ENV_ARG_PARAMETER
                                    );
  ACE_CHECK;

  this->mapping_manager_ =
    TAO_Priority_Mapping_Manager::_narrow (obj.in ()
                                           ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Save a reference to the priority mapping manager.
  CORBA::Object_var object =
    orb_core->object_ref_table ().resolve_initial_references (
                                      TAO_OBJID_NETWORKPRIORITYMAPPINGMANAGER
                                      ACE_ENV_ARG_PARAMETER
                                    );
  ACE_CHECK;

  this->network_mapping_manager_ =
    TAO_Network_Priority_Mapping_Manager::_narrow (object.in ()
                                                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  object =
    this->orb_core_->object_ref_table ().resolve_initial_references (
                                             "RTCurrent"
                                             ACE_ENV_ARG_PARAMETER
                                           );
  ACE_CHECK;

  this->current_ =
    RTCORBA::Current::_narrow (object.in ()
                               ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}

int
TAO_RT_Protocols_Hooks::call_client_protocols_hook (
    int &send_buffer_size,
    int &recv_buffer_size,
    int &no_delay,
    int &enable_network_priority,
    const char *protocol_type
  )
{
  if (TAO_RT_Protocols_Hooks::client_protocols_hook_ == 0)
    return -1;

  (*TAO_RT_Protocols_Hooks::client_protocols_hook_) (this->orb_core_,
                                                     send_buffer_size,
                                                     recv_buffer_size,
                                                     no_delay,
                                                     enable_network_priority,
                                                     protocol_type);

  return 0;
}

void
TAO_RT_Protocols_Hooks::set_client_protocols_hook (Client_Protocols_Hook hook)
{
  TAO_RT_Protocols_Hooks::client_protocols_hook_ = hook;
  // Saving the hook pointer so that we can use it later when needed.
}

int
TAO_RT_Protocols_Hooks::call_server_protocols_hook (
    int &send_buffer_size,
    int &recv_buffer_size,
    int &no_delay,
    int &enable_network_priority,
    const char *protocol_type
  )
{
  if (TAO_RT_Protocols_Hooks::server_protocols_hook_ == 0)
    {
      return -1;
    }

  int result_value =
    (*TAO_RT_Protocols_Hooks::server_protocols_hook_) (this->orb_core_,
                                                       send_buffer_size,
                                                       recv_buffer_size,
                                                       no_delay,
                                                       enable_network_priority,
                                                       protocol_type);

  if (result_value != 0)
    {
      return -1;
    }

  return 0;
}

void
TAO_RT_Protocols_Hooks::set_server_protocols_hook (Server_Protocols_Hook hook)
{
  TAO_RT_Protocols_Hooks::server_protocols_hook_ = hook;
  // Saving the hook pointer so that we can use it later when needed.
}

int
TAO_RT_Protocols_Hooks::update_client_protocol_properties (
    TAO_Stub *stub,
    TAO_Transport *transport,
    const char *protocol_type
  )
{
  if (TAO_debug_level)
    ACE_DEBUG ((LM_DEBUG,
                "TAO_RT_Protocols_Hooks::"
                "get_effective_client_protocol_properties\n"));

  ACE_TRY_NEW_ENV
    {
      RTCORBA::ProtocolProperties_var properties =
        RTCORBA::ProtocolProperties::_nil ();

      TAO_RT_Stub *rt_stub = ACE_dynamic_cast (TAO_RT_Stub *,
                                               stub);

      CORBA::Policy* policy = rt_stub->client_protocol ();

      RTCORBA::ClientProtocolPolicy_var client_protocols_policy;
      TAO_ClientProtocolPolicy *client_protocols = 0;

      if (!CORBA::is_nil (policy))
        {
          client_protocols_policy =
            RTCORBA::ClientProtocolPolicy::_narrow (policy
                                                    ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          client_protocols =
            ACE_dynamic_cast (TAO_ClientProtocolPolicy *,
                              client_protocols_policy.in ());

          if (client_protocols != 0)
            {
              // TAO_ClientProtocolPolicy
              RTCORBA::ProtocolList & protocols =
                client_protocols->protocols_rep ();

              for (CORBA::ULong j = 0; j < protocols.length (); ++j)
                {
                  if (protocols[j].protocol_type == IOP::TAG_INTERNET_IOP)
                    {
                      properties =
                        RTCORBA::ProtocolProperties::_narrow (
                            protocols[j].transport_protocol_properties.in ()
                            ACE_ENV_ARG_PARAMETER
                          );
                      ACE_TRY_CHECK;

                      if (ACE_OS::strcmp (protocol_type, "iiop") == 0)
                        {
                          break;
                        }
                    }
                }
            }

          if (ACE_OS::strcmp (protocol_type, "iiop") == 0)
            {
              if (!CORBA::is_nil (properties.in ()))
                {
                  RTCORBA::TCPProtocolProperties_var tcp_properties =
                    RTCORBA::TCPProtocolProperties::_narrow (
                        properties.in ()
                        ACE_ENV_ARG_PARAMETER
                      );
                  ACE_TRY_CHECK;

                  const int send_buffer_size =
                    tcp_properties->send_buffer_size (
                                        ACE_ENV_SINGLE_ARG_PARAMETER
                                      );
                  ACE_TRY_CHECK;

                  const int recv_buffer_size =
                    tcp_properties->recv_buffer_size (
                                        ACE_ENV_SINGLE_ARG_PARAMETER
                                      );
                  ACE_TRY_CHECK;

                  const int no_delay =
                    tcp_properties->no_delay (
                                        ACE_ENV_SINGLE_ARG_PARAMETER
                                      );
                  ACE_TRY_CHECK;

                  const int enable_network_priority =
                    tcp_properties->enable_network_priority (
                                        ACE_ENV_SINGLE_ARG_PARAMETER
                                      );
                  ACE_TRY_CHECK;

                  TAO_IIOP_Transport *iiop_transport =
                    ACE_dynamic_cast (TAO_IIOP_Transport *,
                                      transport);

                  iiop_transport->update_protocol_properties (
                                      send_buffer_size,
                                      recv_buffer_size,
                                      no_delay,
                                      enable_network_priority
                                    );
                }
            }
        }
    }
  ACE_CATCHANY
    {
      if (TAO_debug_level > 4)
        ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                             "TAO_RT_Protocols_Hooks::"
                             "get_effective_client_protocol_properties");

      return -1;
    }
  ACE_ENDTRY;

  return 0;
}

int
TAO_RT_Protocols_Hooks::update_server_protocol_properties (
    CORBA::Policy *policy,
    TAO_Transport *transport,
    const char *protocol_type
  )
{

  if (TAO_debug_level)
    ACE_DEBUG ((LM_DEBUG,
                "TAO_RT_Protocols_Hooks::"
                "get_effective_server_protocol_properties\n"));

  ACE_TRY_NEW_ENV
    {
      RTCORBA::ProtocolProperties_var properties =
        RTCORBA::ProtocolProperties::_nil ();

      RTCORBA::ServerProtocolPolicy_var server_protocols_policy;
      TAO_ServerProtocolPolicy *server_protocols = 0;

      if (!CORBA::is_nil (policy))
        {
          server_protocols_policy =
            RTCORBA::ServerProtocolPolicy::_narrow (policy
                                                    ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          server_protocols =
            ACE_dynamic_cast (TAO_ServerProtocolPolicy *,
                              server_protocols_policy.in ());

          if (server_protocols != 0)
            {
              // TAO_ServerProtocolPolicy
              RTCORBA::ProtocolList & protocols =
                server_protocols->protocols_rep ();

              for (CORBA::ULong j = 0; j < protocols.length (); ++j)
                {
                  if (protocols[j].protocol_type == IOP::TAG_INTERNET_IOP)
                    {
                      properties =
                        RTCORBA::ProtocolProperties::_narrow (
                          protocols[j].transport_protocol_properties.in ()
                          ACE_ENV_ARG_PARAMETER);
                      ACE_TRY_CHECK;

                      if (ACE_OS::strcmp (protocol_type, "iiop") == 0)
                        {
                          break;
                        }
                    }
                }
            }

          if (ACE_OS::strcmp (protocol_type, "iiop") == 0)
            {
              if (!CORBA::is_nil (properties.in ()))
                {
                  RTCORBA::TCPProtocolProperties_var tcp_properties =
                    RTCORBA::TCPProtocolProperties::_narrow (
                        properties.in ()
                        ACE_ENV_ARG_PARAMETER
                      );
                  ACE_TRY_CHECK;

                  const int send_buffer_size =
                    tcp_properties->send_buffer_size (
                                        ACE_ENV_SINGLE_ARG_PARAMETER
                                      );
                  ACE_TRY_CHECK;

                  const int recv_buffer_size =
                    tcp_properties->recv_buffer_size (
                                        ACE_ENV_SINGLE_ARG_PARAMETER
                                      );
                  ACE_TRY_CHECK;

                  const int no_delay =
                    tcp_properties->no_delay (
                                        ACE_ENV_SINGLE_ARG_PARAMETER
                                      );
                  ACE_TRY_CHECK;

                  const int enable_network_priority =
                    tcp_properties->enable_network_priority (
                                        ACE_ENV_SINGLE_ARG_PARAMETER
                                      );
                  ACE_TRY_CHECK;

                  TAO_IIOP_Transport *iiop_transport =
                    ACE_dynamic_cast (TAO_IIOP_Transport *,
                                      transport);

                  iiop_transport->update_protocol_properties (
                                      send_buffer_size,
                                      recv_buffer_size,
                                      no_delay,
                                      enable_network_priority
                                    );
                }
            }
        }
    }
  ACE_CATCHANY
    {
      if (TAO_debug_level > 4)
        ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                             "TAO_RT_Protocols_Hooks::"
                             "get_effective_client_protocol_properties");

      return -1;
    }
  ACE_ENDTRY;

  return 0;
}

CORBA::Long
TAO_RT_Protocols_Hooks::get_dscp_codepoint (void)
{
  if (TAO_debug_level)
    ACE_DEBUG ((LM_DEBUG,
                "TAO_RT_Protocols_Hooks::get_dscp_codepoint\n"));

  CORBA::Long codepoint = 0;

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Make several invocation, changing the priority of this thread
      // for each.

      RTCORBA::NetworkPriorityMapping *pm =
        this->network_mapping_manager_->mapping ();

      const CORBA::Short priority =
        this->current_->the_priority (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (pm->to_network (priority, codepoint) == 0)
        {
          if (TAO_debug_level > 0)
            {
              ACE_ERROR ((LM_ERROR,
                          "Cannot convert corba priority %d "
                          "to network priority\n",
                          priority));
            }

          return -1;
        }
    }
  ACE_CATCHANY
    {
      if (TAO_debug_level > 0)
        {
          ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                               "TAO_RT_Protocols_Hooks::get_dscp_codepoint");
        }

      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return codepoint;
}

void
TAO_RT_Protocols_Hooks::rt_service_context (
    TAO_Stub *stub,
    TAO_Service_Context &service_context,
    CORBA::Boolean restart
    ACE_ENV_ARG_DECL
  )
{
  // If the restart flag is true, then this call for a
  // reinvocation. We need not prepare the Service Context List once
  // again. We can use the already existing one.
  if (!restart)
    {
      TAO_RT_Stub *rt_stub = ACE_dynamic_cast (TAO_RT_Stub *,
                                               stub);
      CORBA::Policy *priority_model_policy =
        rt_stub->exposed_priority_model (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
      if (priority_model_policy)
        {

          CORBA::Policy *priority_model_policy =
            rt_stub->exposed_priority_model (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_CHECK;

          CORBA::Short client_priority;
          int status =
            this->get_thread_CORBA_priority (client_priority
                                             ACE_ENV_ARG_PARAMETER);
          if (status == -1)
            ACE_THROW (CORBA::DATA_CONVERSION (1, CORBA::COMPLETED_NO));


          this->add_rt_service_context_hook (service_context,
                                             priority_model_policy,
                                             client_priority
                                             ACE_ENV_ARG_PARAMETER);
          ACE_CHECK;
        }
      else
        {
          // The Object does not contain PriorityModel policy in its IOR.
          // We must be talking to a non-RT ORB.  Do nothing.
        }
    }
}

void
TAO_RT_Protocols_Hooks::add_rt_service_context_hook (
    TAO_Service_Context &service_context,
    CORBA::Policy *model_policy,
    CORBA::Short &client_priority
    ACE_ENV_ARG_DECL
  )
{

  RTCORBA::PriorityModelPolicy_var model_policy_ptr =
    RTCORBA::PriorityModelPolicy::_narrow (model_policy
                                           ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  TAO_PriorityModelPolicy *priority_model =
    ACE_static_cast (TAO_PriorityModelPolicy *,
                     model_policy_ptr.in ());

  if (priority_model->get_priority_model () == RTCORBA::CLIENT_PROPAGATED)
    {
      // Encapsulate the priority of the current thread into
      // a service context.
      TAO_OutputCDR cdr;
      if ((cdr << ACE_OutputCDR::from_boolean (TAO_ENCAP_BYTE_ORDER) == 0)
          || (cdr << client_priority) == 0)
        {
          ACE_THROW (CORBA::MARSHAL ());
        }

      service_context.set_context (IOP::RTCorbaPriority, cdr);
    }
}

void
TAO_RT_Protocols_Hooks::get_selector_hook (
    CORBA::Policy *model_policy,
    CORBA::Boolean &is_client_propagated,
    CORBA::Short &server_priority
  )
{

  RTCORBA::PriorityModelPolicy_var model_policy_ptr =
    RTCORBA::PriorityModelPolicy::_narrow (model_policy);

  TAO_PriorityModelPolicy *priority_model_policy =
    ACE_static_cast (TAO_PriorityModelPolicy *,
                     model_policy_ptr.in ());

  if (priority_model_policy->get_priority_model ()
        == RTCORBA::CLIENT_PROPAGATED)
    {
      is_client_propagated = 1;
    }

  if (!is_client_propagated)
    {
      server_priority = priority_model_policy->server_priority ();
    }

  return;
}

void
TAO_RT_Protocols_Hooks::get_selector_bands_policy_hook (
    CORBA::Policy *bands_policy,
    CORBA::Short priority,
    CORBA::Short &min_priority,
    CORBA::Short &max_priority,
    int &in_range
  )
{
  RTCORBA::PriorityBandedConnectionPolicy_var bands_policy_ptr =
    RTCORBA::PriorityBandedConnectionPolicy::_narrow (bands_policy);

  TAO_PriorityBandedConnectionPolicy *priority_bands_policy =
    ACE_static_cast (TAO_PriorityBandedConnectionPolicy *,
                     bands_policy_ptr.in ());

  // Find the band with the range covering our target priority.
  RTCORBA::PriorityBands &bands =
    priority_bands_policy->priority_bands_rep ();

  for (CORBA::ULong i = 0; i < bands.length (); ++i)
    {
      if (bands[i].low <= priority && bands[i].high >= priority)
        {
          min_priority = bands[i].low;
          max_priority = bands[i].high;

          in_range = 1;
          break;
        }
    }
}

int
TAO_RT_Protocols_Hooks::get_thread_CORBA_priority (CORBA::Short &priority
                                                   ACE_ENV_ARG_DECL)
{
  CORBA::Short native_priority = 0;
  int result =
    this->get_thread_CORBA_and_native_priority (priority,
                                                native_priority
                                                ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  if (result == -1)
    {
      return result;
    }

  return 0;
}

int
TAO_RT_Protocols_Hooks::get_thread_native_priority (
    CORBA::Short &native_priority
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  ACE_hthread_t current;
  ACE_Thread::self (current);

  int priority;

  if (ACE_Thread::getprio (current, priority) == -1)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) - ")
                  ACE_TEXT ("RT_Protocols_Hooks::get_thread_priority: ")
                  ACE_TEXT (" ACE_Thread::get_prio\n")));

      return -1;
    }

  native_priority = CORBA::Short (priority);
  return 0;
}

int
TAO_RT_Protocols_Hooks::get_thread_CORBA_and_native_priority (
    CORBA::Short &priority,
    CORBA::Short &native_priority
    ACE_ENV_ARG_DECL
  )
{
  int result =
    this->get_thread_native_priority (native_priority
                                      ACE_ENV_ARG_PARAMETER);
  if (result == -1)
    {
      return result;
    }

  TAO_Priority_Mapping *priority_mapping =
    this->mapping_manager_.in ()->mapping ();

  if (priority_mapping->to_CORBA (native_priority, priority) == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) - ")
                  ACE_TEXT ("RT_Protocols_Hooks::get_thread_priority: ")
                  ACE_TEXT ("Priority_Mapping::to_CORBA\n")));
      return -1;
    }

  return 0;
}

int
TAO_RT_Protocols_Hooks::set_thread_CORBA_priority (CORBA::Short priority
                                                   ACE_ENV_ARG_DECL)
{
  TAO_Priority_Mapping *priority_mapping =
    this->mapping_manager_.in ()->mapping ();

  CORBA::Short native_priority;

  if (priority_mapping->to_native (priority, native_priority) == 0)
    {
      return -1;
    }

  return this->set_thread_native_priority (native_priority
                                           ACE_ENV_ARG_PARAMETER);
}

int
TAO_RT_Protocols_Hooks::set_thread_native_priority (
    CORBA::Short native_priority
    ACE_ENV_ARG_DECL_NOT_USED
   )
{
  ACE_hthread_t current;
  ACE_Thread::self (current);

  if (ACE_Thread::setprio (current, native_priority) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_LIB_TEXT ("(%N,%l) Error setting thread ")
                         ACE_LIB_TEXT ("priority to %d, errno %d %m\n"),
                         native_priority,
                         errno ),
                       -1);
    }

  return 0;
}

int
TAO_RT_Protocols_Hooks::set_default_policies (ACE_ENV_SINGLE_ARG_DECL)
{
  // Set RTCORBA policy defaults.
  // Set RTCORBA::ServerProtocolPolicy and
  // RTCORBA::ClientProtocolPolicy defaults to include all protocols
  // that were loaded into this ORB.
  // First, create a protocol list.

  TAO_ProtocolFactorySet *pfs = this->orb_core_->protocol_factories ();

  RTCORBA::ProtocolList protocols;
  protocols.length (ACE_static_cast (CORBA::ULong, pfs->size ()));

  int i = 0;
  for (TAO_ProtocolFactorySetItor factory = pfs->begin ();
       factory != pfs->end ();
       ++factory, ++i)
    {
      CORBA::ULong protocol_type = (*factory)->factory ()->tag ();
      protocols[i].protocol_type = protocol_type;
      protocols[i].orb_protocol_properties =
        RTCORBA::ProtocolProperties::_nil ();
      // @@ Later, we will likely migrate to using RTCORBA protocol
      // policies for configuration of protocols in nonRT use cases.
      // Then, the code below will change to each protocol factory
      // being responsible for creation of its own default protocol
      // properties.
      protocols[i].transport_protocol_properties =
        TAO_Protocol_Properties_Factory::create_transport_protocol_property
        (protocol_type);
    }

  // Set ServerProtocolPolicy.
  TAO_ServerProtocolPolicy *server_protocol_policy = 0;
  ACE_NEW_RETURN (server_protocol_policy,
                  TAO_ServerProtocolPolicy (protocols),
                  -1);

  RTCORBA::ServerProtocolPolicy_var safe_server_protocol_policy =
    server_protocol_policy;

  this->orb_core_->get_default_policies ()->set_policy (server_protocol_policy
                                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  // Set ClientProtocolPolicy.
  // NOTE: ClientProtocolPolicy default is used ONLY for protocol
  // configuration (not protocol preference) IF there is no ORB-level
  // override.  It is not used when computing effective policy value
  // for preferencing protocols.
  TAO_ClientProtocolPolicy *client_protocol_policy = 0;
  ACE_NEW_RETURN (client_protocol_policy,
                  TAO_ClientProtocolPolicy (protocols),
                  -1);

  RTCORBA::ClientProtocolPolicy_var safe_client_protocol_policy =
    client_protocol_policy;

  this->orb_core_->get_default_policies ()->set_policy (
                                                client_protocol_policy
                                                ACE_ENV_ARG_PARAMETER
                                              );
  ACE_CHECK_RETURN (-1);

  return 0;
}

int
TAO_RT_Protocols_Hooks::set_default_server_protocol_policy (
    TAO_Acceptor_Registry &acceptor_registry
    ACE_ENV_ARG_DECL
  )
{
  RTCORBA::ProtocolList protocols;

  TAO_AcceptorSetIterator end =
    acceptor_registry.end ();

  for (TAO_AcceptorSetIterator acceptor =
         acceptor_registry.begin ();
       acceptor != end;
       ++acceptor)
    {
      if (*acceptor == 0)
        continue;

      CORBA::ULong current_length =
        protocols.length ();

      protocols.length (current_length + 1);

      protocols[current_length].protocol_type =
        (*acceptor)->tag ();

      protocols[current_length].orb_protocol_properties =
        RTCORBA::ProtocolProperties::_nil ();

      // @@ Later, we will likely migrate to using RTCORBA protocol
      // policies for configuration of protocols in nonRT use cases.
      // Then, the code below will change to each protocol factory
      // being responsible for creation of its own default protocol
      // properties.
      protocols[current_length].transport_protocol_properties =
        TAO_Protocol_Properties_Factory::create_transport_protocol_property (
            (*acceptor)->tag ()
          );
    }

  // Set ServerProtocolPolicy.
  TAO_ServerProtocolPolicy *server_protocol_policy = 0;
  ACE_NEW_RETURN (server_protocol_policy,
                  TAO_ServerProtocolPolicy (protocols),
                  -1);

  RTCORBA::ServerProtocolPolicy_var safe_server_protocol_policy =
    server_protocol_policy;

  this->orb_core_->get_default_policies ()->set_policy (
                                                server_protocol_policy
                                                ACE_ENV_ARG_PARAMETER
                                              );
  ACE_CHECK_RETURN (-1);

  return 0;
}

ACE_STATIC_SVC_DEFINE (TAO_RT_Protocols_Hooks,
                       ACE_TEXT ("RT_Protocols_Hooks"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_RT_Protocols_Hooks),
                       ACE_Service_Type::DELETE_THIS
                       | ACE_Service_Type::DELETE_OBJ,
                       0)
  ACE_FACTORY_DEFINE (TAO_RTCORBA, TAO_RT_Protocols_Hooks)

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class ACE_Dynamic_Service<TAO_RT_Protocols_Hooks>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Dynamic_Service<TAO_RT_Protocols_Hooks>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_HAS_CORBA_MESSAGING != 0 */
