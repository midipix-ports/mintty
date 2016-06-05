#include <stdint.h>
#include <stddef.h>

#define MAX_PATH	2048

#define	CNUL		0
#define	CDEL		0377
#define CTRL(x)		((x)&037)

#define HAS_ARGZ_H	0
#define HAS_WCTYPE_H	1
#define HAS_WCSDUP      1
#define HAS_STRLCPY	1
#define HAS_ASPRINTF	1
#define HAS_LOCALES	1
#define HAS_PTY		1

#define HAS_SYNC_WINENV		0
#define HAS_CW_CONV_PATH        0
#define HAS_CW_CREATE_PATH      0
#define HAS_MESSAGE_SLEEP_BUG	0
#define HAS_PROC		0
#define HAS_PROC_SELF_EXE	0
#define HAS_FOUR_BYTES_PTY	0
#define HAS_CONSOLE_HACK	0
#define HAS_FIND_USER_DIRECTORY	1
#define HAS_CREATE_PATH		1
#define HAS_LONG_PATHS		0
#define HAS_WSTRING		0
#define HAS_CW_INT_SETLOCALE	0
#define NEEDS_EXPLICIT_WINCON_H	0
#define NEEDS_WINDOWS_VER	0
#define NEEDS_WCS_TEST		0
#define HAS_PROPS_SYS_KEY	0
#define HAS_INVOKED_WITH_APPID	0
#define HAS_ICON_LOCATION	0
#define HAS_REAL_PASSWD_STRUCT	0
#define HAS_PW_SHELL		0
#define HAS_SUPPORTED_APPID	0

static inline char *host_create_path_posix_to_ansi(const char *from)
{
	return 0;
}

static inline uint16_t *host_create_path_posix_to_utf16(const char *from)
{
	return 0;
}

static inline char *host_create_path_utf16_to_posix(const uint16_t *from)
{
	return 0;
}

static inline void login(const void *ut)
{
}

static inline size_t host_wcslen(const uint16_t *s)
{
	return 0;
}

static inline int host_mbstr_to_utf16(
		uint32_t cp, uint32_t flags,
		char *mbstr, int mbbuflen,
		uint16_t *utf16str, int utf16buflen)
{
	return 0;
}
