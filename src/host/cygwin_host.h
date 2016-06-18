#include <stdint.h>
#include <wchar.h>
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

#define host_wcwidth(x) \
	wcwidth(x)

static inline int host_wcswidth(uint16_t *wcs, size_t n)
{
	return wcswidth(wcs, n);
}

static inline uint16_t * host_wcschr(const uint16_t *ws, uint16_t wc)
{
	return wcschr(ws,wc);
}

static inline uint16_t * host_wcsrchr(const uint16_t *ws, uint16_t wc)
{
	return wcsrchr(ws,wc);
}

#define host_conv_to_win32_path(psx_path, win_path, buflen_ignored) \
	cygwin_conv_to_win32_path(psx_path, win_path)

#define host_mbstr_to_utf16(cp, flags, mbbuf, mbbuflen, utf16buf, utf16buflen) \
	MultiByteToWideChar(cp, flags, mbbuf, mbbuflen, utf16buf, utf16buflen)

#define host_utf16_to_mbstr(cp, flags, utf16buf, utf16buflen, mbbuf, mbbuflen, defch, useddefch) \
	WideCharToMultiByte(cp, flags, utf16buf, utf16buflen, mbbuf, mbbuflen, defch, useddefch)

static inline size_t host_wcslen(const uint16_t *s)
{
  return wcslen(s);
}

static inline int host_wcscmp(const uint16_t *ws1, const uint16_t *ws2)
{
  return wcscmp(ws1,ws2);
}

static inline int host_wcsncmp(const uint16_t *ws1, const uint16_t *ws2, size_t n)
{
  return wcsncmp(ws1, ws2, n);
}

static inline uint16_t *host_wcsdup(const uint16_t *string)
{
  return wcsdup(string);
}

static inline uint32_t host_mbstowcs(uint16_t *pwcs, const char *s, size_t n)
{
  return mbstowcs(pwcs,s,n);
}

static inline size_t host_mbrtowc(uint16_t *pwc, const char *s, size_t n, mbstate_t *ps)
{
  return mbrtowc(pwc,s,n,ps);
}

#if HAS_CREATE_PATH

static inline char *
host_create_path_posix_to_ansi(const char *from)
{
  return cygwin_create_path(CCP_POSIX_TO_WIN_A, from);
}

static inline uint16_t *
host_create_path_posix_to_utf16(const char *from)
{
  return cygwin_create_path(CCP_POSIX_TO_WIN_W, from);
}

static inline char *
host_create_path_utf16_to_posix(const uint16_t *from)
{
  return cygwin_create_path(CCP_WIN_W_TO_POSIX, from);
}

static inline char *
path_win_w_to_posix(const wchar * wp)
{
  return host_create_path_utf16_to_posix(wp);
}

static inline wchar *
path_posix_to_win_w(const char * p)
{
  return host_create_path_posix_to_utf16(p);
}

static inline char * path_posix_to_win_a(const char * p)
{
  return host_create_path_posix_to_ansi(p);
}

#else

#include <winbase.h>
#include <winnls.h>

static inline char *
path_win_w_to_posix(const wchar * wp)
{
  char * mp = cs__wcstombs(wp);
  char * p = newn(char, MAX_PATH);
  cygwin_conv_to_full_posix_path(mp, p);
  free(mp);
  p = renewn(p, strlen(p) + 1);
  return p;
}

static inline wchar *
path_posix_to_win_w(const char * p)
{
  char ap[MAX_PATH];
  host_conv_to_win32_path(p, ap);
  wchar * wp = newn(wchar, MAX_PATH);
  MultiByteToWideChar(0, 0, ap, -1, wp, MAX_PATH);
  wp = renewn(wp, wcslen(wp) + 1);
  return wp;
}

static inline char *
path_posix_to_win_a(const char * p)
{
  char * ap = newn(char, MAX_PATH);
  host_conv_to_win32_path(p, ap);
  ap = renewn(ap, strlen(ap) + 1);
  return ap;
}

#endif
