#include <sys/cygwin.h>
#include <cygwin/version.h>

#define HAS_SYNC_WINENV	1
#define HAS_CW_CONV_PATH         1

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
#define HAS_WSTRING		1
#define HAS_CW_INT_SETLOCALE	1
#else
#define HAS_WSTRING		0
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
#define HAS_INVOKED_WITH_APPID	1
#define HAS_ICON_LOCATION	1
#define HAS_REAL_PASSWD_STRUCT	1
#define HAS_PW_SHELL		1
#define need_wcschr		1
#else
#define HAS_MESSAGE_SLEEP_BUG	1
#define HAS_PROC		0
#define HAS_PROC_SELF_EXE	0
#define HAS_FOUR_BYTES_PTY	1
#define HAS_FIND_USER_DIRECTORY	0
#define HAS_INVOKED_WITH_APPID	0
#define HAS_ICON_LOCATION	0
#define HAS_REAL_PASSWD_STRUCT	0
#define HAS_PW_SHELL		0
#endif

#if CYGWIN_VERSION_DLL_MAJOR >= 1007
#define HAS_CREATE_PATH		1
#define HAS_LONG_PATHS		1
#define NEEDS_EXPLICIT_WINCON_H	0
#define HAS_CONSOLE_HACK	0
#define HAS_PROPS_SYS_KEY	1
#define HAS_SUPPORTED_APPID	1
#else
#define HAS_CREATE_PATH		0
#define HAS_LONG_PATHS		0
#define NEEDS_EXPLICIT_WINCON_H	1
#define HAS_CONSOLE_HACK	1
#define HAS_PROPS_SYS_KEY	0
#define HAS_SUPPORTED_APPID	0
#endif

#if ((CYGWIN_VERSION_API_MINOR < 74) || defined(TEST_WCS))
#define NEEDS_WCS_TEST		1
#else
#define NEEDS_WCS_TEST		0
#endif

#if CYGWIN_VERSION_API_MINOR >= 181
#define HAS_CW_CREATE_PATH      1
#define HAS_EXTRACT_ICON_UTF16	1
#else
#define HAS_CW_CREATE_PATH      0
#define HAS_EXTRACT_ICON_UTF16	0
#endif

#if CYGWIN_VERSION_API_MINOR >= 207
#define HAS_WCSDUP              1
#else
#define HAS_WCSDUP              0
#endif
