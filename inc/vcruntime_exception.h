/// \file vcruntime_exception.h
//
// vcruntime_exception.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// <exception> functionality that is implemented in the VCRuntime.
//
#pragma once

#define _INC_EH

#include "corecrt_terminate.h"
#include "vadefs.h"

#if _VCRT_COMPILER_PREPROCESSOR

#pragma warning(push)
#pragma warning(disable : _VCRUNTIME_DISABLED_WARNINGS)

_CRT_BEGIN_C_HEADER

#if defined(_VCRT_BUILD) || !_HAS_CXX23 // C++98 unexpected() is incompatible with C++23 unexpected<E>.
// unexpected_handler is the standard name;
// unexpected_function is defined for source compatibility.
typedef void(__CRTDECL* unexpected_handler)(void);
typedef void(__CRTDECL* unexpected_function)(void);

#ifdef _M_CEE
typedef void(__clrcall* __unexpected_function_m)();
typedef void(__clrcall* __unexpected_handler_m)();
#endif // _M_CEE

#ifdef __cplusplus
_VCRTIMP __declspec(noreturn) void __cdecl unexpected() noexcept(false);

#ifndef _M_CEE_PURE
_VCRTIMP unexpected_handler __cdecl set_unexpected(_In_opt_ unexpected_handler _NewUnexpectedHandler) noexcept;
_VCRTIMP unexpected_handler __cdecl _get_unexpected() noexcept;
#endif // _M_CEE_PURE
#endif // __cplusplus
#endif // defined(_VCRT_BUILD) || !_HAS_CXX23

struct _EXCEPTION_POINTERS;

#ifdef __cplusplus
#ifndef _M_CEE_PURE
typedef void(__cdecl* _se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS*);

_VCRTIMP _se_translator_function __cdecl _set_se_translator(_In_opt_ _se_translator_function _NewSETranslator);
#endif // _M_CEE_PURE

extern "C++" { // attach declarations to the global module, see N4910 [module.unit]/7
class type_info;
} // extern "C++"

_VCRTIMP int __cdecl _is_exception_typeof(_In_ type_info const& _Type, _In_ _EXCEPTION_POINTERS* _ExceptionPtr);

_VCRTIMP bool __cdecl __uncaught_exception();
_VCRTIMP int __cdecl __uncaught_exceptions();
#endif // __cplusplus

_CRT_END_C_HEADER

#pragma warning(pop) // _VCRUNTIME_DISABLED_WARNINGS

#endif // _VCRT_COMPILER_PREPROCESSOR

#ifdef _M_CEE_PURE
#include <vcruntime_new.h>
#endif

#if _VCRT_COMPILER_PREPROCESSOR && _HAS_EXCEPTIONS

#pragma warning(push)
#pragma warning(disable : _VCRUNTIME_DISABLED_WARNINGS)

#pragma pack(push, _CRT_PACKING)

_CRT_BEGIN_C_HEADER

struct __std_exception_data {
  char const* _What;
  bool _DoFree;
};

_VCRTIMP void __cdecl __std_exception_copy(_In_ __std_exception_data const* _From, _Inout_ __std_exception_data* _To);

_VCRTIMP void __cdecl __std_exception_destroy(_Inout_ __std_exception_data* _Data);

_CRT_END_C_HEADER

namespace std {

#pragma warning(push)
#pragma warning(disable : 4577) // 'noexcept' used with no exception handling mode specified
class exception {
public:
  exception() noexcept : _Data() {}

  explicit exception(char const* const _Message) noexcept : _Data() {
    __std_exception_data _InitData = {_Message, true};
    __std_exception_copy(&_InitData, &_Data);
  }

  exception(char const* const _Message, int) noexcept : _Data() { _Data._What = _Message; }

  exception(exception const& _Other) noexcept : _Data() { __std_exception_copy(&_Other._Data, &_Data); }

  exception& operator=(exception const& _Other) noexcept {
    if (this == &_Other) { return *this; }

    __std_exception_destroy(&_Data);
    __std_exception_copy(&_Other._Data, &_Data);
    return *this;
  }

  virtual ~exception() noexcept { __std_exception_destroy(&_Data); }

  _NODISCARD virtual char const* what() const { return _Data._What ? _Data._What : "Unknown exception"; }

private:
  __std_exception_data _Data;
};

class bad_exception : public exception {
public:
  bad_exception() noexcept : exception("bad exception", 1) {}
};

class bad_alloc : public exception {
public:
  bad_alloc() noexcept : exception("bad allocation", 1) {}

private:
  friend class bad_array_new_length;

  bad_alloc(char const* const _Message) noexcept : exception(_Message, 1) {}
};

class bad_array_new_length : public bad_alloc {
public:
  bad_array_new_length() noexcept : bad_alloc("bad array new length") {}
};

#pragma warning(pop)

} // namespace std

#pragma pack(pop)

#pragma warning(pop) // _VCRUNTIME_DISABLED_WARNINGS
#endif               // _VCRT_COMPILER_PREPROCESSOR && _HAS_EXCEPTIONS
