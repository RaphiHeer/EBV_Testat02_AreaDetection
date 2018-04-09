#ifndef COMPAT_STRINGS_H
#define COMPAT_STRINGS_H

#include <compat/compat.h>

#include <cstring>
#include <cstdlib>
#include <cstdio> // for xxprintf

// not fully compatible, because return value is dest*, but usual ok
#define strncpy(dst, src, dst_size) (strncpy(dst, src, dst_size)[dst_size-1] = '\0')

char * strnstr(const char *s, const char *find, size_t slen);

#if defined(_WIN32)
#define snprintf fixed_snprintf
int fixed_snprintf(char *str,size_t size,const char *fmt,...);

#define __func__  __FUNCTION__
#define strtoull(x, y, z) _strtoui64(x, y, z)
#define strtoll(x, y, z) _strtoi64(x, y, z)

#define strcasecmp(str1, str2) _stricmp(str1, str2)
#define strncasecmp(str1, str2, n) _strnicmp(str1, str2, n)
#define strdup(str) _strdup(str)
#define stricmp(str1,str2) _stricmp(str1,str2)
#else
#endif

#include <cctype> // tolower, toupper

#endif /*COMPAT_STRINGS_H */

