/// \file sys/utime.h
/// \copyright (c) 2022 ywx9.com

#pragma once

#include "corecrt.h"

extern "C" {

#ifndef _CRT_NO_TIME_T
struct _utimbuf {
  time_t actime;  // access time
  time_t modtime; // modification time
};
#endif

struct __utimbuf32 {
  __time32_t actime;  // access time
  __time32_t modtime; // modification time
};

struct __utimbuf64 {
  __time64_t actime;  // access time
  __time64_t modtime; // modification time
};

#if defined(_CRT_INTERNAL_NONSTDC_NAMES) && _CRT_INTERNAL_NONSTDC_NAMES && !defined _CRT_NO_TIME_T

struct utimbuf {
  time_t actime;  // access time
  time_t modtime; // modification time
};

struct utimbuf32 {
  __time32_t actime;  // access time
  __time32_t modtime; // modification time
};

#endif

_ACRTIMP int __cdecl _utime32(char const* _FileName, __utimbuf32* _Time);
_ACRTIMP int __cdecl _futime32(int _FileHandle, __utimbuf32* _Time);
_ACRTIMP int __cdecl _wutime32(wchar_t const* _FileName, __utimbuf32* _Time);
_ACRTIMP int __cdecl _utime64(char const* _FileName, __utimbuf64* _Time);
_ACRTIMP int __cdecl _futime64(int _FileHandle, __utimbuf64* _Time);
_ACRTIMP int __cdecl _wutime64(wchar_t const* _FileName, __utimbuf64* _Time);

#if !defined RC_INVOKED && !defined __midl && !defined _CRT_NO_TIME_T
#ifdef _USE_32BIT_TIME_T

static __inline int __CRTDECL _utime(char const* const _FileName, struct _utimbuf* const _Time) {
  _STATIC_ASSERT(sizeof(struct _utimbuf) == sizeof(struct __utimbuf32));
  return _utime32(_FileName, (struct __utimbuf32*)_Time);
}

static __inline int __CRTDECL _futime(int const _FileHandle, struct _utimbuf* const _Time) {
  _STATIC_ASSERT(sizeof(struct _utimbuf) == sizeof(struct __utimbuf32));
  return _futime32(_FileHandle, (struct __utimbuf32*)_Time);
}

static __inline int __CRTDECL _wutime(wchar_t const* const _FileName, struct _utimbuf* const _Time) {
  _STATIC_ASSERT(sizeof(struct _utimbuf) == sizeof(struct __utimbuf32));
  return _wutime32(_FileName, (struct __utimbuf32*)_Time);
}

#else
static __inline int __CRTDECL _utime(char const* const _FileName, struct _utimbuf* const _Time) {
  _STATIC_ASSERT(sizeof(struct _utimbuf) == sizeof(struct __utimbuf64));
  return _utime64(_FileName, (struct __utimbuf64*)_Time);
}

static __inline int __CRTDECL _futime(int const _FileHandle, struct _utimbuf* const _Time) {
  _STATIC_ASSERT(sizeof(struct _utimbuf) == sizeof(struct __utimbuf64));
  return _futime64(_FileHandle, (struct __utimbuf64*)_Time);
}

static __inline int __CRTDECL _wutime(wchar_t const* const _FileName, struct _utimbuf* const _Time) {
  _STATIC_ASSERT(sizeof(struct _utimbuf) == sizeof(struct __utimbuf64));
  return _wutime64(_FileName, (struct __utimbuf64*)_Time);
}

#endif

#if defined(_CRT_INTERNAL_NONSTDC_NAMES) && _CRT_INTERNAL_NONSTDC_NAMES
#ifdef _USE_32BIT_TIME_T

static __inline int __CRTDECL utime(char const* const _FileName, struct utimbuf* const _Time) {
  _STATIC_ASSERT(sizeof(struct utimbuf) == sizeof(struct __utimbuf32));
  return _utime32(_FileName, (struct __utimbuf32*)_Time);
}

#else

static __inline int __CRTDECL utime(char const* const _FileName, struct utimbuf* const _Time) {
  _STATIC_ASSERT(sizeof(struct utimbuf) == sizeof(struct __utimbuf64));
  return _utime64(_FileName, (struct __utimbuf64*)_Time);
}

#endif
#endif
#endif

}
