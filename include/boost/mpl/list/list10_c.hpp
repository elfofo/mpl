//-----------------------------------------------------------------------------
// boost mpl/list/list10_c.hpp header file
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

#ifndef BOOST_MPL_LIST_LIST10_C_HPP_INCLUDED
#define BOOST_MPL_LIST_LIST10_C_HPP_INCLUDED

#if !defined(BOOST_MPL_PREPROCESSING_MODE)
#   include "boost/mpl/list/list0_c.hpp"
#endif

#include "boost/mpl/aux_/config/use_preprocessed.hpp"

#if defined(BOOST_MPL_USE_PREPROCESSED_HEADERS) && \
    !defined(BOOST_MPL_PREPROCESSING_MODE)

#   define BOOST_MPL_PREPROCESSED_HEADER list10_c.hpp
#   include "boost/mpl/aux_/include_preprocessed.hpp"

#else

#   include "boost/preprocessor/iterate.hpp"

namespace boost {
namespace mpl {

#   define BOOST_PP_ITERATION_PARAMS_1 \
    (3,(1, 10, "boost/mpl/list/aux_/numbered_c.hpp"))
#   include BOOST_PP_ITERATE()

} // namespace mpl
} // namespace boost

#endif // BOOST_MPL_USE_PREPROCESSED_HEADERS

#endif // BOOST_MPL_LIST_LIST10_C_HPP_INCLUDED
