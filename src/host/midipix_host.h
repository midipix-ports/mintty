#include <stdint.h>
#include <stddef.h>
#include <wchar.h>

#define MAX_PATH	2048

#define CERASE		0177
#define	CNUL		0
#define	CDEL		0377
#define CTRL(x)		((x)&037)

#define O_BINARY	0

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

static inline int min(int a, int b)
{
	return (a < b) ? a : b;
}

static inline int max(int a, int b)
{
	return (a > b) ? a : b;
}

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

static inline char * path_win_w_to_posix(const wchar * wp)
{
	return host_create_path_utf16_to_posix(wp);
}

static inline wchar * path_posix_to_win_w(const char * p)
{
	return host_create_path_posix_to_utf16(p);
}

static inline char * path_posix_to_win_a(const char * p)
{
	return host_create_path_posix_to_ansi(p);
}

static inline void login(const void *ut)
{
}

static inline size_t host_wcslen(const uint16_t *s)
{
	return 0;
}

static inline int host_wcwidth(uint16_t wc)
{
	return wcwidth(wc);
}

static inline int host_wcswidth(const uint16_t *wcs, size_t n)
{
	return 0;
}

static inline int host_wcscmp(const uint16_t *ws1, const uint16_t *ws2)
{
	return 0;
}

static inline int host_wcsncmp(const uint16_t *ws1, const uint16_t *ws2, size_t n)
{
	return 0;
}

static inline uint16_t *host_wcscpy(uint16_t *ws1, const uint16_t *ws2)
{
	return 0;
}

static inline uint16_t *host_wcsdup(const uint16_t *string)
{
	return 0;
}

static inline uint32_t host_mbstowcs(uint16_t *pwcs, const char *s, size_t n)
{
	return 0;
}

static inline size_t host_mbrtowc(uint16_t *pwc, const char *s, size_t n, mbstate_t *ps)
{
	return 0;
}

static inline uint16_t * host_wcschr(const uint16_t *ws, uint16_t wc)
{
	return 0;
}

static inline uint16_t * host_wcsrchr(const uint16_t *ws, uint16_t wc)
{
	return 0;
}

static inline int host_conv_to_win32_path(
		const char *psx_path, char *win_path, size_t buflen)
{
	return 0;
}

static inline int host_mbstr_to_utf16(
		uint32_t cp, uint32_t flags,
		const char *mbstr, int mbbuflen,
		uint16_t *utf16str, int utf16buflen)
{
	return 0;
}

static inline int host_utf16_to_mbstr(
		uint32_t cp, uint32_t flags,
		const uint16_t *utf16str, int utf16buflen,
		char *mbstr, int mbbuflen,
		const char *defch, int * useddefch)
{
	return 0;
}

static inline int host_swprintf(uint16_t *wcs, size_t maxlen,
             const uint16_t *format, ...)
{
	return 0;
}
