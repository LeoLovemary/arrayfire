/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#pragma once

#ifdef __CUDACC_RTC__

#include <complex.hpp>
using dim_t = long long;

#else  //__CUDACC_RTC__

#include <cuComplex.h>
#include <af/traits.hpp>

namespace cuda {
#endif  //__CUDACC_RTC__

using cdouble = cuDoubleComplex;
using cfloat  = cuFloatComplex;
using intl    = long long;
using uchar   = unsigned char;
using uint    = unsigned int;
using uintl   = unsigned long long;
using ushort  = unsigned short;
using ulong   = unsigned long long;

#ifndef __CUDACC_RTC__
namespace {
template<typename T>
const char *shortname(bool caps = false) {
    return caps ? "Q" : "q";
}
template<>
const char *shortname<float>(bool caps) {
    return caps ? "S" : "s";
}
template<>
const char *shortname<double>(bool caps) {
    return caps ? "D" : "d";
}
template<>
const char *shortname<cfloat>(bool caps) {
    return caps ? "C" : "c";
}
template<>
const char *shortname<cdouble>(bool caps) {
    return caps ? "Z" : "z";
}
template<>
const char *shortname<int>(bool caps) {
    return caps ? "I" : "i";
}
template<>
const char *shortname<uint>(bool caps) {
    return caps ? "U" : "u";
}
template<>
const char *shortname<char>(bool caps) {
    return caps ? "J" : "j";
}
template<>
const char *shortname<uchar>(bool caps) {
    return caps ? "V" : "v";
}
template<>
const char *shortname<intl>(bool caps) {
    return caps ? "X" : "x";
}
template<>
const char *shortname<uintl>(bool caps) {
    return caps ? "Y" : "y";
}
template<>
const char *shortname<short>(bool caps) {
    return caps ? "P" : "p";
}
template<>
const char *shortname<ushort>(bool caps) {
    return caps ? "Q" : "q";
}

template<typename T>
const char *getFullName();

#define SPECIALIZE(T)              \
    template<>                     \
    const char *getFullName<T>() { \
        return #T;                 \
    }

SPECIALIZE(float)
SPECIALIZE(double)
SPECIALIZE(cfloat)
SPECIALIZE(cdouble)
SPECIALIZE(char)
SPECIALIZE(unsigned char)
SPECIALIZE(short)
SPECIALIZE(unsigned short)
SPECIALIZE(int)
SPECIALIZE(unsigned int)
SPECIALIZE(unsigned long long)
SPECIALIZE(long long)

#undef SPECIALIZE
}  // namespace
#endif  //__CUDACC_RTC__

#ifndef __CUDACC_RTC__
}  // namespace cuda
#endif  //__CUDACC_RTC__
