#ifndef __math_compat_h
#define __math_compat_h

/* Define isnan and isinf on Windows/MSVC */

#include "config.h"

#ifndef HAVE_DECL_ISNAN
#ifdef HAVE_DECL__ISNAN
#include <float.h>
#define isnan(x) _isnan(x)
#endif
#endif

#ifndef HAVE_DECL_ISINF
# ifdef HAVE_DECL__FINITE
#include <float.h>
#define isinf(x) (!_finite(x) && !_isnan(x))
# endif
#endif

#ifdef HAVE_ENDIAN_H
# include <endian.h>    /* attempt to define endianness */
#else
#define __LITTLE_ENDIAN__ 1 //assume x86
#endif


#if defined(__BIG_ENDIAN__)

typedef union {
       struct {
        unsigned long hi;
        unsigned long lo;
    } i;
       double            d;
} hexdouble;

#define HEXDOUBLE(hi, lo) { { hi, lo } }

#elif defined(__LITTLE_ENDIAN__)

typedef union {
       struct {
        unsigned long lo;
        unsigned long hi;
    } i;
       double            d;
} hexdouble;

#define HEXDOUBLE(hi, lo) { { lo, hi } }

#else
#error Unknown endianness
#endif


#ifndef HAVE_DECL_NAN
//#error This platform does Bnot have nan()
#ifdef _MSC_VER 
    #ifndef NAN
        //static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
        //#define NAN (*(const float *) __nan)
        static const hexdouble __nan = HEXDOUBLE(0x7fffffff, 0xffffffff);
        #define NAN __nan.d
    #endif
#else
#ifndef NAN
#define NAN nan("")
#endif /* !NAN */
#endif

#endif

//TODO: endianness
#ifndef HAVE_DECL_INFINITY
//#error This platform does not have INFINITY
static const unsigned long __plus_infinity[2] = {0x00000000, 0x7ff00000};
static const hexdouble __plus_infinity_d = HEXDOUBLE(0x7ff00000, 0x00000000);
#define INFINITY1 (*(const double *) __plus_infinity)
#define INFINITY __plus_infinity_d.d
#endif

/* Use C99 NAN by default; if not available, nan("") should work too. */


#endif

