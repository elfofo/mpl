//-----------------------------------------------------------------------------
// boost mpl/aux_/full_lambda.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2001-02
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#if !defined(BOOST_PP_IS_ITERATING)

///// header body

#ifndef BOOST_MPL_AUX_FULL_LAMBDA_HPP_INCLUDED
#define BOOST_MPL_AUX_FULL_LAMBDA_HPP_INCLUDED

#if !defined(BOOST_MPL_PREPROCESSING_MODE)
#   include "boost/mpl/lambda_fwd.hpp"
#   include "boost/mpl/bind.hpp"
#   include "boost/mpl/protect.hpp"
#   include "boost/mpl/meta_fun.hpp"
#   include "boost/mpl/bool_c.hpp"
#   include "boost/mpl/aux_/arity.hpp"
#   include "boost/mpl/aux_/template_arity.hpp"
#   include "boost/mpl/aux_/config/dtp.hpp"
#   include "boost/mpl/aux_/config/ttp.hpp"
#endif

#include "boost/mpl/aux_/lambda_expr.hpp"
#include "boost/mpl/aux_/config/use_preprocessed.hpp"

#if defined(BOOST_MPL_USE_PREPROCESSED_HEADERS) && \
    !defined(BOOST_MPL_PREPROCESSING_MODE)

#   define BOOST_MPL_PREPROCESSED_HEADER full_lambda.hpp
#   include "boost/mpl/aux_/include_preprocessed.hpp"

#else

#   include "boost/mpl/limits/arity.hpp"
#   include "boost/mpl/aux_/preprocessor/default_params.hpp"
#   include "boost/mpl/aux_/preprocessor/params.hpp"
#   include "boost/mpl/aux_/preprocessor/enum.hpp"
#   include "boost/mpl/aux_/preprocessor/repeat.hpp"

#   include "boost/preprocessor/iterate.hpp"
#   include "boost/preprocessor/comma_if.hpp"
#   include "boost/preprocessor/inc.hpp"
#   include "boost/preprocessor/cat.hpp"

namespace boost {
namespace mpl {

// local macros, #undef-ined at the end of the header
#   define AUX_LAMBDA_PARAMS(i, param) \
    BOOST_MPL_PP_PARAMS(i, param) \
    /**/

#   define AUX_LAMBDA_BIND_PARAMS(param) \
    BOOST_MPL_PP_PARAMS( \
          BOOST_MPL_METAFUNCTION_MAX_ARITY \
        , param \
        ) \
    /**/

#   define AUX_LAMBDA_BIND_N_PARAMS(i, param) \
    BOOST_PP_COMMA_IF(i) \
    BOOST_MPL_PP_PARAMS(i, param) \
    /**/

#if !defined(BOOST_EXTENDED_TEMPLATE_PARAMETERS_MATCHING)

template< typename T >
struct lambda
{
    BOOST_MPL_AUX_IS_LAMBDA_EXPR(false_c)
    typedef T type;
};

#else

template< long Arity, typename T >
struct lambda_impl
{
    BOOST_MPL_AUX_IS_LAMBDA_EXPR(false_c)
    typedef T type;
};

template< typename T >
struct lambda
    : lambda_impl< aux::template_arity<T>::value, T >
{
};

#endif // BOOST_EXTENDED_TEMPLATE_PARAMETERS_MATCHING


#if !defined(BOOST_MPL_NO_LAMBDA_HEURISTIC)

#define n BOOST_MPL_METAFUNCTION_MAX_ARITY
namespace aux {

template<
      BOOST_MPL_PP_DEFAULT_PARAMS(n,bool C,false)
    >
struct lambda_or
    : true_c
{
};

template<>
struct lambda_or< BOOST_MPL_PP_ENUM(n,false) >
    : false_c
{
};

} // namespace aux
#undef n

template< int N >
struct lambda< arg<N> >
{
    BOOST_MPL_AUX_IS_LAMBDA_EXPR(true_c)
    typedef arg<N> type;
};

#endif // BOOST_MPL_NO_LAMBDA_HEURISTIC

#define BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, BOOST_MPL_METAFUNCTION_MAX_ARITY, "boost/mpl/aux_/full_lambda.hpp"))
#include BOOST_PP_ITERATE()

//: special case for 'protect'
template< typename T >
struct lambda< protect<T> >
{
    BOOST_MPL_AUX_IS_LAMBDA_EXPR(false_c)
    typedef protect<T> type;
};

//: specializations for main 'bind', 'bind1st' and 'bind2nd' forms
template<
      typename F, AUX_LAMBDA_BIND_PARAMS(typename T)
    >
struct lambda< bind<F, AUX_LAMBDA_BIND_PARAMS(T)> >
{
    BOOST_MPL_AUX_IS_LAMBDA_EXPR(false_c)
    typedef bind<F, AUX_LAMBDA_BIND_PARAMS(T)> type;
};

template<
      typename F
    , typename T
    >
struct lambda< bind1st<F,T> >
{
    BOOST_MPL_AUX_IS_LAMBDA_EXPR(false_c)
    typedef bind1st<F,T> type;
};

template<
      typename F
    , typename T
    >
struct lambda< bind2nd<F,T> >
{
    BOOST_MPL_AUX_IS_LAMBDA_EXPR(false_c)
    typedef bind2nd<F,T> type;
};

#if defined(BOOST_NO_DEFAULT_TEMPLATE_PARAMETERS_IN_NESTED_TEMPLATES)
namespace aux {
template< typename T, int N > 
struct arity< lambda<T>, N >
{
    BOOST_STATIC_CONSTANT(int
        , value = BOOST_MPL_METAFUNCTION_MAX_ARITY
        );
};
}
#endif

#   undef AUX_LAMBDA_BIND_N_PARAMS
#   undef AUX_LAMBDA_BIND_PARAMS
#   undef AUX_LAMBDA_PARAMS

} // namespace mpl
} // namespace boost

#endif // BOOST_MPL_USE_PREPROCESSED_HEADERS
#endif // BOOST_MPL_AUX_FULL_LAMBDA_HPP_INCLUDED

///// iteration, depth == 1

#elif BOOST_PP_ITERATION_DEPTH() == 1
#define i BOOST_PP_FRAME_ITERATION(1)

#if i > 0
#if defined(BOOST_MPL_NO_LAMBDA_HEURISTIC)

#if !defined(BOOST_EXTENDED_TEMPLATE_PARAMETERS_MATCHING)
#   define BOOST_PP_ITERATION_PARAMS_2 \
    (3,(0, 0, "boost/mpl/aux_/full_lambda.hpp"))
#else
#   define BOOST_PP_ITERATION_PARAMS_2 \
    (3,(0, 1, "boost/mpl/aux_/full_lambda.hpp"))
#endif

#include BOOST_PP_ITERATE()

#else // BOOST_MPL_NO_LAMBDA_HEURISTIC

#   define AUX_LAMBDA_RESULT(i, T) \
    BOOST_PP_COMMA_IF(i) \
    typename BOOST_PP_CAT(T, BOOST_PP_INC(i))::type \
    /**/

namespace aux {

template<
      bool
    , template< AUX_LAMBDA_PARAMS(i, typename P) > class F
    , AUX_LAMBDA_PARAMS(i, typename L)
    >
struct BOOST_PP_CAT(le_result,i)
{
    typedef F<
          BOOST_MPL_PP_REPEAT(i, AUX_LAMBDA_RESULT, L)
        > type;
};

template<
      template< AUX_LAMBDA_PARAMS(i, typename P) > class F
    , AUX_LAMBDA_PARAMS(i, typename L)
    >
struct BOOST_PP_CAT(le_result,i)<true, F, AUX_LAMBDA_PARAMS(i, L) >
{
    typedef BOOST_PP_CAT(bind,i)<
          BOOST_PP_CAT(meta_fun,i)<F>
        , BOOST_MPL_PP_REPEAT(i, AUX_LAMBDA_RESULT, L)
        > type;
};

} // namespace aux

#   define AUX_LAMBDA_INVOCATION(i, T) \
    typedef lambda< BOOST_PP_CAT(T, BOOST_PP_INC(i)) > \
        BOOST_PP_CAT(l,BOOST_PP_INC(i)); \
    /**/

#   define AUX_IS_LAMBDA_EXPR(i, unused) \
    BOOST_PP_COMMA_IF(i) \
    BOOST_PP_CAT(l,BOOST_PP_INC(i))::is_le::value \
    /**/

#if !defined(BOOST_EXTENDED_TEMPLATE_PARAMETERS_MATCHING)
#   define BOOST_PP_ITERATION_PARAMS_2 \
    (3,(0, 0, "boost/mpl/aux_/full_lambda.hpp"))
#else
#   define BOOST_PP_ITERATION_PARAMS_2 \
    (3,(0, 1, "boost/mpl/aux_/full_lambda.hpp"))
#endif

#include BOOST_PP_ITERATE()

#   undef AUX_IS_LAMBDA_EXPR
#   undef AUX_LAMBDA_INVOCATION
#   undef AUX_LAMBDA_RESULT

#endif // BOOST_MPL_NO_LAMBDA_HEURISTIC
#endif // i > 0

template<
      typename F AUX_LAMBDA_BIND_N_PARAMS(i, typename T)
    >
struct lambda<
      BOOST_PP_CAT(bind,i)<F AUX_LAMBDA_BIND_N_PARAMS(i, T)>
    >
{
    BOOST_MPL_AUX_IS_LAMBDA_EXPR(false_c)
    typedef BOOST_PP_CAT(bind,i)<
          F
        AUX_LAMBDA_BIND_N_PARAMS(i, T)
        > type;
};

#undef i

///// iteration, depth == 2

#elif BOOST_PP_ITERATION_DEPTH() == 2

#if defined(BOOST_MPL_NO_LAMBDA_HEURISTIC)

template<
      template< AUX_LAMBDA_PARAMS(i, typename P) > class F
    , AUX_LAMBDA_PARAMS(i, typename T)
    >
#if !defined(BOOST_EXTENDED_TEMPLATE_PARAMETERS_MATCHING)
struct lambda< F<AUX_LAMBDA_PARAMS(i, T)> >
#else
#if BOOST_PP_FRAME_ITERATION(2) > 0
struct lambda_impl< i, F<AUX_LAMBDA_PARAMS(i, T)> >
#else
struct lambda_impl< -1, F<AUX_LAMBDA_PARAMS(i, T)> >
#endif
#endif
{
#   define AUX_LAMBDA_INVOCATION(i, T) \
    BOOST_PP_COMMA_IF(i) \
    typename lambda< BOOST_PP_CAT(T, BOOST_PP_INC(i)) >::type \
    /**/

    typedef BOOST_PP_CAT(bind,i)<
          BOOST_PP_CAT(meta_fun,i)<F>
        , BOOST_MPL_PP_REPEAT(i, AUX_LAMBDA_INVOCATION, T)
        > type;

#   undef AUX_LAMBDA_INVOCATION
};

#else

template<
      template< AUX_LAMBDA_PARAMS(i, typename P) > class F
    , AUX_LAMBDA_PARAMS(i, typename T)
    >
#if !defined(BOOST_EXTENDED_TEMPLATE_PARAMETERS_MATCHING)
struct lambda< F<AUX_LAMBDA_PARAMS(i, T)> >
#else
#if BOOST_PP_FRAME_ITERATION(2) > 0
struct lambda_impl< i, F<AUX_LAMBDA_PARAMS(i, T)> >
#else
struct lambda_impl< -1, F<AUX_LAMBDA_PARAMS(i, T)> >
#endif
#endif
{
    BOOST_MPL_PP_REPEAT(i, AUX_LAMBDA_INVOCATION, T)
    typedef aux::lambda_or<
          BOOST_MPL_PP_REPEAT(i, AUX_IS_LAMBDA_EXPR, unused)
        > is_le;

    typedef typename aux::BOOST_PP_CAT(le_result,i)<
          is_le::value
        , F
        , AUX_LAMBDA_PARAMS(i, l)
        >::type type;
};

#endif // BOOST_MPL_NO_LAMBDA_HEURISTIC

#endif // BOOST_PP_IS_ITERATING
