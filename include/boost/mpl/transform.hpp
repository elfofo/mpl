//-----------------------------------------------------------------------------
// boost mpl/transform.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2000-02
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#ifndef BOOST_MPL_TRANSFORM_HPP_INCLUDED
#define BOOST_MPL_TRANSFORM_HPP_INCLUDED

#include "boost/mpl/fold_backward.hpp"
#include "boost/mpl/push_front.hpp"
#include "boost/mpl/clear.hpp"
#include "boost/mpl/lambda.hpp"
#include "boost/mpl/apply.hpp"
#include "boost/mpl/protect.hpp"
#include "boost/mpl/aux_/common_name_wknd.hpp"
#include "boost/mpl/aux_/void_spec.hpp"

namespace boost {
namespace mpl {

BOOST_MPL_AUX_COMMON_NAME_WKND(transform)

namespace aux {

template< typename Op >
struct transform_op
{
    template< typename Sequence, typename T > struct apply
    {
        typedef typename push_front<
              Sequence
            , typename apply1<Op,T>::type
            >::type type;
    };
};

} // namespace aux

BOOST_MPL_AUX_AGLORITHM_NAMESPACE_BEGIN

template<
      typename BOOST_MPL_AUX_VOID_SPEC_PARAM(Sequence)
    , typename BOOST_MPL_AUX_VOID_SPEC_PARAM(Operation)
    >
struct transform
{
 private:
    typedef typename lambda<Operation>::type op_;
    typedef typename clear<Sequence>::type result_;

 public:
    typedef typename fold_backward<
          Sequence
        , result_
        , protect< aux::transform_op<op_> >
        >::type type;
};

BOOST_MPL_AUX_AGLORITHM_NAMESPACE_END

BOOST_MPL_AUX_ALGORITHM_VOID_SPEC(2, transform)

} // namespace mpl
} // namespace boost

#endif // BOOST_MPL_TRANSFORM_HPP_INCLUDED
