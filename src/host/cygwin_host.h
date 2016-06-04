#include <sys/cygwin.h>
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

#if CYGWIN_VERSION_DLL_MAJOR >= 1007
#define HAS_LOCALES	1
#else
#define HAS_LOCALES	0
#endif

#if CYGWIN_VERSION_API_MINOR >= 93
#define HAS_PTY 1
#else
#define HAS_PTY 0
#endif

#if CYGWIN_VERSION_API_MINOR >= 222
#define HAS_CW_INT_SETLOCALE	1
#else
#define HAS_CW_INT_SETLOCALE	0
#endif

#if CYGWIN_VERSION_DLL_MAJOR == 1005
#define NEEDS_WINDOWS_VER	1
#else
#define NEEDS_WINDOWS_VER	0
#endif

#if CYGWIN_VERSION_DLL_MAJOR >= 1005
#define HAS_MESSAGE_SLEEP_BUG	0
#define HAS_PROC		1
#define HAS_PROC_SELF_EXE	1
#define HAS_FOUR_BYTES_PTY	0
#define HAS_FIND_USER_DIRECTORY	1
#else
#define HAS_MESSAGE_SLEEP_BUG	1
#define HAS_PROC		0
#define HAS_PROC_SELF_EXE	0
#define HAS_FOUR_BYTES_PTY	1
#define HAS_FIND_USER_DIRECTORY	0
#endif

#if CYGWIN_VERSION_DLL_MAJOR >= 1007
#define HAS_LONG_PATHS		1
#define NEEDS_EXPLICIT_WINCON_H	0
#define HAS_CONSOLE_HACK	0
#else
#define HAS_LONG_PATHS		0
#define NEEDS_EXPLICIT_WINCON_H	1
#define HAS_CONSOLE_HACK	1
#endif
