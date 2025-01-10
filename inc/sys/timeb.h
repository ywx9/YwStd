/// \file sys/timeb.h
/// \copyright (c) 2022 ywx9.com

#pragma once

#include "corecrt.h"

extern "C" {

struct __timeb32 {
  __time32_t time;
  unsigned short millitm;
  short timezone;
  short dstflag;
};

struct __timeb64 {
  __time64_t time;
  unsigned short millitm;
  short timezone;
  short dstflag;
};

#if defined(_CRT_INTERNAL_NONSTDC_NAMES) && _CRT_INTERNAL_NONSTDC_NAMES && !defined _CRT_NO_TIME_T
struct timeb {
  time_t time;
  unsigned short millitm;
  short timezone;
  short dstflag;
};
#endif

#ifdef _USE_32BIT_TIME_T
#define _timeb __timeb32
#define _ftime _ftime32
#define _ftime_s _ftime32_s
#else
#define _timeb __timeb64
#define _ftime _ftime64
#define _ftime_s _ftime64_s
#endif

_CRT_INSECURE_DEPRECATE(_ftime32_s)
_ACRTIMP void __cdecl _ftime32(__timeb32* _Time);

_ACRTIMP errno_t __cdecl _ftime32_s(__timeb32* _Time);

_CRT_INSECURE_DEPRECATE(_ftime64_s)
_ACRTIMP void __cdecl _ftime64(__timeb64* _Time);

_ACRTIMP errno_t __cdecl _ftime64_s(__timeb64* _Time);

#if !defined RC_INVOKED && !defined __midl && defined(_CRT_INTERNAL_NONSTDC_NAMES) && _CRT_INTERNAL_NONSTDC_NAMES && \
  !defined _CRT_NO_TIME_T

#ifdef _USE_32BIT_TIME_T

static __inline void __CRTDECL ftime(struct timeb* const _Tmb) {
  _STATIC_ASSERT(sizeof(struct timeb) == sizeof(struct __timeb32));
  _ftime32((struct __timeb32*)_Tmb);
}

#else

static __inline void __CRTDECL ftime(struct timeb* const _Tmb) {
  _STATIC_ASSERT(sizeof(struct timeb) == sizeof(struct __timeb64));
  _ftime64((struct __timeb64*)_Tmb);
}

#endif

#endif

}
