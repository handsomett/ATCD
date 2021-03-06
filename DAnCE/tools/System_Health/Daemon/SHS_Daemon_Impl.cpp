// -*- C++ -*-
// TAO_IDL - Generated from
// be/be_codegen.cpp:1756

#include "SHS_Daemon_Impl.h"

#include "dance/Logger/Log_Macros.h"

#include <sstream>

namespace DAnCE
{
  // Implementation skeleton constructor
  SHS_Daemon_i::SHS_Daemon_i (CORBA::ORB_ptr orb)
    : orb_ (CORBA::ORB::_duplicate (orb))
  {
    DANCE_TRACE ("SHS_Daemon_i::constructor");
  }

  // Implementation skeleton destructor
  SHS_Daemon_i::~SHS_Daemon_i (void)
  {
    DANCE_TRACE ("SHS_Daemon_i::destructor");
  }

  void
  SHS_Daemon_i::update (const ::DAnCE::SHS::Status_Update & update)
  {
    DANCE_TRACE ("SHS_Daemon_i::update");

    DANCE_DEBUG (DANCE_LOG_EVENT_TRACE, (LM_DEBUG, DLINFO
                     ACE_TEXT ("SHS_Daemon_i::update - ")
                     ACE_TEXT ("Received status update from <%C>\n"),
                     update.id.in ()));

    std::stringstream str;

    str << "Instance with ID <" << update.id.in () << "> "
        << "and type <" << update.type.in () << ">: ";

    switch (update.new_status)
      {
      case ::DAnCE::SHS::INST_INSTALLED:
        str << "INSTALLED.";
        break;

      case ::DAnCE::SHS::INST_ACTIVE:
        str << "ACTIVE.";
        break;

      case ::DAnCE::SHS::INST_PASSIVE:
        str << "PASSIVE.";
        break;

      case ::DAnCE::SHS::INST_ERROR:
        str << "ERROR.";
        break;

      case ::DAnCE::SHS::INST_DEFUNCT:
        str << "DEFUNCT.";
        break;
      }

    std::cerr << str.str () << std::endl;
  }

  void SHS_Daemon_i::shutdown (void)
  {
    DANCE_TRACE ("SHS_Daemon_i::shutdown");

    this->orb_->shutdown ();
  }

}
