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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// C:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_FP_SCHEDULINGC_H_
#define _TAO_IDL_FP_SCHEDULINGC_H_

#include "ace/pre.h"

#include "tao/corba.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "c:/ACE_wrappers/TAO/tao/RTScheduling/RTSchedulerC.h"
#include "c:/ACE_wrappers/TAO/tao/RTCORBA/RTCORBAC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO 
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  FP_Scheduling
{
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:52

#if !defined (_FP_SCHEDULING_SEGMENTSCHEDULINGPARAMETERPOLICY___PTR_CH_)
#define _FP_SCHEDULING_SEGMENTSCHEDULINGPARAMETERPOLICY___PTR_CH_
  
  class SegmentSchedulingParameterPolicy;
  typedef SegmentSchedulingParameterPolicy *SegmentSchedulingParameterPolicy_ptr;

#endif /* end #if !defined */

#if !defined (_FP_SCHEDULING_SEGMENTSCHEDULINGPARAMETERPOLICY___VAR_CH_)
#define _FP_SCHEDULING_SEGMENTSCHEDULINGPARAMETERPOLICY___VAR_CH_
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:571
  
  class  SegmentSchedulingParameterPolicy_var : public TAO_Base_var
  {
  public:
    SegmentSchedulingParameterPolicy_var (void); // default constructor
    SegmentSchedulingParameterPolicy_var (SegmentSchedulingParameterPolicy_ptr p) : ptr_ (p) {} 
    SegmentSchedulingParameterPolicy_var (const SegmentSchedulingParameterPolicy_var &); // copy constructor
    ~SegmentSchedulingParameterPolicy_var (void); // destructor
    
    SegmentSchedulingParameterPolicy_var &operator= (SegmentSchedulingParameterPolicy_ptr);
    SegmentSchedulingParameterPolicy_var &operator= (const SegmentSchedulingParameterPolicy_var &);
    SegmentSchedulingParameterPolicy_ptr operator-> (void) const;
    
    operator const SegmentSchedulingParameterPolicy_ptr &() const;
    operator SegmentSchedulingParameterPolicy_ptr &();
    // in, inout, out, _retn 
    SegmentSchedulingParameterPolicy_ptr in (void) const;
    SegmentSchedulingParameterPolicy_ptr &inout (void);
    SegmentSchedulingParameterPolicy_ptr &out (void);
    SegmentSchedulingParameterPolicy_ptr _retn (void);
    SegmentSchedulingParameterPolicy_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static SegmentSchedulingParameterPolicy_ptr tao_duplicate (SegmentSchedulingParameterPolicy_ptr);
    static void tao_release (SegmentSchedulingParameterPolicy_ptr);
    static SegmentSchedulingParameterPolicy_ptr tao_nil (void);
    static SegmentSchedulingParameterPolicy_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    SegmentSchedulingParameterPolicy_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    SegmentSchedulingParameterPolicy_var (const TAO_Base_var &rhs);
    SegmentSchedulingParameterPolicy_var &operator= (const TAO_Base_var &rhs);
  };

#endif /* end #if !defined */

#if !defined (_FP_SCHEDULING_SEGMENTSCHEDULINGPARAMETERPOLICY___OUT_CH_)
#define _FP_SCHEDULING_SEGMENTSCHEDULINGPARAMETERPOLICY___OUT_CH_
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:946
  
  class  SegmentSchedulingParameterPolicy_out
  {
  public:
    SegmentSchedulingParameterPolicy_out (SegmentSchedulingParameterPolicy_ptr &);
    SegmentSchedulingParameterPolicy_out (SegmentSchedulingParameterPolicy_var &);
    SegmentSchedulingParameterPolicy_out (const SegmentSchedulingParameterPolicy_out &);
    SegmentSchedulingParameterPolicy_out &operator= (const SegmentSchedulingParameterPolicy_out &);
    SegmentSchedulingParameterPolicy_out &operator= (const SegmentSchedulingParameterPolicy_var &);
    SegmentSchedulingParameterPolicy_out &operator= (SegmentSchedulingParameterPolicy_ptr);
    operator SegmentSchedulingParameterPolicy_ptr &();
    SegmentSchedulingParameterPolicy_ptr &ptr (void);
    SegmentSchedulingParameterPolicy_ptr operator-> (void);
  
  private:
    SegmentSchedulingParameterPolicy_ptr &ptr_;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:110

#if !defined (_FP_SCHEDULING_SEGMENTSCHEDULINGPARAMETERPOLICY_CH_)
#define _FP_SCHEDULING_SEGMENTSCHEDULINGPARAMETERPOLICY_CH_
  
  class  SegmentSchedulingParameterPolicy
    : public virtual CORBA::Policy
  {
  public:
    typedef SegmentSchedulingParameterPolicy_ptr _ptr_type;
    typedef SegmentSchedulingParameterPolicy_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static SegmentSchedulingParameterPolicy_ptr _duplicate (SegmentSchedulingParameterPolicy_ptr obj);
    
    static SegmentSchedulingParameterPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static SegmentSchedulingParameterPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static SegmentSchedulingParameterPolicy_ptr _nil (void)
      {
        return (SegmentSchedulingParameterPolicy_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual RTCORBA::Priority value (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void value (
        RTCORBA::Priority value
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:267
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;
  
  protected:
    SegmentSchedulingParameterPolicy (void);
    virtual ~SegmentSchedulingParameterPolicy (void);
    
    friend class _TAO_SegmentSchedulingParameterPolicy_Remote_Proxy_Impl;
    friend class _TAO_SegmentSchedulingParameterPolicy_ThruPOA_Proxy_Impl;
    friend class _TAO_SegmentSchedulingParameterPolicy_Direct_Proxy_Impl;
  
  private:
    SegmentSchedulingParameterPolicy (const SegmentSchedulingParameterPolicy &);
    void operator= (const SegmentSchedulingParameterPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_SegmentSchedulingParameterPolicy;
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:52

#if !defined (_FP_SCHEDULING_FP_SCHEDULER___PTR_CH_)
#define _FP_SCHEDULING_FP_SCHEDULER___PTR_CH_
  
  class FP_Scheduler;
  typedef FP_Scheduler *FP_Scheduler_ptr;

#endif /* end #if !defined */

#if !defined (_FP_SCHEDULING_FP_SCHEDULER___VAR_CH_)
#define _FP_SCHEDULING_FP_SCHEDULER___VAR_CH_
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:571
  
  class  FP_Scheduler_var : public TAO_Base_var
  {
  public:
    FP_Scheduler_var (void); // default constructor
    FP_Scheduler_var (FP_Scheduler_ptr p) : ptr_ (p) {} 
    FP_Scheduler_var (const FP_Scheduler_var &); // copy constructor
    ~FP_Scheduler_var (void); // destructor
    
    FP_Scheduler_var &operator= (FP_Scheduler_ptr);
    FP_Scheduler_var &operator= (const FP_Scheduler_var &);
    FP_Scheduler_ptr operator-> (void) const;
    
    operator const FP_Scheduler_ptr &() const;
    operator FP_Scheduler_ptr &();
    // in, inout, out, _retn 
    FP_Scheduler_ptr in (void) const;
    FP_Scheduler_ptr &inout (void);
    FP_Scheduler_ptr &out (void);
    FP_Scheduler_ptr _retn (void);
    FP_Scheduler_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static FP_Scheduler_ptr tao_duplicate (FP_Scheduler_ptr);
    static void tao_release (FP_Scheduler_ptr);
    static FP_Scheduler_ptr tao_nil (void);
    static FP_Scheduler_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    FP_Scheduler_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    FP_Scheduler_var (const TAO_Base_var &rhs);
    FP_Scheduler_var &operator= (const TAO_Base_var &rhs);
  };

#endif /* end #if !defined */

#if !defined (_FP_SCHEDULING_FP_SCHEDULER___OUT_CH_)
#define _FP_SCHEDULING_FP_SCHEDULER___OUT_CH_
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:946
  
  class  FP_Scheduler_out
  {
  public:
    FP_Scheduler_out (FP_Scheduler_ptr &);
    FP_Scheduler_out (FP_Scheduler_var &);
    FP_Scheduler_out (const FP_Scheduler_out &);
    FP_Scheduler_out &operator= (const FP_Scheduler_out &);
    FP_Scheduler_out &operator= (const FP_Scheduler_var &);
    FP_Scheduler_out &operator= (FP_Scheduler_ptr);
    operator FP_Scheduler_ptr &();
    FP_Scheduler_ptr &ptr (void);
    FP_Scheduler_ptr operator-> (void);
  
  private:
    FP_Scheduler_ptr &ptr_;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:110

#if !defined (_FP_SCHEDULING_FP_SCHEDULER_CH_)
#define _FP_SCHEDULING_FP_SCHEDULER_CH_
  
  class  FP_Scheduler
    : public virtual RTScheduling::Scheduler
  {
  public:
    typedef FP_Scheduler_ptr _ptr_type;
    typedef FP_Scheduler_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static FP_Scheduler_ptr _duplicate (FP_Scheduler_ptr obj);
    
    static FP_Scheduler_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static FP_Scheduler_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static FP_Scheduler_ptr _nil (void)
      {
        return (FP_Scheduler_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::FP_Scheduling::SegmentSchedulingParameterPolicy_ptr create_segment_scheduling_parameter (
        RTCORBA::Priority segment_priority
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:267
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;
  
  protected:
    FP_Scheduler (void);
    virtual ~FP_Scheduler (void);
    
    friend class _TAO_FP_Scheduler_Remote_Proxy_Impl;
    friend class _TAO_FP_Scheduler_ThruPOA_Proxy_Impl;
    friend class _TAO_FP_Scheduler_Direct_Proxy_Impl;
  
  private:
    FP_Scheduler (const FP_Scheduler &);
    void operator= (const FP_Scheduler &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_FP_Scheduler;

// TAO_IDL - Generated from
// C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module FP_Scheduling

// TAO_IDL - Generated from
// C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

 void operator<<= (CORBA::Any &, FP_Scheduling::SegmentSchedulingParameterPolicy_ptr); // copying
 void operator<<= (CORBA::Any &, FP_Scheduling::SegmentSchedulingParameterPolicy_ptr *); // non-copying
 CORBA::Boolean operator>>= (const CORBA::Any &, FP_Scheduling::SegmentSchedulingParameterPolicy_ptr &);

// TAO_IDL - Generated from
// C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

 void operator<<= (CORBA::Any &, FP_Scheduling::FP_Scheduler_ptr); // copying
 void operator<<= (CORBA::Any &, FP_Scheduling::FP_Scheduler_ptr *); // non-copying
 CORBA::Boolean operator>>= (const CORBA::Any &, FP_Scheduling::FP_Scheduler_ptr &);

// TAO_IDL - Generated from
// C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// C:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// C:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1004

#if defined (__ACE_INLINE__)
#include "FP_SchedulingC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */

