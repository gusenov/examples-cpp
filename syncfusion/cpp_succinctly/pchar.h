#pragma once

#if !defined(_PCHAR_H)
#define _PCHAR_H 1

#if defined(WIN32) && defined(UNICODE)
#define _pmain wmain
#define _pchar wchar_t
#else
#define _pmain main
#define _pchar char
#endif

#endif
