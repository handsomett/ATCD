// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:390

#ifndef _TAO_IDL_ORIG_IFR_BASES_H_
#define _TAO_IDL_ORIG_IFR_BASES_H_

#include /**/ "ace/pre.h"

#include "IFR_BaseC.h"
#include "tao/orb_typesS.h"
#include "tao/Typecode_typesS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_sh.cpp:49

namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87

  class IRObject;
  typedef IRObject *IRObject_ptr;

  class _TAO_IRObject_Strategized_Proxy_Broker;

  class TAO_IFR_Client_Export IRObject
    : public virtual PortableServer::ServantBase
  {
  protected:
    IRObject (void);

  public:
    // Useful for template programming.
    typedef ::CORBA::IRObject _stub_type;
    typedef ::CORBA::IRObject_ptr _stub_ptr_type;
    typedef ::CORBA::IRObject_var _stub_var_type;

    IRObject (const IRObject& rhs);
    virtual ~IRObject (void);

    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall
        ACE_ENV_ARG_DECL
      );

    ::CORBA::IRObject *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::DefinitionKind def_kind (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_def_kind_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void destroy_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
  };

  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration
  //

  // TAO_IDL - Generated from
  // be\be_visitor_interface/strategized_proxy_broker_sh.cpp:36

  class TAO_IFR_Client_Export _TAO_IRObject_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public:
    _TAO_IRObject_Strategized_Proxy_Broker (void);

    virtual ~_TAO_IRObject_Strategized_Proxy_Broker (void);

    TAO::Collocation_Strategy
    get_strategy (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::SystemException));

    void
    dispatch (
        CORBA::Object_ptr obj,
        CORBA::Object_out forward_obj,
        TAO::Argument ** args,
        int num_args,
        const char * op,
        size_t op_len,
        TAO::Collocation_Strategy strategy
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::Exception));

    static _TAO_IRObject_Strategized_Proxy_Broker *
    the_TAO_IRObject_Strategized_Proxy_Broker (void);
  };

  //
  //            End Strategized Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////



  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87

  class Contained;
  typedef Contained *Contained_ptr;

  class _TAO_Contained_Strategized_Proxy_Broker;

  class TAO_IFR_Client_Export Contained
    : public virtual POA_CORBA::IRObject
  {
  protected:
    Contained (void);

  public:
    // Useful for template programming.
    typedef ::CORBA::Contained _stub_type;
    typedef ::CORBA::Contained_ptr _stub_ptr_type;
    typedef ::CORBA::Contained_var _stub_var_type;

    Contained (const Contained& rhs);
    virtual ~Contained (void);

    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall
        ACE_ENV_ARG_DECL
      );

    ::CORBA::Contained *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual char * id (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_id_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual void id (
        const char * id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _set_id_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual char * name (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_name_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual void name (
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _set_name_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual char * version (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_version_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual void version (
        const char * version
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _set_version_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::Container_ptr defined_in (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_defined_in_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual char * absolute_name (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_absolute_name_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::Repository_ptr containing_repository (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_containing_repository_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::Contained::Description * describe (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void describe_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual void move (
        ::CORBA::Container_ptr new_container,
        const char * new_name,
        const char * new_version
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void move_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void
    _get_def_kind_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    // TAO_IDL - Generated from
    // be\be_interface.cpp:1939

    static void
    destroy_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
  };

  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration
  //

  // TAO_IDL - Generated from
  // be\be_visitor_interface/strategized_proxy_broker_sh.cpp:36

  class TAO_IFR_Client_Export _TAO_Contained_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public:
    _TAO_Contained_Strategized_Proxy_Broker (void);

    virtual ~_TAO_Contained_Strategized_Proxy_Broker (void);

    TAO::Collocation_Strategy
    get_strategy (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::SystemException));

    void
    dispatch (
        CORBA::Object_ptr obj,
        CORBA::Object_out forward_obj,
        TAO::Argument ** args,
        int num_args,
        const char * op,
        size_t op_len,
        TAO::Collocation_Strategy strategy
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::Exception));

    static _TAO_Contained_Strategized_Proxy_Broker *
    the_TAO_Contained_Strategized_Proxy_Broker (void);
  };

  //
  //            End Strategized Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////



  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87

  class Container;
  typedef Container *Container_ptr;

  class _TAO_Container_Strategized_Proxy_Broker;

  class TAO_IFR_Client_Export Container
    : public virtual POA_CORBA::IRObject
  {
  protected:
    Container (void);

  public:
    // Useful for template programming.
    typedef ::CORBA::Container _stub_type;
    typedef ::CORBA::Container_ptr _stub_ptr_type;
    typedef ::CORBA::Container_var _stub_var_type;

    Container (const Container& rhs);
    virtual ~Container (void);

    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall
        ACE_ENV_ARG_DECL
      );

    ::CORBA::Container *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::Contained_ptr lookup (
        const char * search_name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void lookup_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::ContainedSeq * contents (
        ::CORBA::DefinitionKind limit_type,
        ::CORBA::Boolean exclude_inherited
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void contents_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::ContainedSeq * lookup_name (
        const char * search_name,
        ::CORBA::Long levels_to_search,
        ::CORBA::DefinitionKind limit_type,
        ::CORBA::Boolean exclude_inherited
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void lookup_name_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::Container::DescriptionSeq * describe_contents (
        ::CORBA::DefinitionKind limit_type,
        ::CORBA::Boolean exclude_inherited,
        ::CORBA::Long max_returned_objs
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void describe_contents_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::ModuleDef_ptr create_module (
        const char * id,
        const char * name,
        const char * version
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_module_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::ConstantDef_ptr create_constant (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::IDLType_ptr type,
        const ::CORBA::Any & value
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_constant_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::StructDef_ptr create_struct (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::StructMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_struct_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::UnionDef_ptr create_union (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::IDLType_ptr discriminator_type,
        const ::CORBA::UnionMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_union_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::EnumDef_ptr create_enum (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::EnumMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_enum_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::AliasDef_ptr create_alias (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::IDLType_ptr original_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_alias_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::InterfaceDef_ptr create_interface (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::InterfaceDefSeq & base_interfaces
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_interface_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::ValueDef_ptr create_value (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::Boolean is_custom,
        ::CORBA::Boolean is_abstract,
        ::CORBA::ValueDef_ptr base_value,
        ::CORBA::Boolean is_truncatable,
        const ::CORBA::ValueDefSeq & abstract_base_values,
        const ::CORBA::InterfaceDefSeq & supported_interfaces,
        const ::CORBA::InitializerSeq & initializers
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_value_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::ValueBoxDef_ptr create_value_box (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::IDLType_ptr original_type_def
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_value_box_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::ExceptionDef_ptr create_exception (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::StructMemberSeq & members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_exception_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::NativeDef_ptr create_native (
        const char * id,
        const char * name,
        const char * version
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_native_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::AbstractInterfaceDef_ptr create_abstract_interface (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::AbstractInterfaceDefSeq & base_interfaces
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_abstract_interface_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::LocalInterfaceDef_ptr create_local_interface (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::InterfaceDefSeq & base_interfaces
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_local_interface_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::ExtValueDef_ptr create_ext_value (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::Boolean is_custom,
        ::CORBA::Boolean is_abstract,
        ::CORBA::ValueDef_ptr base_value,
        ::CORBA::Boolean is_truncatable,
        const ::CORBA::ValueDefSeq & abstract_base_values,
        const ::CORBA::InterfaceDefSeq & supported_interfaces,
        const ::CORBA::ExtInitializerSeq & initializers
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void create_ext_value_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void
    _get_def_kind_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    // TAO_IDL - Generated from
    // be\be_interface.cpp:1939

    static void
    destroy_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
  };

  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration
  //

  // TAO_IDL - Generated from
  // be\be_visitor_interface/strategized_proxy_broker_sh.cpp:36

  class TAO_IFR_Client_Export _TAO_Container_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public:
    _TAO_Container_Strategized_Proxy_Broker (void);

    virtual ~_TAO_Container_Strategized_Proxy_Broker (void);

    TAO::Collocation_Strategy
    get_strategy (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::SystemException));

    void
    dispatch (
        CORBA::Object_ptr obj,
        CORBA::Object_out forward_obj,
        TAO::Argument ** args,
        int num_args,
        const char * op,
        size_t op_len,
        TAO::Collocation_Strategy strategy
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::Exception));

    static _TAO_Container_Strategized_Proxy_Broker *
    the_TAO_Container_Strategized_Proxy_Broker (void);
  };

  //
  //            End Strategized Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////



  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87

  class IDLType;
  typedef IDLType *IDLType_ptr;

  class _TAO_IDLType_Strategized_Proxy_Broker;

  class TAO_IFR_Client_Export IDLType
    : public virtual POA_CORBA::IRObject
  {
  protected:
    IDLType (void);

  public:
    // Useful for template programming.
    typedef ::CORBA::IDLType _stub_type;
    typedef ::CORBA::IDLType_ptr _stub_ptr_type;
    typedef ::CORBA::IDLType_var _stub_var_type;

    IDLType (const IDLType& rhs);
    virtual ~IDLType (void);

    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall
        ACE_ENV_ARG_DECL
      );

    ::CORBA::IDLType *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual CORBA::TypeCode_ptr type (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_type_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void
    _get_def_kind_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    // TAO_IDL - Generated from
    // be\be_interface.cpp:1939

    static void
    destroy_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
  };

  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration
  //

  // TAO_IDL - Generated from
  // be\be_visitor_interface/strategized_proxy_broker_sh.cpp:36

  class TAO_IFR_Client_Export _TAO_IDLType_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public:
    _TAO_IDLType_Strategized_Proxy_Broker (void);

    virtual ~_TAO_IDLType_Strategized_Proxy_Broker (void);

    TAO::Collocation_Strategy
    get_strategy (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::SystemException));

    void
    dispatch (
        CORBA::Object_ptr obj,
        CORBA::Object_out forward_obj,
        TAO::Argument ** args,
        int num_args,
        const char * op,
        size_t op_len,
        TAO::Collocation_Strategy strategy
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::Exception));

    static _TAO_IDLType_Strategized_Proxy_Broker *
    the_TAO_IDLType_Strategized_Proxy_Broker (void);
  };

  //
  //            End Strategized Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////



  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87

  class TypedefDef;
  typedef TypedefDef *TypedefDef_ptr;

  class _TAO_TypedefDef_Strategized_Proxy_Broker;

  class TAO_IFR_Client_Export TypedefDef
    : public virtual POA_CORBA::Contained,
      public virtual POA_CORBA::IDLType
  {
  protected:
    TypedefDef (void);

  public:
    // Useful for template programming.
    typedef ::CORBA::TypedefDef _stub_type;
    typedef ::CORBA::TypedefDef_ptr _stub_ptr_type;
    typedef ::CORBA::TypedefDef_var _stub_var_type;

    TypedefDef (const TypedefDef& rhs);
    virtual ~TypedefDef (void);

    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );

    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall
        ACE_ENV_ARG_DECL
      );

    ::CORBA::TypedefDef *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;

    static void
    _get_def_kind_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    // TAO_IDL - Generated from
    // be\be_interface.cpp:1939

    static void
    destroy_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _get_id_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _set_id_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _get_name_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _set_name_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _get_version_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _set_version_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _get_defined_in_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _get_absolute_name_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _get_containing_repository_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    // TAO_IDL - Generated from
    // be\be_interface.cpp:1939

    static void
    describe_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    // TAO_IDL - Generated from
    // be\be_interface.cpp:1939

    static void
    move_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static void
    _get_type_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
  };

  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration
  //

  // TAO_IDL - Generated from
  // be\be_visitor_interface/strategized_proxy_broker_sh.cpp:36

  class TAO_IFR_Client_Export _TAO_TypedefDef_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public:
    _TAO_TypedefDef_Strategized_Proxy_Broker (void);

    virtual ~_TAO_TypedefDef_Strategized_Proxy_Broker (void);

    TAO::Collocation_Strategy
    get_strategy (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::SystemException));

    void
    dispatch (
        CORBA::Object_ptr obj,
        CORBA::Object_out forward_obj,
        TAO::Argument ** args,
        int num_args,
        const char * op,
        size_t op_len,
        TAO::Collocation_Strategy strategy
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::Exception));

    static _TAO_TypedefDef_Strategized_Proxy_Broker *
    the_TAO_TypedefDef_Strategized_Proxy_Broker (void);
  };

  //
  //            End Strategized Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////



// TAO_IDL - Generated from
// be\be_visitor_module/module_sh.cpp:80

} // module CORBA

// TAO_IDL - Generated from
// be\be_codegen.cpp:997

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */

