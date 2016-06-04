#include <cygwin/version.h>

#if CYGWIN_VERSION_API_MINOR >= 91
#define HAS_ARGZ_H	1
#else
#define HAS_ARGZ_H	0
#endif

#if CYGWIN_VERSION_API_MINOR >= 74
#define HAS_WCTYPE_H	1
#else
#define HAS_WCTYPE_H	0
#endif

#if CYGWIN_VERSION_API_MINOR < 53
#define HAS_STRLCPY	0
#else
#define HAS_STRLCPY	1
#endif

#if CYGWIN_VERSION_API_MINOR < 70
#define HAS_ASPRINTF	0
#else
#define HAS_ASPRINTF	1
#endif

