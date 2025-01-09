// yvals.h internal header

// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// This header is used to compile the import library (via locale0_implib.cpp => locale0.cpp => xfacet => yvals.h).
// MAJOR LIMITATIONS apply to what can be included here!
// Before editing this file, read: /docs/import_library.md

#ifndef _YVALS
#define _YVALS
#include "yvals_core.h"
#if _STL_COMPILER_PREPROCESSOR

#ifdef _ENFORCE_ONLY_CORE_HEADERS
_EMIT_STL_ERROR(
    STL1005, "Tried to include a non-core C++ Standard Library header file with _ENFORCE_ONLY_CORE_HEADERS defined.");
#endif // defined(_ENFORCE_ONLY_CORE_HEADERS)

#include "crtdbg.h"
#include "crtdefs.h"

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

#if defined(MRTDLL) && defined(_CRTBLD)
// process-global is the default for code built with /clr or /clr:oldSyntax.
// appdomain-global is the default for code built with /clr:pure.
// Code in MSVCM is built with /clr, but is used by user code built with /clr:pure
// so it must conform to the expectations of /clr:pure clients.
// Use __PURE_APPDOMAIN_GLOBAL when a global needs to be appdomain-global for pure
// clients and process-global for mixed clients.
#define __PURE_APPDOMAIN_GLOBAL __declspec(appdomain)
#else
#define __PURE_APPDOMAIN_GLOBAL
#endif

#ifndef _CRT_MSVCP_CURRENT
#ifdef _CRT_WINDOWS
// Windows
#ifdef _DEBUG
#define _CRT_MSVCP_CURRENT "msvcpd_win.dll"
#else
#define _CRT_MSVCP_CURRENT "msvcp_win.dll"
#endif
#else // ^^^ defined(_CRT_WINDOWS) / !defined(_CRT_WINDOWS) vvv
// Visual Studio
#ifdef _DEBUG
#define _CRT_MSVCP_CURRENT "msvcp140d.dll"
#else
#define _CRT_MSVCP_CURRENT "msvcp140.dll"
#endif
#endif // ^^^ !defined(_CRT_WINDOWS) ^^^
#endif // !defined(_CRT_MSVCP_CURRENT)

#ifdef _ITERATOR_DEBUG_LEVEL // A. _ITERATOR_DEBUG_LEVEL is already defined.

// A1. Validate _ITERATOR_DEBUG_LEVEL.
#if _ITERATOR_DEBUG_LEVEL > 2 && defined(_DEBUG)
#error _ITERATOR_DEBUG_LEVEL > 2 is not supported in debug mode.
#elif _ITERATOR_DEBUG_LEVEL > 1 && !defined(_DEBUG)
#error _ITERATOR_DEBUG_LEVEL > 1 is not supported in release mode.
#endif

// A2. Inspect _HAS_ITERATOR_DEBUGGING.
#ifdef _HAS_ITERATOR_DEBUGGING // A2i. _HAS_ITERATOR_DEBUGGING is already defined, validate it.
#if _ITERATOR_DEBUG_LEVEL == 2 && _HAS_ITERATOR_DEBUGGING != 1
#error _ITERATOR_DEBUG_LEVEL == 2 must imply _HAS_ITERATOR_DEBUGGING == 1.
#elif _ITERATOR_DEBUG_LEVEL < 2 && _HAS_ITERATOR_DEBUGGING != 0
#error _ITERATOR_DEBUG_LEVEL < 2 must imply _HAS_ITERATOR_DEBUGGING == 0.
#endif
#else // A2ii. _HAS_ITERATOR_DEBUGGING is not yet defined, derive it.
#if _ITERATOR_DEBUG_LEVEL == 2
#define _HAS_ITERATOR_DEBUGGING 1
#else
#define _HAS_ITERATOR_DEBUGGING 0
#endif
#endif // ^^^ !defined(_HAS_ITERATOR_DEBUGGING) ^^^

// A3. Inspect _SECURE_SCL.
#ifdef _SECURE_SCL // A3i. _SECURE_SCL is already defined, validate it.
#if _ITERATOR_DEBUG_LEVEL > 0 && _SECURE_SCL != 1
#error _ITERATOR_DEBUG_LEVEL > 0 must imply _SECURE_SCL == 1.
#elif _ITERATOR_DEBUG_LEVEL == 0 && _SECURE_SCL != 0
#error _ITERATOR_DEBUG_LEVEL == 0 must imply _SECURE_SCL == 0.
#endif
#else // A3ii. _SECURE_SCL is not yet defined, derive it.
#if _ITERATOR_DEBUG_LEVEL > 0
#define _SECURE_SCL 1
#else
#define _SECURE_SCL 0
#endif
#endif // ^^^ !defined(_SECURE_SCL) ^^^

#else // B. _ITERATOR_DEBUG_LEVEL is not yet defined.

// B1. Inspect _HAS_ITERATOR_DEBUGGING.
#ifdef _HAS_ITERATOR_DEBUGGING // B1i. _HAS_ITERATOR_DEBUGGING is already defined, validate it.
#if _HAS_ITERATOR_DEBUGGING > 1
#error _HAS_ITERATOR_DEBUGGING must be either 0 or 1.
#elif _HAS_ITERATOR_DEBUGGING == 1 && !defined(_DEBUG)
#error _HAS_ITERATOR_DEBUGGING == 1 is not supported in release mode.
#endif
#else // B1ii. _HAS_ITERATOR_DEBUGGING is not yet defined, default it.
#ifdef _DEBUG
#define _HAS_ITERATOR_DEBUGGING 1
#else
#define _HAS_ITERATOR_DEBUGGING 0
#endif
#endif // ^^^ !defined(_HAS_ITERATOR_DEBUGGING) ^^^

// B2. Inspect _SECURE_SCL.
#ifdef _SECURE_SCL // B2i. _SECURE_SCL is already defined, validate it.
#if _SECURE_SCL > 1
#error _SECURE_SCL must be either 0 or 1.
#endif
#else // B2ii. _SECURE_SCL is not yet defined, default it.
#if _HAS_ITERATOR_DEBUGGING == 1
#define _SECURE_SCL 1
#else
#define _SECURE_SCL 0
#endif
#endif // ^^^ !defined(_SECURE_SCL) ^^^

// B3. Derive _ITERATOR_DEBUG_LEVEL.
#if _HAS_ITERATOR_DEBUGGING
#define _ITERATOR_DEBUG_LEVEL 2
#elif _SECURE_SCL
#define _ITERATOR_DEBUG_LEVEL 1
#else // ^^^ _SECURE_SCL / !_SECURE_SCL vvv
#define _ITERATOR_DEBUG_LEVEL 0
#endif // ^^^ !_HAS_ITERATOR_DEBUGGING && !_SECURE_SCL ^^^

#endif // ^^^ !defined(_ITERATOR_DEBUG_LEVEL) ^^^

#ifndef _ALLOW_MSC_VER_MISMATCH
#pragma detect_mismatch("_MSC_VER", "1900")
#endif // !defined(_ALLOW_MSC_VER_MISMATCH)

#ifndef _ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
#pragma detect_mismatch("_ITERATOR_DEBUG_LEVEL", _STL_STRINGIZE(_ITERATOR_DEBUG_LEVEL))
#endif // !defined(_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH)

#ifndef _ALLOW_RUNTIME_LIBRARY_MISMATCH
#if !defined(_DLL) && !defined(_DEBUG)
#pragma detect_mismatch("RuntimeLibrary", "MT_StaticRelease")
#elif !defined(_DLL) && defined(_DEBUG)
#pragma detect_mismatch("RuntimeLibrary", "MTd_StaticDebug")
#elif defined(_DLL) && !defined(_DEBUG)
#pragma detect_mismatch("RuntimeLibrary", "MD_DynamicRelease")
#elif defined(_DLL) && defined(_DEBUG)
#pragma detect_mismatch("RuntimeLibrary", "MDd_DynamicDebug")
#endif // defined(_DLL) etc.
#endif // !defined(_ALLOW_RUNTIME_LIBRARY_MISMATCH)

#ifndef _CONTAINER_DEBUG_LEVEL
#if _ITERATOR_DEBUG_LEVEL == 0
#define _CONTAINER_DEBUG_LEVEL 0
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 / _ITERATOR_DEBUG_LEVEL != 0 vvv
#define _CONTAINER_DEBUG_LEVEL 1
#endif // _ITERATOR_DEBUG_LEVEL == 0
#endif // !defined(_CONTAINER_DEBUG_LEVEL)

#if _ITERATOR_DEBUG_LEVEL != 0 && _CONTAINER_DEBUG_LEVEL == 0
#error _ITERATOR_DEBUG_LEVEL != 0 must imply _CONTAINER_DEBUG_LEVEL == 1.
#endif // _ITERATOR_DEBUG_LEVEL != 0 && _CONTAINER_DEBUG_LEVEL == 0

#ifndef _STL_CRT_SECURE_INVALID_PARAMETER
#ifdef _STL_CALL_ABORT_INSTEAD_OF_INVALID_PARAMETER
#define _STL_CRT_SECURE_INVALID_PARAMETER(expr) _CSTD abort()
#elif defined(_DEBUG) // Avoid emitting unused long strings for function names; see GH-1956.
// static_cast<unsigned int>(__LINE__) avoids warning C4365 (signed/unsigned mismatch) with the /ZI compiler option.
#define _STL_CRT_SECURE_INVALID_PARAMETER(expr) \
    ::_invalid_parameter(_CRT_WIDE(#expr), L"", __FILEW__, static_cast<unsigned int>(__LINE__), 0)
#else // ^^^ defined(_DEBUG) / !defined(_DEBUG) vvv
#define _STL_CRT_SECURE_INVALID_PARAMETER(expr) _CRT_SECURE_INVALID_PARAMETER(expr)
#endif // ^^^ !defined(_DEBUG) ^^^
#endif // !defined(_STL_CRT_SECURE_INVALID_PARAMETER)

#define _STL_REPORT_ERROR(mesg)                  \
    do {                                         \
        _RPTF0(_CRT_ASSERT, mesg);               \
        _STL_CRT_SECURE_INVALID_PARAMETER(mesg); \
    } while (false)

#ifdef __clang__
#define _STL_VERIFY(cond, mesg)                                                            \
    _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Wassume\"") do { \
        if (cond) { /* contextually convertible to bool paranoia */                        \
        } else {                                                                           \
            _STL_REPORT_ERROR(mesg);                                                       \
        }                                                                                  \
                                                                                           \
        _Analysis_assume_(cond);                                                           \
    }                                                                                      \
    while (false)                                                                          \
    _Pragma("clang diagnostic pop")
#else // ^^^ Clang / MSVC vvv
#define _STL_VERIFY(cond, mesg)                                     \
    do {                                                            \
        if (cond) { /* contextually convertible to bool paranoia */ \
        } else {                                                    \
            _STL_REPORT_ERROR(mesg);                                \
        }                                                           \
                                                                    \
        _Analysis_assume_(cond);                                    \
    } while (false)
#endif // ^^^ MSVC ^^^

#ifdef _DEBUG
#define _STL_ASSERT(cond, mesg) _STL_VERIFY(cond, mesg)
#else // ^^^ defined(_DEBUG) / !defined(_DEBUG) vvv
#define _STL_ASSERT(cond, mesg) _Analysis_assume_(cond)
#endif // ^^^ !defined(_DEBUG) ^^^

#ifdef _ENABLE_STL_INTERNAL_CHECK
#define _STL_INTERNAL_CHECK(...) _STL_VERIFY(__VA_ARGS__, "STL internal check: " #__VA_ARGS__)
#else // ^^^ defined(_ENABLE_STL_INTERNAL_CHECK) / !defined(_ENABLE_STL_INTERNAL_CHECK) vvv
#define _STL_INTERNAL_CHECK(...) _Analysis_assume_(__VA_ARGS__)
#endif // ^^^ !defined(_ENABLE_STL_INTERNAL_CHECK) ^^^

#ifndef _ENABLE_ATOMIC_REF_ALIGNMENT_CHECK
#ifdef _DEBUG
#define _ENABLE_ATOMIC_REF_ALIGNMENT_CHECK 1
#else // ^^^ defined(_DEBUG) / !defined(_DEBUG) vvv
#define _ENABLE_ATOMIC_REF_ALIGNMENT_CHECK 0
#endif // ^^^ !defined(_DEBUG) ^^^
#endif // !defined(_ENABLE_ATOMIC_REF_ALIGNMENT_CHECK)

#if _ENABLE_ATOMIC_REF_ALIGNMENT_CHECK
#define _ATOMIC_REF_CHECK_ALIGNMENT(cond, mesg) _STL_VERIFY(cond, mesg)
#else
#define _ATOMIC_REF_CHECK_ALIGNMENT(cond, mesg) _Analysis_assume_(cond)
#endif

// #include "use_ansi.h" >

#undef _DEBUG_AFFIX
#undef _IDL_AFFIX
#undef _IDL_DEFAULT
#undef _LIB_STEM

#ifdef _DEBUG
#define _DEBUG_AFFIX "d"
#define _IDL_DEFAULT 2
#else
#define _DEBUG_AFFIX ""
#define _IDL_DEFAULT 0
#endif

#if defined(_DLL) && !defined(_STATIC_CPPLIB)
#define _LIB_STEM "msvcprt"
#else
#define _LIB_STEM "libcpmt"
#if _ITERATOR_DEBUG_LEVEL != _IDL_DEFAULT
#define _IDL_AFFIX _STL_STRINGIZE(_ITERATOR_DEBUG_LEVEL)
#endif
#endif

#ifndef _IDL_AFFIX
#define _IDL_AFFIX ""
#endif

#pragma comment(lib, _LIB_STEM _DEBUG_AFFIX _IDL_AFFIX)

#undef _DEBUG_AFFIX
#undef _IDL_AFFIX
#undef _IDL_DEFAULT
#undef _LIB_STEM

// < use_ansi.h

#ifdef _STATIC_CPPLIB
#ifndef _DISABLE_DEPRECATE_STATIC_CPPLIB
#ifdef _DLL
_EMIT_STL_WARNING(STL4000, "_STATIC_CPPLIB is deprecated and will be REMOVED.");
#endif
#ifdef _M_CEE_MIXED
#error _STATIC_CPPLIB is not supported while building with /clr
#endif
#endif // !defined(_DISABLE_DEPRECATE_STATIC_CPPLIB)
#ifdef _M_CEE_PURE
#error _STATIC_CPPLIB cannot be used with /clr:pure (the resulting assembly would not be pure)
#endif
#endif // defined(_STATIC_CPPLIB)

#if defined(_M_CEE_PURE) && !defined(_SILENCE_CLR_PURE_DEPRECATION_WARNING)
_EMIT_STL_WARNING(STL4001, "/clr:pure is deprecated and will be REMOVED.");
#endif

#ifndef _MRTIMP2_PURE
#ifdef _M_CEE_PURE
#define _MRTIMP2_PURE
#else
#define _MRTIMP2_PURE _MRTIMP2
#endif
#endif // !defined(_MRTIMP2_PURE)

#if defined(_DLL) && !defined(_STATIC_CPPLIB) && !defined(_M_CEE_PURE)
#define _DLL_CPPLIB
#endif

#ifndef _CRTIMP2_PURE
#ifdef _M_CEE_PURE
#define _CRTIMP2_PURE
#else
#define _CRTIMP2_PURE _CRTIMP2
#endif
#endif // !defined(_CRTIMP2_PURE)

#ifndef _CRTIMP2_IMPORT
#if defined(CRTDLL2) && defined(_CRTBLD)
#define _CRTIMP2_IMPORT __declspec(dllexport)
#elif defined(_DLL) && !defined(_STATIC_CPPLIB)
#define _CRTIMP2_IMPORT __declspec(dllimport)
#else // ^^^ defined(_DLL) && !defined(_STATIC_CPPLIB) / !defined(_DLL) || defined(_STATIC_CPPLIB) vvv
#define _CRTIMP2_IMPORT
#endif // ^^^ !defined(_DLL) || defined(_STATIC_CPPLIB) ^^^
#endif // !defined(_CRTIMP2_IMPORT)

#ifndef _CRTIMP2_PURE_IMPORT
#ifdef _M_CEE_PURE
#define _CRTIMP2_PURE_IMPORT
#else
#define _CRTIMP2_PURE_IMPORT _CRTIMP2_IMPORT
#endif
#endif // !defined(_CRTIMP2_PURE_IMPORT)

#ifndef _CRTIMP2_PURE_IMPORT_UNLESS_CODECVT_ID_SATELLITE
#ifdef _BUILDING_SATELLITE_CODECVT_IDS
#define _CRTIMP2_PURE_IMPORT_UNLESS_CODECVT_ID_SATELLITE
#else
#define _CRTIMP2_PURE_IMPORT_UNLESS_CODECVT_ID_SATELLITE _CRTIMP2_PURE_IMPORT
#endif
#endif // !defined(_CRTIMP2_PURE_IMPORT_UNLESS_CODECVT_ID_SATELLITE)

#ifndef _CRTDATA2_IMPORT
#if defined(MRTDLL) && defined(_CRTBLD)
#define _CRTDATA2_IMPORT
#else
#define _CRTDATA2_IMPORT _CRTIMP2_IMPORT
#endif
#endif // !defined(_CRTDATA2_IMPORT)

#define _LOCK_LOCALE 0
#define _LOCK_STREAM 2
#define _LOCK_DEBUG  3

_STD_BEGIN
enum _Uninitialized { // tag for suppressing initialization
    _Noinit
};

extern "C++" class _CRTIMP2_PURE_IMPORT _Lockit { // lock while object in existence -- MUST NEST
public:
#ifdef _M_CEE_PURE
    __CLR_OR_THIS_CALL _Lockit() noexcept : _Locktype(0) {
        _Lockit_ctor(this);
    }

    explicit __CLR_OR_THIS_CALL _Lockit(int _Kind) noexcept { // set the lock
        _Lockit_ctor(this, _Kind);
    }

    __CLR_OR_THIS_CALL ~_Lockit() noexcept { // clear the lock
        _Lockit_dtor(this);
    }
#else // ^^^ defined(_M_CEE_PURE) / !defined(_M_CEE_PURE) vvv
    __thiscall _Lockit() noexcept;
    explicit __thiscall _Lockit(int) noexcept; // set the lock
    __thiscall ~_Lockit() noexcept; // clear the lock
#endif // ^^^ !defined(_M_CEE_PURE) ^^^

    static void __cdecl _Lockit_ctor(int) noexcept;
    static void __cdecl _Lockit_dtor(int) noexcept;

private:
    static void __cdecl _Lockit_ctor(_Lockit*) noexcept;
    static void __cdecl _Lockit_ctor(_Lockit*, int) noexcept;
    static void __cdecl _Lockit_dtor(_Lockit*) noexcept;

public:
    __CLR_OR_THIS_CALL _Lockit(const _Lockit&)            = delete;
    _Lockit& __CLR_OR_THIS_CALL operator=(const _Lockit&) = delete;

private:
    int _Locktype;
};

#ifdef _M_CEE_PURE
class _CRTIMP2_PURE_IMPORT _EmptyLockit { // empty lock class used for bin compat
private:
    int _Locktype;
};
#endif // defined(_M_CEE_PURE)

#ifdef _M_CEE
#ifndef _PREPARE_CONSTRAINED_REGIONS
#ifdef _M_CEE_PURE
#define _PREPARE_CONSTRAINED_REGIONS 1
#else // ^^^ defined(_M_CEE_PURE) / !defined(_M_CEE_PURE) vvv
#define _PREPARE_CONSTRAINED_REGIONS 0
#endif // ^^^ !defined(_M_CEE_PURE) ^^^
#endif // !defined(_PREPARE_CONSTRAINED_REGIONS)

#if _PREPARE_CONSTRAINED_REGIONS
#define _BEGIN_LOCK(_Kind)                                                                  \
    {                                                                                       \
        bool _MustReleaseLock = false;                                                      \
        int _LockKind         = _Kind;                                                      \
        System::Runtime::CompilerServices::RuntimeHelpers::PrepareConstrainedRegions();     \
        try {                                                                               \
            System::Runtime::CompilerServices::RuntimeHelpers::PrepareConstrainedRegions(); \
            try {                                                                           \
            } finally {                                                                     \
                _STD _Lockit::_Lockit_ctor(_LockKind);                                      \
                _MustReleaseLock = true;                                                    \
            }

#define _END_LOCK()                                \
    }                                              \
    finally {                                      \
        if (_MustReleaseLock) {                    \
            _STD _Lockit::_Lockit_dtor(_LockKind); \
        }                                          \
    }                                              \
    }

#else // ^^^ _PREPARE_CONSTRAINED_REGIONS / !_PREPARE_CONSTRAINED_REGIONS vvv
#define _BEGIN_LOCK(_Kind) \
    {                      \
        _STD _Lockit _Lock(_Kind);

#define _END_LOCK() }

#endif // ^^^ !_PREPARE_CONSTRAINED_REGIONS ^^^

#define _BEGIN_LOCINFO(_VarName) \
    _BEGIN_LOCK(_LOCK_LOCALE)    \
    _Locinfo _VarName;

#define _END_LOCINFO() _END_LOCK()

#else // ^^^ defined(_M_CEE) / !defined(_M_CEE) vvv
#define _BEGIN_LOCK(_Kind) \
    {                      \
        _STD _Lockit _Lock(_Kind);

#define _END_LOCK() }

#define _BEGIN_LOCINFO(_VarName) \
    {                            \
        _Locinfo _VarName;

#define _END_LOCINFO() }
#endif // ^^^ !defined(_M_CEE) ^^^

#if _HAS_EXCEPTIONS
#define _TRY_BEGIN try {
#define _CATCH(x) \
    }             \
    catch (x) {
#define _CATCH_ALL \
    }              \
    catch (...) {
#define _CATCH_END }

#define _RERAISE    throw
#define _THROW(...) throw(__VA_ARGS__)

#else // ^^^ _HAS_EXCEPTIONS / !_HAS_EXCEPTIONS vvv
#define _TRY_BEGIN \
    {              \
        if (1) {
#define _CATCH(x) \
    }             \
    else if (0) {
#define _CATCH_ALL \
    }              \
    else if (0) {
#define _CATCH_END \
    }              \
    }

#define _RAISE(x) _invoke_watson(nullptr, nullptr, nullptr, 0, 0)

#define _RERAISE
#define _THROW(...) (__VA_ARGS__)._Raise()
#endif // ^^^ !_HAS_EXCEPTIONS ^^^
_STD_END

#pragma pop_macro("new")
_STL_RESTORE_CLANG_WARNINGS
#pragma warning(pop)
#pragma pack(pop)
#endif // _STL_COMPILER_PREPROCESSOR
#endif // _YVALS
