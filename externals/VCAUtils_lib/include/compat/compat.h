#ifndef COMPAT_H
#define COMPAT_H

#if defined(_WIN32)
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS // Disable deprecation warning in VS2005
#endif
#define _CRT_NONSTDC_NO_DEPRECATE
#else
#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600     // For flockfile() on Linux
#undef _LARGEFILE_SOURCE
#define _LARGEFILE_SOURCE     // Enable 64-bit file offsets
#define __STDC_FORMAT_MACROS  // <inttypes.h> wants this for C++
#define __STDC_LIMIT_MACROS   // C++ wants that for INT64_MAX
#endif
#include <cstddef> // NULL

#if defined(_WIN32)
#else
#include <unistd.h>
#endif

#if defined(_WIN32)
#include "wingetopt/wingetopt.h" // getopt port
#ifndef MIN
#  define MIN(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef MAX
#  define MAX(a,b) (((a)>(b))?(a):(b))
#endif
#else
#include <getopt.h> // symmetry to wingetopt
#include <sys/param.h> // MIN/MAX
#endif

#include <errno.h>
#endif /* COMPAT_H*/
