/// \file abc.hpp
/// \brief primary header file for `ywstd`
/// \copyright (c) 2022 ywx9.com

// clang-format off
#pragma once

#define nat size_t
#define wchar wchar_t

#ifndef ywstd_export
#define ywstd_export
#endif

#pragma region <cassert>
#if ywstd_is_exported
extern "C" {
export void __cdecl _wassert(wchar_t const*, wchar_t const*, unsigned);
}
#endif
#ifndef assert
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
#define ywstd_filew__(file) L##file
#define ywstd_filew_(file) ywstd_filew__(file)
#define ywstd_filew ywstd_filew_(__FILE__)
#define assert(e) (static_cast<void>(!(e) && (::_wassert(L#e, ywstd_filew, unsigned(__LINE__)), 0)))
#endif
#endif
#pragma endregion // <cassert>

#pragma region <cctype>
#if ywstd_is_exported
extern "C" {
int __cdecl isalnum(int);
int __cdecl isalpha(int);
int __cdecl isblank(int);
int __cdecl iscntrl(int);
int __cdecl isdigit(int);
int __cdecl isgraph(int);
int __cdecl islower(int);
int __cdecl isprint(int);
int __cdecl ispunct(int);
int __cdecl isspace(int);
int __cdecl isupper(int);
int __cdecl isxdigit(int);
int __cdecl tolower(int);
int __cdecl toupper(int);
}
#endif
#pragma endregion // <cctype>

#pragma region <cerrno>
#if ywstd_is_exported
extern "C" {
export int* __cdecl _errno();
}
#endif
#ifndef errno
/// macro which expands to thread-local error number variable
#define errno (static_cast<int&>(*::_errno()))
#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EAGAIN 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define EINVAL 22
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define ERANGE 34
#define EDEADLK 36
#define ENAMETOOLONG 38
#define ENOLCK 39
#define ENOSYS 40
#define ENOTEMPTY 41
#define EILSEQ 42
#define STRUNCATE 80
#define EADDRINUSE 100
#define EADDRNOTAVAIL 101
#define EAFNOSUPPORT 102
#define EALREADY 103
#define EBADMSG 104
#define ECANCELED 105
#define ECONNABORTED 106
#define ECONNREFUSED 107
#define ECONNRESET 108
#define EDESTADDRREQ 109
#define EHOSTUNREACH 110
#define EIDRM 111
#define EINPROGRESS 112
#define EISCONN 113
#define ELOOP 114
#define EMSGSIZE 115
#define ENETDOWN 116
#define ENETRESET 117
#define ENETUNREACH 118
#define ENOBUFS 119
#define ENODATA 120
#define ENOLINK 121
#define ENOMSG 122
#define ENOPROTOOPT 123
#define ENOSR 124
#define ENOSTR 125
#define ENOTCONN 126
#define ENOTRECOVERABLE 127
#define ENOTSOCK 128
#define ENOTSUP 129
#define EOPNOTSUPP 130
#define EOTHER 131
#define EOVERFLOW 132
#define EOWNERDEAD 133
#define EPROTO 134
#define EPROTONOSUPPORT 135
#define EPROTOTYPE 136
#define ETIME 137
#define ETIMEDOUT 138
#define ETXTBSY 139
#define EWOULDBLOCK 140
#endif
#pragma endregion // <cerrno>

#pragma region <cfenv>
#if ywstd_is_exported
extern "C" {
struct fenv_t {unsigned long _Fe_ctl, _Fe_stat;};
using fexcept_t = unsigned long;
int __cdecl fegetround();
int __cdecl fesetround(int);
int __cdecl fegetenv(fenv_t*);
int __cdecl fesetenv(const fenv_t*);
int __cdecl feclearexcept(int);
int __cdecl feholdexcept(fenv_t*);
int __cdecl fetestexcept(int);
int __cdecl fegetexceptflag(fexcept_t*, int);
int __cdecl fesetexceptflag(const fexcept_t*, int);
export __declspec(selectany) extern const fenv_t _Fenv1{0x3f00003f, 0};
}
#endif
#ifndef FE_ALL_EXCEPT
#define FE_TONEAREST 0x000
#define FE_DOWNWARD 0x100
#define FE_UPWARD 0x200
#define FE_TOWARDZERO 0x300
#define FE_INEXACT 0x01
#define FE_UNDERFLOW 0x02
#define FE_OVERFLOW 0x04
#define FE_DIVBYZERO 0x08
#define FE_INVALID 0x10
#define FE_ALL_EXCEPT 0x1f
#define FE_DFL_ENV (static_cast<const std::fenv_t*>(&_Fenv1))
#endif
#pragma endregion // <cfenv>

#pragma region <cfloat>
#if ywstd_is_exported
extern "C" {
export int __cdecl __fpe_flt_rounds();
}
#endif
#ifndef FLT_RADIX
#define FLT_RADIX 2
#define FLT_ROUNDS (static_cast<int>(::__fpe_flt_rounds()))
#ifdef _M_FP_FAST
#define FLT_EVAL_METHOD -1
#else
#ifdef _M_IX86
#if _M_IX86_FP >= 2
#define FLT_EVAL_METHOD 0
#else
#define FLT_EVAL_METHOD 2
#endif
#else
#define FLT_EVAL_METHOD 0
#endif
#endif
#define DECIMAL_DIG 17
#define FLT_DECIMAL_DIG 9
#define DBL_DECIMAL_DIG 17
#define LDBL_DECIMAL_DIG 21
#define FLT_MAX 3.402823466e+38F
#define DBL_MAX 1.7976931348623158e+308
#define LDBL_MAX 1.7976931348623158e+308L
#define FLT_MIN 1.175494351e-38F
#define DBL_MIN 2.2250738585072014e-308
#define LDBL_MIN 2.2250738585072014e-308L
#define FLT_TRUE_MIN 1.401298464e-45F
#define DBL_TRUE_MIN 4.9406564584124654e-324
#define LDBL_TRUE_MIN 4.9406564584124654e-324L
#define FLT_EPSILON 1.192092896e-07F
#define DBL_EPSILON 2.2204460492503131e-016
#define LDBL_EPSILON 2.2204460492503131e-016L
#define FLT_DIG 6
#define DBL_DIG 15
#define LDBL_DIG 15
#define FLT_MANT_DIG 24
#define DBL_MANT_DIG 53
#define LDBL_MANT_DIG 53
#define FLT_MAX_EXP 128
#define DBL_MAX_EXP 1024
#define LDBL_MAX_EXP 1024
#define FLT_MIN_EXP -125
#define DBL_MIN_EXP -1021
#define LDBL_MIN_EXP -1021
#define FLT_MAX_10_EXP 38
#define DBL_MAX_10_EXP 308
#define LDBL_MAX_10_EXP 308
#define FLT_MIN_10_EXP -37
#define DBL_MIN_10_EXP -307
#define LDBL_MIN_10_EXP -307
#define FLT_HAS_SUBNORM 1
#define DBL_HAS_SUBNORM 1
#define LDBL_HAS_SUBNORM 1
#endif
#pragma endregion // <cfloat>

#pragma region <cinttypes>
#if ywstd_is_exported
extern "C" {
using intmax_t = long long;
using uintmax_t = unsigned long long;
struct imaxdiv_t { intmax_t quot, rem; };
intmax_t __cdecl imaxabs(intmax_t);
imaxdiv_t __cdecl imaxdiv(intmax_t, intmax_t);
intmax_t __cdecl strtoimax(const char*, char**, int);
intmax_t __cdecl wcstoimax(const wchar_t*, wchar_t**, int);
uintmax_t __cdecl strtoumax(const char*, char**, int);
uintmax_t __cdecl wcstoumax(const wchar_t*, wchar_t**, int);
}
#endif
#ifndef PRId8
#define PRId8 "hhd"
#define PRId16 "hd"
#define PRId32 "d"
#define PRId64 "lld"
#define PRIdLEAST8 PRId8
#define PRIdLEAST16 PRId16
#define PRIdLEAST32 PRId32
#define PRIdLEAST64 PRId64
#define PRIdFAST8 PRId8
#define PRIdFAST16 PRId32
#define PRIdFAST32 PRId32
#define PRIdFAST64 PRId64
#define PRIdMAX PRId64
#ifdef _WIN64
#define PRIdPTR PRId64
#else
#define PRIdPTR PRId32
#endif
#define PRIi8 "hhi"
#define PRIi16 "hi"
#define PRIi32 "i"
#define PRIi64 "lli"
#define PRIiLEAST8 PRIi8
#define PRIiLEAST16 PRIi16
#define PRIiLEAST32 PRIi32
#define PRIiLEAST64 PRIi64
#define PRIiFAST8 PRIi8
#define PRIiFAST16 PRIi32
#define PRIiFAST32 PRIi32
#define PRIiFAST64 PRIi64
#define PRIiMAX PRIi64
#ifdef _WIN64
#define PRIiPTR PRIi64
#else
#define PRIiPTR PRIi32
#endif
#define PRIo8 "hho"
#define PRIo16 "ho"
#define PRIo32 "o"
#define PRIo64 "llo"
#define PRIoLEAST8 PRIo8
#define PRIoLEAST16 PRIo16
#define PRIoLEAST32 PRIo32
#define PRIoLEAST64 PRIo64
#define PRIoFAST8 PRIo8
#define PRIoFAST16 PRIo32
#define PRIoFAST32 PRIo32
#define PRIoFAST64 PRIo64
#define PRIoMAX PRIo64
#ifdef _WIN64
#define PRIoPTR PRIo64
#else
#define PRIoPTR PRIo32
#endif
#define PRIu8 "hhu"
#define PRIu16 "hu"
#define PRIu32 "u"
#define PRIu64 "llu"
#define PRIuLEAST8 PRIu8
#define PRIuLEAST16 PRIu16
#define PRIuLEAST32 PRIu32
#define PRIuLEAST64 PRIu64
#define PRIuFAST8 PRIu8
#define PRIuFAST16 PRIu32
#define PRIuFAST32 PRIu32
#define PRIuFAST64 PRIu64
#define PRIuMAX PRIu64
#ifdef _WIN64
#define PRIuPTR PRIu64
#else
#define PRIuPTR PRIu32
#endif
#define PRIx8 "hhx"
#define PRIx16 "hx"
#define PRIx32 "x"
#define PRIx64 "llx"
#define PRIxLEAST8 PRIx8
#define PRIxLEAST16 PRIx16
#define PRIxLEAST32 PRIx32
#define PRIxLEAST64 PRIx64
#define PRIxFAST8 PRIx8
#define PRIxFAST16 PRIx32
#define PRIxFAST32 PRIx32
#define PRIxFAST64 PRIx64
#define PRIxMAX PRIx64
#ifdef _WIN64
#define PRIxPTR PRIx64
#else
#define PRIxPTR PRIx32
#endif
#define PRIX8 "hhX"
#define PRIX16 "hX"
#define PRIX32 "X"
#define PRIX64 "llX"
#define PRIXLEAST8 PRIX8
#define PRIXLEAST16 PRIX16
#define PRIXLEAST32 PRIX32
#define PRIXLEAST64 PRIX64
#define PRIXFAST8 PRIX8
#define PRIXFAST16 PRIX32
#define PRIXFAST32 PRIX32
#define PRIXFAST64 PRIX64
#define PRIXMAX PRIX64
#ifdef _WIN64
#define PRIXPTR PRIX64
#else
#define PRIXPTR PRIX32
#endif
#define SCNd8 "hhd"
#define SCNd16 "hd"
#define SCNd32 "d"
#define SCNd64 "lld"
#define SCNdLEAST8 SCNd8
#define SCNdLEAST16 SCNd16
#define SCNdLEAST32 SCNd32
#define SCNdLEAST64 SCNd64
#define SCNdFAST8 SCNd8
#define SCNdFAST16 SCNd32
#define SCNdFAST32 SCNd32
#define SCNdFAST64 SCNd64
#define SCNdMAX SCNd64
#ifdef _WIN64
#define SCNdPTR SCNd64
#else
#define SCNdPTR SCNd32
#endif
#define SCNi8 "hhi"
#define SCNi16 "hi"
#define SCNi32 "i"
#define SCNi64 "lli"
#define SCNiLEAST8 SCNi8
#define SCNiLEAST16 SCNi16
#define SCNiLEAST32 SCNi32
#define SCNiLEAST64 SCNi64
#define SCNiFAST8 SCNi8
#define SCNiFAST16 SCNi32
#define SCNiFAST32 SCNi32
#define SCNiFAST64 SCNi64
#define SCNiMAX SCNi64
#ifdef _WIN64
#define SCNiPTR SCNi64
#else
#define SCNiPTR SCNi32
#endif
#define SCNo8 "hho"
#define SCNo16 "ho"
#define SCNo32 "o"
#define SCNo64 "llo"
#define SCNoLEAST8 SCNo8
#define SCNoLEAST16 SCNo16
#define SCNoLEAST32 SCNo32
#define SCNoLEAST64 SCNo64
#define SCNoFAST8 SCNo8
#define SCNoFAST16 SCNo32
#define SCNoFAST32 SCNo32
#define SCNoFAST64 SCNo64
#define SCNoMAX SCNo64
#ifdef _WIN64
#define SCNoPTR SCNo64
#else
#define SCNoPTR SCNo32
#endif
#define SCNu8 "hhu"
#define SCNu16 "hu"
#define SCNu32 "u"
#define SCNu64 "llu"
#define SCNuLEAST8 SCNu8
#define SCNuLEAST16 SCNu16
#define SCNuLEAST32 SCNu32
#define SCNuLEAST64 SCNu64
#define SCNuFAST8 SCNu8
#define SCNuFAST16 SCNu32
#define SCNuFAST32 SCNu32
#define SCNuFAST64 SCNu64
#define SCNuMAX SCNu64
#ifdef _WIN64
#define SCNuPTR SCNu64
#else
#define SCNuPTR SCNu32
#endif
#define SCNx8 "hhx"
#define SCNx16 "hx"
#define SCNx32 "x"
#define SCNx64 "llx"
#define SCNxLEAST8 SCNx8
#define SCNxLEAST16 SCNx16
#define SCNxLEAST32 SCNx32
#define SCNxLEAST64 SCNx64
#define SCNxFAST8 SCNx8
#define SCNxFAST16 SCNx32
#define SCNxFAST32 SCNx32
#define SCNxFAST64 SCNx64
#define SCNxMAX SCNx64
#ifdef _WIN64
#define SCNxPTR SCNx64
#else
#define SCNxPTR SCNx32
#endif
#endif
#pragma endregion // <cinttypes>

#pragma region <climits>
#ifndef CHAR_BIT
#define CHAR_BIT 8
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127
#define UCHAR_MAX 0xff
#ifndef _CHAR_UNSIGNED
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX
#else
#define CHAR_MIN 0
#define CHAR_MAX UCHAR_MAX
#endif
#define MB_LEN_MAX 5
#define SHRT_MIN (-32768)
#define SHRT_MAX 32767
#define USHRT_MAX 0xffff
#define INT_MIN (-2147483647 - 1)
#define INT_MAX 2147483647
#define UINT_MAX 0xffffffff
#define LONG_MIN (-2147483647L - 1)
#define LONG_MAX 2147483647L
#define ULONG_MAX 0xffffffffUL
#define LLONG_MAX 9223372036854775807i64
#define LLONG_MIN (-9223372036854775807i64 - 1)
#define ULLONG_MAX 0xffffffffffffffffui64
#ifdef _WIN64
#define SIZE_MAX 0xffffffffffffffffui64
#else
#define SIZE_MAX 0xffffffffui32
#endif
#define RSIZE_MAX (SIZE_MAX >> 1)
#endif
#pragma endregion // <climits>

#pragma region <clocale>
#if ywstd_is_exported
extern "C" {
struct lconv {
  char *decimal_point, *thousands_sep, *grouping, *int_curr_symbol, *currency_symbol,
       *mon_decimal_point, *mon_thousands_sep, *mon_grouping, *positive_sign, *negative_sign;
  char int_frac_digits, frac_digits, p_cs_precedes, p_sep_by_space,
       n_cs_precedes, n_sep_by_space, p_sign_posn, n_sign_posn;
  wchar *_W_decimal_point, *_W_thousands_sep, *_W_int_curr_symbol, *_W_currency_symbol,
        * _W_mon_decimal_point, *_W_mon_thousands_sep, *_W_positive_sign, *_W_negative_sign;
};
char* __cdecl setlocale(int, const char*);
lconv* __cdecl localeconv();
}
#endif
#ifndef NULL
#define NULL 0
#endif
#ifndef LC_ALL
#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5
#endif
#pragma endregion // <clocale>

#pragma region <cmath>
#if ywstd_is_exported
extern "C" {
#define ywstd_math_func1(name) float __cdecl name##f(float); double __cdecl name(double)
#define ywstd_math_func2(name) float __cdecl name##f(float, float); double __cdecl name(double, double)
ywstd_math_func1(ceil);
ywstd_math_func1(floor);
ywstd_math_func1(trunc);
ywstd_math_func1(round);
float __cdecl fmaf(float, float, float);
double __cdecl fma(double, double, double);
ywstd_math_func2(fmax);
ywstd_math_func2(fmin);
ywstd_math_func2(fdim);
int __cdecl abs(int);
long __cdecl labs(long);
long long __cdecl llabs(long long);
ywstd_math_func1(fabs);
long double __cdecl fabsl(long double);
ywstd_math_func2(fmod);
ywstd_math_func2(remainder);
float __cdecl remquof(float, float, int*);
double __cdecl remquo(double, double, int*);
float __cdecl nanf(const char*);
double __cdecl nan(const char*);
ywstd_math_func1(exp);
ywstd_math_func1(exp2);
ywstd_math_func1(expm1);
ywstd_math_func1(log);
ywstd_math_func1(log2);
ywstd_math_func1(log10);
ywstd_math_func1(log1p);
ywstd_math_func2(pow);
ywstd_math_func1(sqrt);
ywstd_math_func1(cbrt);
ywstd_math_func2(hypot);
ywstd_math_func1(sin);
ywstd_math_func1(cos);
ywstd_math_func1(tan);
ywstd_math_func1(asin);
ywstd_math_func1(acos);
ywstd_math_func1(atan);
ywstd_math_func2(atan2);
ywstd_math_func1(sinh);
ywstd_math_func1(cosh);
ywstd_math_func1(tanh);
ywstd_math_func1(asinh);
ywstd_math_func1(acosh);
ywstd_math_func1(atanh);
ywstd_math_func1(erf);
ywstd_math_func1(erfc);
ywstd_math_func1(tgamma);
ywstd_math_func1(lgamma);
long __cdecl lroundf(float);
long __cdecl lround(double);
long long __cdecl llroundf(float);
long long __cdecl llround(double);
ywstd_math_func1(nearbyint);
ywstd_math_func1(rint);
long __cdecl lrintf(float);
long __cdecl lrint(double);
long long __cdecl llrintf(float);
long long __cdecl llrint(double);
double __cdecl frexp(double, int*);
float __cdecl ldexpf(float, int);
double __cdecl ldexp(double, int);
float __cdecl modff(float, float*);
double __cdecl modf(double, double*);
float __cdecl scalbnf(float, int);
double __cdecl scalbn(double, int);
float __cdecl scalblnf(float, long);
double __cdecl scalbln(double, long);
int __cdecl ilogbf(float);
int __cdecl ilogb(double);
ywstd_math_func1(logb);
ywstd_math_func2(nextafter);
float __cdecl nexttowardf(float, long double);
double __cdecl nexttoward(double, long double);
ywstd_math_func2(copysign);
short __cdecl _fdtest(float*);
short __cdecl _dtest(double*);
short __cdecl _ldtest(long double*);
int __cdecl _fdsign(float);
int __cdecl _dsign(double);
int __cdecl _ldsign(long double);
int __cdecl _fdpcomp(float, float);
int __cdecl _dpcomp(double, double);
int __cdecl _ldpcomp(long double, long double);
[[nodiscard]] float __stdcall __std_smf_assoc_laguerref(unsigned, unsigned, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_assoc_laguerre(unsigned, unsigned, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_assoc_legendref(unsigned, unsigned, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_assoc_legendre(unsigned, unsigned, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_betaf(float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_beta(double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_comp_ellint_1f(float) noexcept;
[[nodiscard]] double __stdcall __std_smf_comp_ellint_1(double) noexcept;
[[nodiscard]] float __stdcall __std_smf_comp_ellint_2f(float) noexcept;
[[nodiscard]] double __stdcall __std_smf_comp_ellint_2(double) noexcept;
[[nodiscard]] float __stdcall __std_smf_comp_ellint_3f(float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_comp_ellint_3(double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_cyl_bessel_if(float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_cyl_bessel_i(double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_cyl_bessel_jf(float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_cyl_bessel_j(double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_cyl_bessel_kf(float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_cyl_bessel_k(double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_cyl_neumannf(float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_cyl_neumann(double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_ellint_1f(float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_ellint_1(double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_ellint_2f(float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_ellint_2(double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_ellint_3f(float, float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_ellint_3(double, double, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_expintf(float) noexcept;
[[nodiscard]] double __stdcall __std_smf_expint(double) noexcept;
[[nodiscard]] float __stdcall __std_smf_hermitef(unsigned, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_hermite(unsigned, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_laguerref(unsigned, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_laguerre(unsigned, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_legendref(unsigned, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_legendre(unsigned, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_riemann_zetaf(float) noexcept;
[[nodiscard]] double __stdcall __std_smf_riemann_zeta(double) noexcept;
[[nodiscard]] float __stdcall __std_smf_sph_besself(unsigned, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_sph_bessel(unsigned, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_sph_legendref(unsigned, unsigned, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_sph_legendre(unsigned, unsigned, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_sph_neumannf(unsigned, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_sph_neumann(unsigned, double) noexcept;
[[nodiscard]] float __stdcall __std_smf_hypot3f(float, float, float) noexcept;
[[nodiscard]] double __stdcall __std_smf_hypot3(double, double, double) noexcept;
#undef ywstd_math_func1
#undef ywstd_math_func2
}
#endif
#ifndef INFINITY
#define INFINITY ((float)(1e+300 * 1e+300))
#ifndef _UCRT_NEGATIVE_NAN
#define NAN (-(float)(INFINITY * 0.0F))
#else
#define NAN ((float)(INFINITY * 0.0F))
#endif
#define HUGE_VALF ((float)INFINITY)
#define HUGE_VAL ((double)INFINITY)
#define HUGE_VALL ((long double)INFINITY)
#define MATH_ERRNO 1
#define MATH_ERREXCEPT 2
#define math_errhandling (MATH_ERRNO | MATH_ERREXCEPT)
#define FP_INFINITE 1
#define FP_NAN 2
#define FP_NORMAL (-1)
#define FP_SUBNORMAL (-2)
#define FP_ZERO 0
#endif
#pragma endregion // <cmath>

#pragma region <csetjmp>
#if ywstd_is_exported
extern "C" {
struct alignas(16) SETJMP_FLOAT128 { unsigned long long Part[2]; };
using jmp_buf = SETJMP_FLOAT128[16];
int __cdecl _setjmp(jmp_buf);
[[noreturn]] void __cdecl longjmp(jmp_buf, int) noexcept(false);
}
#endif
#ifndef setjmp
#define setjmp _setjmp
#endif
#pragma endregion // <csetjmp>

#pragma region <csignal>
#if ywstd_is_exported
extern "C" {
using signal_handler = void(__cdecl)(int);
signal_handler* __cdecl signal(int, signal_handler*);
int __cdecl raise(int);
}
#endif
#ifndef SIG_ERR
#define NSIG 23
#define SIGINT 2
#define SIGILL 4
#define SIGFPE 8
#define SIGSEGV 11
#define SIGTERM 15
#define SIGBREAK 21
#define SIGABRT 22
#define SIGABRT_COMPAT 6
#define SIG_DFL (reinterpret_cast<signal_handler*>(0))
#define SIG_IGN (reinterpret_cast<signal_handler*>(1))
#define SIG_GET (reinterpret_cast<signal_handler*>(2))
#define SIG_SGE (reinterpret_cast<signal_handler*>(3))
#define SIG_ACK (reinterpret_cast<signal_handler*>(4))
#define SIG_DIE (reinterpret_cast<signal_handler*>(5))
#define SIG_ERR (reinterpret_cast<signal_handler*>(-1))
#endif
#pragma endregion // <csignal>

#pragma region <cstdarg>
#if ywstd_is_exported
extern "C" {
using va_list = char*;
void __cdecl __va_start(va_list*, ...);
}
#endif
#ifndef va_start
#define va_start(ap, x) (static_cast<void>([]{ static_assert(!::std::is_reference_v<decltype(x)>); }(), ::__va_start(&ap, x)))
#define va_arg(ap, t) ((sizeof(t) > 8 || (sizeof(t) & (sizeof(t) - 1)) != 0) ? **(t**)((ap += 8) - 8) : *(t*)((ap += 8) - 8))
#define va_end(ap) (static_cast<void>(ap = nullptr))
#define va_copy(dest, src) (static_cast<void>(dest = src))
#endif
#pragma endregion // <cstdarg>

#pragma region <cstddef>
#ifndef offsetof
#define offsetof(s, m) (static_cast<nat>(&reinterpret_cast<char const volatile&>((((s*)0)->m))))
#endif
#pragma endregion // <cstddef>

#pragma region <cstdint>
#if ywstd_is_exported
extern "C" {
using int8_t = signed char;
using int16_t = short;
using int32_t = int;
using int64_t = long long;
using uint8_t = unsigned char;
using uint16_t = unsigned short;
using uint32_t = unsigned int;
using uint64_t = unsigned long long;
using int_least8_t = signed char;
using int_least16_t = short;
using int_least32_t = int;
using int_least64_t = long long;
using uint_least8_t = unsigned char;
using uint_least16_t = unsigned short;
using uint_least32_t = unsigned int;
using uint_least64_t = unsigned long long;
using int_fast8_t = signed char;
using int_fast16_t = int;
using int_fast32_t = int;
using int_fast64_t = long long;
using uint_fast8_t = unsigned char;
using uint_fast16_t = unsigned int;
using uint_fast32_t = unsigned int;
using uint_fast64_t = unsigned long long;
using intmax_t = long long;
using uintmax_t = unsigned long long;
using intptr_t = long long;
using uintptr_t = unsigned long long;
}
#endif
#ifndef INT_LEAST8_MIN
#define INT8_MIN         (static_cast<int8_t>(-128))
#define INT16_MIN        (static_cast<int16_t>(-32768))
#define INT32_MIN        (static_cast<int32_t>(-2147483647 - 1))
#define INT64_MIN        (static_cast<int64_t>(-9223372036854775807LL - 1))
#define INT8_MAX         (static_cast<int8_t>(127))
#define INT16_MAX        (static_cast<int16_t>(32767))
#define INT32_MAX        (static_cast<int32_t>(2147483647))
#define INT64_MAX        (static_cast<int64_t>(9223372036854775807LL))
#define UINT8_MAX        (static_cast<uint8_t>(0xff))
#define UINT16_MAX       (static_cast<uint16_t>(0xffff))
#define UINT32_MAX       (static_cast<uint32_t>(0xffffffff))
#define UINT64_MAX       (static_cast<uint64_t>(0xffffffffffffffffULL))
#define INT_LEAST8_MIN   INT8_MIN
#define INT_LEAST16_MIN  INT16_MIN
#define INT_LEAST32_MIN  INT32_MIN
#define INT_LEAST64_MIN  INT64_MIN
#define INT_LEAST8_MAX   INT8_MAX
#define INT_LEAST16_MAX  INT16_MAX
#define INT_LEAST32_MAX  INT32_MAX
#define INT_LEAST64_MAX  INT64_MAX
#define UINT_LEAST8_MAX  UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX
#define INT_FAST8_MIN    INT8_MIN
#define INT_FAST16_MIN   INT32_MIN
#define INT_FAST32_MIN   INT32_MIN
#define INT_FAST64_MIN   INT64_MIN
#define INT_FAST8_MAX    INT8_MAX
#define INT_FAST16_MAX   INT32_MAX
#define INT_FAST32_MAX   INT32_MAX
#define INT_FAST64_MAX   INT64_MAX
#define UINT_FAST8_MAX   UINT8_MAX
#define UINT_FAST16_MAX  UINT32_MAX
#define UINT_FAST32_MAX  UINT32_MAX
#define UINT_FAST64_MAX  UINT64_MAX
#define INTPTR_MIN       INT64_MIN
#define INTPTR_MAX       INT64_MAX
#define UINTPTR_MAX      UINT64_MAX
#define INTMAX_MIN       INT64_MIN
#define INTMAX_MAX       INT64_MAX
#define UINTMAX_MAX      UINT64_MAX
#define PTRDIFF_MIN      INTPTR_MIN
#define PTRDIFF_MAX      INTPTR_MAX
#define SIG_ATOMIC_MIN   INT32_MIN
#define SIG_ATOMIC_MAX   INT32_MAX
#define WCHAR_MIN        (static_cast<wchar>(0))
#define WCHAR_MAX        (static_cast<wchar>(0xffff))
#define WINT_MIN         (static_cast<unsigned short>(0))
#define WINT_MAX         (static_cast<unsigned short>(0xffff))
#define INT8_C(x)        (static_cast<int8_t>(x))
#define INT16_C(x)       (static_cast<int16_t>(x))
#define INT32_C(x)       (static_cast<int32_t>(x))
#define INT64_C(x)       (static_cast<int64_t>(x##LL))
#define UINT8_C(x)       (static_cast<uint8_t>(x))
#define UINT16_C(x)      (static_cast<uint16_t>(x))
#define UINT32_C(x)      (static_cast<uint32_t>(x))
#define UINT64_C(x)      (static_cast<uint64_t>(x##ULL))
#define INTMAX_C(x)      (static_cast<intmax_t>(x##LL))
#define UINTMAX_C(x)     (static_cast<uintmax_t>(x##ULL))
#endif
#pragma endregion // <cstdint>

#pragma region <cstdio>
#if ywstd_is_exported
extern "C" {
using fpos_t = long long;
struct FILE { void* _Placeholder; };
export FILE* __cdecl __acrt_iob_func(unsigned);
FILE* __cdecl fopen(const char*, const char*);
FILE* __cdecl freopen(const char*, const char*, FILE*);
int __cdecl fclose(FILE*);
int __cdecl fflush(FILE*);
void __cdecl setbuf(FILE*, char*);
int __cdecl setvbuf(FILE*, char*, int, size_t);
size_t __cdecl fread(void*, size_t, size_t, FILE*);
size_t __cdecl fwrite(const void*, size_t, size_t, FILE*);
int __cdecl getc(FILE*);
int __cdecl fgetc(FILE*);
char* __cdecl fgets(char*, int, FILE*);
int __cdecl putc(int, FILE*);
int __cdecl fputc(int, FILE*);
int __cdecl fputs(const char* s, FILE*);
int __cdecl getchar();
int __cdecl putchar(int);
int __cdecl puts(const char*);
int __cdecl ungetc(int, FILE*);
long __cdecl ftell(FILE*);
int __cdecl fgetpos(FILE*, fpos_t*);
int __cdecl fseek(FILE*, long int, int);
int __cdecl fsetpos(FILE*, const fpos_t*);
void __cdecl rewind(FILE*);
void __cdecl clearerr(FILE*);
int __cdecl feof(FILE*);
int __cdecl ferror(FILE*);
void __cdecl perror(const char*);
int __cdecl remove(const char*);
int __cdecl rename(const char*, const char*);
FILE* __cdecl tmpfile();
char* __cdecl tmpnam(char*);
}
#endif
#ifndef stdin
#define stdin (static_cast<::std::FILE*>(::__acrt_iob_func(0)))
#define stdout (static_cast<::std::FILE*>(::__acrt_iob_func(1)))
#define stderr (static_cast<::std::FILE*>(::__acrt_iob_func(2)))
#define _IOFBF 0x0000
#define _IOLBF 0x0040
#define _IONBF 0x0004
#define BUFSIZ 512
#define EOF (-1)
#define FOPEN_MAX 20
#define FILENAME_MAX 260
#define L_tmpnam 260
#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0
#define TMP_MAX 0x7fff
#endif
#pragma endregion // <cstdio>

#pragma region <cstdlib>
#if ywstd_is_exported
extern "C" {
struct div_t { int quot, rem; };
struct ldiv_t { long quot, rem; };
struct lldiv_t { long long quot, rem; };
using atexit_handler = void(__cdecl)();
using compare_pred = int(__cdecl)(const void*, const void*);
int __cdecl ___mb_cur_max_func();
int __cdecl abs(int);
long __cdecl labs(long);
long long __cdecl llabs(long long);
div_t __cdecl div(int, int);
ldiv_t __cdecl ldiv(long, long);
lldiv_t __cdecl lldiv(long long, long long);
[[noreturn]] void __cdecl abort();
[[noreturn]] void __cdecl exit(int);
[[noreturn]] void __cdecl _Exit(int);
[[noreturn]] void __cdecl quick_exit(int);
int __cdecl atexit(atexit_handler*);
int __cdecl at_quick_exit(atexit_handler*);
char* __cdecl getenv(const char*);
int __cdecl system(const char*);
void __cdecl free(void*);
__declspec(restrict) void* __cdecl malloc(size_t);
__declspec(restrict) void* __cdecl calloc(size_t, size_t);
__declspec(restrict) void* __cdecl realloc(void*, size_t);
void __cdecl srand(unsigned);
int __cdecl rand();
void __cdecl qsort(void*, size_t, size_t, compare_pred*);
void* __cdecl bsearch(const void*, const void*, size_t, size_t, compare_pred*);
int __cdecl mblen(const char*, size_t);
int __cdecl mbtowc(wchar_t*, const char*, size_t);
int __cdecl wctomb(char*, wchar_t);
size_t __cdecl mbstowcs(wchar_t*, const char*, size_t);
size_t __cdecl wcstombs(char*, const wchar_t*, size_t);
int __cdecl atoi(const char*);
long __cdecl atol(const char*);
long long __cdecl atoll(const char*);
double __cdecl atof(const char*);
long __cdecl strtol(const char*, char**, int);
long long __cdecl strtoll(const char*, char**, int);
unsigned long __cdecl strtoul(const char*, char**, int);
unsigned long long __cdecl strtoull(const char*, char**, int);
float __cdecl strtof(const char*, char**);
double __cdecl strtod(const char*, char**);
long double __cdecl strtold(const char*, char**);
}
#endif
#ifndef RAND_MAX
#define RAND_MAX 0x7fff
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MB_CUR_MAX (static_cast<int>(::___mb_cur_max_func()))
#endif
#pragma endregion // <cstdlib>

#pragma region <cstring>
#if ywstd_is_exported
extern "C" {
void* __cdecl memcpy(void*, const void*, size_t);
void* __cdecl memmove(void*, const void*, size_t);
char* __cdecl strcpy(char*, const char*);
char* __cdecl strncpy(char*, const char*, size_t);
char* __cdecl strcat(char*, const char*);
int __cdecl memcmp(const void*, const void*, size_t);
int __cdecl strcmp(const char*, const char*);
int __cdecl strcoll(const char*, const char*);
int __cdecl strncmp(const char*, const char*, size_t);
size_t __cdecl strxfrm(char*, const char*, size_t);
const void* __cdecl memchr(const void*, int, size_t);
const char* __cdecl strchr(const char*, int);
size_t __cdecl strcspn(const char*, const char*);
const char* __cdecl strpbrk(const char*, const char*);
const char* __cdecl strrchr(const char*, int);
size_t __cdecl strspn(const char*, const char*);
const char* __cdecl strstr(const char*, const char*);
char* __cdecl strtok(char*, const char*);
void* __cdecl memset(void*, int, size_t);
char* __cdecl strerror(int);
size_t __cdecl strlen(const char*);
}
#endif
#pragma endregion // <cstring>

#pragma region <ctime>
#if ywstd_is_exported
extern "C" {
using clock_t = long;
using time_t = long long;
struct timespec { time_t tv_sec; long tv_nsec; };
struct tm { int tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst; };
struct _timespec64 { long long tv_sec; long tv_nsec; };
clock_t __cdecl clock();
char* __cdecl asctime(const tm*);
size_t __cdecl strftime(char*, size_t, const char*, const tm*);
char* __cdecl _ctime64(const long long*);
double __cdecl _difftime64(long long, long long);
tm* __cdecl _gmtime64(const long long*);
tm* __cdecl _localtime64(const long long*);
long long __cdecl _mktime64(tm*);
long long __cdecl _time64(long long*);
int __cdecl _timespec64_get(_timespec64*, int);
}
#endif
#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC (static_cast<std::clock_t>(1000))
#endif
#pragma endregion // <ctime>

#pragma region <cuchar>
#if ywstd_is_exported
struct mbstate_t {
  unsigned long _Wchar;
  unsigned short _Byte, _State;
};
size_t __cdecl mbrtoc16(char16_t*, const char*, size_t, mbstate_t*);
size_t __cdecl c16rtomb(char*, char16_t, mbstate_t*);
size_t __cdecl mbrtoc32(char32_t*, const char*, size_t, mbstate_t*);
size_t __cdecl c32rtomb(char*, char32_t, mbstate_t*);
#endif
#pragma endregion // <cuchar>

#pragma region <cwchar>
#if ywstd_is_exported
extern "C" {
using wint_t = unsigned short;
wchar_t* __cdecl wcscpy(wchar_t*, const wchar_t*);
wchar_t* __cdecl wcsncpy(wchar_t*, const wchar_t*, size_t);
wchar_t* __cdecl wcscat(wchar_t*, const wchar_t*);
wchar_t* __cdecl wcsncat(wchar_t*, const wchar_t*, size_t);
size_t __cdecl wcsxfrm(wchar_t*, const wchar_t*, size_t);
size_t __cdecl wcslen(const wchar_t*);
int __cdecl wcscmp(const wchar_t*, const wchar_t*);
int __cdecl wcsncmp(const wchar_t*, const wchar_t*, size_t);
int __cdecl wcscoll(const wchar_t*, const wchar_t*);
const wchar_t* __cdecl wcschr(const wchar_t*, wchar_t);
const wchar_t* __cdecl wcsrchr(const wchar_t*, wchar_t);
size_t __cdecl wcsspn(const wchar_t*, const wchar_t*);
size_t __cdecl wcscspn(const wchar_t*, const wchar_t*);
const wchar_t* __cdecl wcspbrk(const wchar_t*, const wchar_t*);
const wchar_t* __cdecl wcsstr(const wchar_t*, const wchar_t*);
wchar_t* __cdecl wcstok(wchar_t*, const wchar_t*);
wchar_t* __cdecl wmemchr(const wchar_t*, wchar_t, size_t);
int __cdecl wmemcmp(const wchar_t*, const wchar_t*, size_t);
wchar_t* __cdecl wmemcpy(wchar_t*, const wchar_t*, size_t);
wchar_t* __cdecl wmemmove(wchar_t*, const wchar_t*, size_t);
wchar_t* __cdecl wmemset(wchar_t*, wchar_t, size_t);
int __cdecl mbsinit(const mbstate_t*);
wint_t __cdecl btowc(int);
int __cdecl wctob(wint_t);
size_t __cdecl mbrlen(const char*, size_t, mbstate_t*);
size_t __cdecl mbrtowc(wchar_t*, const char*, size_t, mbstate_t*);
size_t __cdecl wcrtomb(char*, wchar_t, mbstate_t*);
size_t __cdecl mbsrtowcs(wchar_t*, const char**, size_t, mbstate_t*);
size_t __cdecl wcsrtombs(char*, const wchar_t**, size_t, mbstate_t*);
wint_t __cdecl getwc(FILE*);
wint_t __cdecl fgetwc(FILE*);
wchar_t* __cdecl fgetws(wchar_t*, int, FILE*);
wint_t __cdecl putwc(wint_t, FILE*);
wint_t __cdecl fputwc(wint_t, FILE*);
int __cdecl fputws(const wchar_t*, FILE*);
wint_t __cdecl getwchar();
wint_t __cdecl putwchar(wint_t);
wint_t __cdecl ungetwc(wint_t, FILE*);
int __cdecl fwide(FILE*, int);
long __cdecl wcstol(const wchar_t*, wchar_t**, int);
long long __cdecl wcstoll(const wchar_t*, wchar_t**, int);
unsigned long __cdecl wcstoul(const wchar_t*, wchar_t**, int);
unsigned long long __cdecl wcstoull(const wchar_t*, wchar_t**, int);
float __cdecl wcstof(const wchar_t*, wchar_t**);
double __cdecl wcstod(const wchar_t*, wchar_t**);
long double __cdecl wcstold(const wchar_t*, wchar_t**);
size_t __cdecl wcsftime(wchar_t*, size_t, const wchar_t*, const tm*);
}
#endif
#ifndef WEOF
#define WEOF (static_cast<unsigned short>(0xffff))
#endif
#pragma endregion // <cwchar>

#pragma region <cwctype>
#if ywstd_is_exported
extern "C" {
using wctype_t = unsigned short;
using wctrans_t = wchar_t;
int __cdecl iswalnum(wint_t);
int __cdecl iswalpha(wint_t);
int __cdecl iswlower(wint_t);
int __cdecl iswupper(wint_t);
int __cdecl iswdigit(wint_t);
int __cdecl iswxdigit(wint_t);
int __cdecl iswcntrl(wint_t);
int __cdecl iswgraph(wint_t);
int __cdecl iswspace(wint_t);
int __cdecl iswblank(wint_t);
int __cdecl iswprint(wint_t);
int __cdecl iswpunct(wint_t);
int __cdecl iswctype(wint_t, wctype_t);
wctype_t __cdecl wctype(const char*);
wint_t __cdecl towlower(wint_t);
wint_t __cdecl towupper(wint_t);
wint_t __cdecl towctrans(wint_t, wctrans_t);
wctrans_t __cdecl wctrans(const char*);
}
#endif
#pragma endregion // <cwctype>

#pragma region printf and scanf family
#if ywstd_is_exported
extern "C" {
struct __crt_locale_pointers {
  struct __crt_locale_data* locinfo;
  struct __crt_multibyte_data* mbcinfo;
};
using _locale_t = __crt_locale_pointers*;
__declspec(noinline) inline unsigned long long* __cdecl __local_stdio_printf_options() { static unsigned long long _static; return &_static; }
__declspec(noinline) inline unsigned long long* __cdecl __local_stdio_scanf_options() { static unsigned long long _static; return &_static; }
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS (*__local_stdio_printf_options())
#define _CRT_INTERNAL_LOCAL_SCANF_OPTIONS  (*__local_stdio_scanf_options ())
#define _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION (1ULL << 0)
#define _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR       (1ULL << 1)
#define _CRT_INTERNAL_PRINTF_LEGACY_WIDE_SPECIFIERS           (1ULL << 2)
#define _CRT_INTERNAL_PRINTF_LEGACY_MSVCRT_COMPATIBILITY      (1ULL << 3)
#define _CRT_INTERNAL_PRINTF_LEGACY_THREE_DIGIT_EXPONENTS     (1ULL << 4)
#define _CRT_INTERNAL_PRINTF_STANDARD_ROUNDING                (1ULL << 5)
#define _CRT_INTERNAL_SCANF_SECURECRT                   (1ULL << 0)
#define _CRT_INTERNAL_SCANF_LEGACY_WIDE_SPECIFIERS      (1ULL << 1)
#define _CRT_INTERNAL_SCANF_LEGACY_MSVCRT_COMPATIBILITY (1ULL << 2)
int __cdecl __stdio_common_vsprintf(unsigned long long, char*, size_t, const char*, _locale_t, va_list);
int __cdecl __stdio_common_vfprintf(unsigned long long, FILE*, const char*, _locale_t, va_list);
int __cdecl __stdio_common_vsscanf(unsigned long long, const char*, size_t, const char*, _locale_t, va_list);
int __cdecl __stdio_common_vfscanf(unsigned long long, FILE*, const char*, _locale_t, va_list);
int __cdecl __stdio_common_vswprintf(unsigned long long, wchar*, size_t, const wchar*, _locale_t, va_list);
int __cdecl __stdio_common_vfwprintf(unsigned long long, FILE*, const wchar*, _locale_t, va_list);
int __cdecl __stdio_common_vswscanf(unsigned long long, const wchar*, const wchar*, _locale_t, va_list);
int __cdecl __stdio_common_vfwscanf(unsigned long long, FILE*, const wchar*, _locale_t, va_list);
inline int __cdecl vsnprintf(char* buffer, size_t count, const char* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = ::__stdio_common_vsprintf(options, buffer, count, format, nullptr, args);
  return result < 0 ? -1 : result;
}
inline int __cdecl vsprintf(char* buffer, const char* format, va_list args) {
  return ::vsnprintf(buffer, size_t(-1), format, args);
}
inline int __cdecl vfprintf(FILE* stream, const char* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  return ::__stdio_common_vfprintf(options, stream, format, nullptr, args);
}
inline int __cdecl vsscanf(const char* buffer, const char* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS;
  return ::__stdio_common_vsscanf(options, buffer, size_t(-1), format, nullptr, args);
}
inline int __cdecl vfscanf(FILE* stream, const char* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS;
  return ::__stdio_common_vfscanf(options, stream, format, nullptr, args);
}
inline int __cdecl vswprintf(wchar* buffer, size_t count, const wchar* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  const int result = ::__stdio_common_vswprintf(options, buffer, count, format, nullptr, args);
  return result < 0 ? -1 : result;
}
inline int __cdecl vfwprintf(FILE* stream, const wchar* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  return ::__stdio_common_vfwprintf(options, stream, format, nullptr, args);
}
inline int __cdecl vswscanf(const wchar* buffer, const wchar* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS;
  return ::__stdio_common_vswscanf(options, buffer, format, nullptr, args);
}
inline int __cdecl vfwscanf(FILE* stream, const wchar* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_SCANF_OPTIONS;
  return ::__stdio_common_vfwscanf(options, stream, format, nullptr, args);
}

// for `std::to_string`
inline int __cdecl _vscprintf(const char* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = ::__stdio_common_vsprintf(options, nullptr, 0, format, nullptr, args);
  return result < 0 ? -1 : result;
}
inline int __cdecl _scprintf(const char* format, ...) {
  va_list args;
  __va_start(&args, format);
  const int result = _vscprintf(format, args);
  va_end(args);
  return result;
}
int __cdecl __stdio_common_vsprintf_s(unsigned long long, char*, nat, const char*, _locale_t, va_list);
inline int __cdecl vsprintf_s(char* buffer, nat count, const char* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  const int result = ::__stdio_common_vsprintf_s(options, buffer, count, format, nullptr, args);
  return result < 0 ? -1 : result;
}
inline int __cdecl sprintf_s(char* buffer, nat count, const char* format, ...) {
  va_list args;
  __va_start(&args, format);
  const int result = ::vsprintf_s(buffer, count, format, args);
  va_end(args);
  return result;
}

// for `std::to_wstring`
inline int __cdecl _vscwprintf(const wchar* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
  const int result = ::__stdio_common_vswprintf(options, nullptr, 0, format, nullptr, args);
  return result < 0 ? -1 : result;
}
inline int __cdecl _scwprintf(const wchar* format, ...) {
  va_list args;
  __va_start(&args, format);
  const int result = _vscwprintf(format, args);
  va_end(args);
  return result;
}
int __cdecl __stdio_common_vswprintf_s(unsigned long long, wchar_t*, nat, const wchar_t*, _locale_t, va_list);
inline int __cdecl vswprintf_s(wchar* buffer, nat count, const wchar* format, va_list args) {
  const auto options = _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS;
  const int result =  __stdio_common_vswprintf_s(options, buffer, count, format, nullptr, args);
  return result < 0 ? -1 : result;
}
inline int __cdecl swprintf_s(wchar* buffer, nat count, const wchar* format, ...) {
  va_list args;
  __va_start(&args, format);
  const int result = ::vswprintf_s(buffer, count, format, args);
  va_end(args);
  return result;
}
}
#endif
#pragma endregion // `printf` and `scanf` family

#ifndef ywstd_import
#if not ywstd_is_exported
namespace std {
struct fenv_t {unsigned long _Fe_ctl, _Fe_stat;};
struct imaxdiv_t { intmax_t quot, rem; };
struct lconv {
  char *decimal_point, *thousands_sep, *grouping, *int_curr_symbol, *currency_symbol,
       *mon_decimal_point, *mon_thousands_sep, *mon_grouping, *positive_sign, *negative_sign;
  char int_frac_digits, frac_digits, p_cs_precedes, p_sep_by_space,
       n_cs_precedes, n_sep_by_space, p_sign_posn, n_sign_posn;
  wchar *_W_decimal_point, *_W_thousands_sep, *_W_int_curr_symbol, *_W_currency_symbol,
        * _W_mon_decimal_point, *_W_mon_thousands_sep, *_W_positive_sign, *_W_negative_sign;
};
struct alignas(16) SETJMP_FLOAT128 { unsigned long long Part[2]; };
using jmp_buf = SETJMP_FLOAT128[16];
using signal_handler = void(__cdecl)(int);
using va_list = char*;
using fpos_t = long long;
struct FILE { void* _Placeholder; };
struct div_t { int quot, rem; };
struct ldiv_t { long quot, rem; };
struct lldiv_t { long long quot, rem; };
using atexit_handler = void(__cdecl)();
using compare_pred = int(__cdecl)(const void*, const void*);
using clock_t = long;
using time_t = long long;
struct timespec { time_t tv_sec; long tv_nsec; };
struct tm { int tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst; };
struct mbstate_t { unsigned long _Wchar; unsigned short _Byte, _State; };
}
#else
namespace std {
using ::fenv_t;
using ::imaxdiv_t;
using ::lconv;
using ::SETJMP_FLOAT128;
using ::jmp_buf;
using ::signal_handler;
using ::va_list;
using ::fpos_t;
using ::FILE;
using ::div_t;
using ::ldiv_t;
using ::lldiv_t;
using ::atexit_handler;
using ::compare_pred;
using ::clock_t;
using ::time_t;
using ::timespec;
using ::tm;
using ::mbstate_t;
}
#endif
#endif

#pragma region <type_traits>
#ifndef ywstd_import
ywstd_export namespace std {

template<typename... Ts> using void_t = void;
template<typename... Ts> concept _valid = requires { typename void_t<Ts...>; };
template<typename T> constexpr bool _always_false = false;

template<typename T> struct type_identity { using type = T; };
template<typename T> using type_identity_t = typename type_identity<T>::type;

template<bool B, typename T = void> struct enable_if {};
template<typename T> struct enable_if<true, T> : type_identity<T> {};
template<bool B, typename T, typename F> struct conditional : type_identity<T> {};
template<typename T, typename F> struct conditional<false, T, F> : type_identity<F> {};
template<bool B, typename T = void> using enable_if_t = typename enable_if<B, T>::type;
template<bool B, typename T, typename F> using conditional_t = typename conditional<B, T, F>::type;

template<typename T> struct remove_const : type_identity<T> {};
template<typename T> struct remove_const<const T> : type_identity<T> {};
template<typename T> using remove_const_t = typename remove_const<T>::type;

template<typename T> struct remove_volatile : type_identity<T> {};
template<typename T> struct remove_volatile<volatile T> : type_identity<T> {};
template<typename T> using remove_volatile_t = typename remove_volatile<T>::type;

template<typename T> struct remove_cv : remove_const<remove_volatile_t<T>> {};
template<typename T> using remove_cv_t = typename remove_cv<T>::type;

template<typename T> struct remove_reference : type_identity<T> {};
template<typename T> struct remove_reference<T&> : type_identity<T> {};
template<typename T> struct remove_reference<T&&> : type_identity<T> {};
template<typename T> using remove_reference_t = typename remove_reference<T>::type;

template<typename T> struct remove_cvref : remove_cv<remove_reference_t<T>> {};
template<typename T> using remove_cvref_t = typename remove_cvref<T>::type;

template<typename T> struct remove_pointer : type_identity<T> {};
template<typename T> struct remove_pointer<T*> : type_identity<T> {};
template<typename T> struct remove_pointer<T* const> : type_identity<T> {};
template<typename T> struct remove_pointer<T* volatile> : type_identity<T> {};
template<typename T> struct remove_pointer<T* const volatile> : type_identity<T> {};
template<typename T> using remove_pointer_t = typename remove_pointer<T>::type;

template<typename T> struct remove_extent : type_identity<T> {};
template<typename T> struct remove_extent<T[]> : type_identity<T> {};
template<typename T, nat N> struct remove_extent<T[N]> : type_identity<T> {};
template<typename T> using remove_extent_t = typename remove_extent<T>::type;

template<typename T> struct remove_all_extents : type_identity<T> {};
template<typename T> struct remove_all_extents<T[]> : remove_all_extents<T> {};
template<typename T, nat N> struct remove_all_extents<T[N]> : remove_all_extents<T> {};
template<typename T> using remove_all_extents_t = typename remove_all_extents<T>::type;

template<typename T> struct add_const : type_identity<const T> {};
template<typename T> using add_const_t = typename add_const<T>::type;

template<typename T> struct add_volatile : type_identity<volatile T> {};
template<typename T> using add_volatile_t = typename add_volatile<T>::type;

template<typename T> struct add_cv : type_identity<const volatile T> {};
template<typename T> using add_cv_t = typename add_cv<T>::type;

template<typename T> struct add_lvalue_reference : type_identity<T> {};
template<typename T> requires _valid<T&> struct add_lvalue_reference<T> : type_identity<T&> {};
template<typename T> using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

template<typename T> struct add_rvalue_reference : type_identity<T> {};
template<typename T> requires _valid<T&&> struct add_rvalue_reference<T> : type_identity<T&&> {};
template<typename T> using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

template<typename T> struct add_pointer : type_identity<T> {};
template<typename T> requires _valid<remove_reference_t<T>*> struct add_pointer<T> : type_identity<remove_reference_t<T>*> {};
template<typename T> using add_pointer_t = typename add_pointer<T>::type;

template<typename T> struct _class_type {};
template<typename M, typename C> struct _class_type<M C::*> : type_identity<C> {};
template<typename T> using _class_type_t = typename _class_type<T>::type;

template<typename T> struct _member_type {};
template<typename M, typename C> struct _member_type<M C::*> : type_identity<M> {};
template<typename T> using _member_type_t = typename _member_type<T>::type;

template<typename T, T V> struct integral_constant {
  static constexpr T value = V;
  using value_type = T;
  using type = integral_constant;
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};
template<bool B> using bool_constant = integral_constant<bool, B>;
using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template<typename... Ts> struct conjunction : bool_constant<(Ts::value && ...)> {};
template<typename... Ts> constexpr bool conjunction_v = conjunction<Ts...>::value;

template<typename... Ts> struct disjunction : bool_constant<(Ts::value || ...)> {};
template<typename... Ts> constexpr bool disjunction_v = disjunction<Ts...>::value;

template<typename T> struct negation : bool_constant<!T::value> {};
template<typename T> constexpr bool negation_v = negation<T>::value;

template<typename T> struct is_const : false_type {};
template<typename T> struct is_const<const T> : true_type {};
template<typename T> constexpr bool is_const_v = is_const<T>::value;

template<typename T> struct is_volatile : false_type {};
template<typename T> struct is_volatile<volatile T> : true_type {};
template<typename T> constexpr bool is_volatile_v = is_volatile<T>::value;

template<typename T> struct is_lvalue_reference : false_type {};
template<typename T> struct is_lvalue_reference<T&> : true_type {};
template<typename T> constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

template<typename T> struct is_rvalue_reference : false_type {};
template<typename T> struct is_rvalue_reference<T&&> : true_type {};
template<typename T> constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;

template<typename T> struct is_reference : disjunction<is_lvalue_reference<T>, is_rvalue_reference<T>> {};
template<typename T> constexpr bool is_reference_v = is_reference<T>::value;

template<typename T> struct is_pointer : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
template<typename T> struct is_pointer<T* const> : true_type {};
template<typename T> struct is_pointer<T* volatile> : true_type {};
template<typename T> struct is_pointer<T* const volatile> : true_type {};
template<typename T> constexpr bool is_pointer_v = is_pointer<T>::value;

template<typename T> struct is_bounded_array : false_type {};
template<typename T, nat N> struct is_bounded_array<T[N]> : true_type {};
template<typename T> constexpr bool is_bounded_array_v = is_bounded_array<T>::value;

template<typename T> struct is_unbounded_array : false_type {};
template<typename T> struct is_unbounded_array<T[]> : true_type {};
template<typename T> constexpr bool is_unbounded_array_v = is_unbounded_array<T>::value;

template<typename T> struct is_array : disjunction<is_bounded_array<T>, is_unbounded_array<T>> {};
template<typename T> constexpr bool is_array_v = is_array<T>::value;

template<typename T> struct is_function : conjunction<negation<is_const<const T>>, negation<is_reference<T>>> {};
template<typename T> constexpr bool is_function_v = is_function<T>::value;

template<typename T, typename U> struct is_same : false_type {};
template<typename T> struct is_same<T, T> : true_type {};
template<typename T, typename U> constexpr bool is_same_v = is_same<T, U>::value;

template<typename T, typename U> struct is_base_of : bool_constant<__is_base_of(T, U)> {};
template<typename T, typename U> constexpr bool is_base_of_v = is_base_of<T, U>::value;

template<typename T, typename U> struct is_convertible : bool_constant<__is_convertible_to(T, U)> {};
template<typename T, typename U> constexpr bool is_convertible_v = is_convertible<T, U>::value;

template<typename T, typename... Ts> struct _is_included : disjunction<is_same<T, Ts>...> {};
template<typename T, typename... Ts> constexpr bool _is_included_v = _is_included<T, Ts...>::value;

template<typename T> struct is_void : is_same<remove_cv_t<T>, void> {};
template<typename T> constexpr bool is_void_v = is_void<T>::value;

template<typename T> struct is_null_pointer : is_same<remove_cv_t<T>, nullptr_t> {};
template<typename T> constexpr bool is_null_pointer_v = is_null_pointer<T>::value;

template<typename T> struct _is_bool : is_same<remove_cv_t<T>, bool> {};
template<typename T> constexpr bool _is_bool_v = _is_bool<T>::value;

template<typename T> struct _is_character : _is_included<remove_cv_t<T>, char, wchar, char8_t, char16_t, char32_t> {};
template<typename T> constexpr bool _is_character_v = _is_character<T>::value;

template<typename T> struct _is_int : _is_included<remove_cv_t<T>, signed char, short, int, long, long long> {};
template<typename T> constexpr bool _is_int_v = _is_int<T>::value;

template<typename T> struct _is_uint : _is_included<remove_cv_t<T>, unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long> {};
template<typename T> constexpr bool _is_uint_v = _is_uint<T>::value;

template<typename T> struct is_integral : disjunction<_is_bool<T>, _is_character<T>, _is_int<T>, _is_uint<T>> {};
template<typename T> constexpr bool is_integral_v = is_integral<T>::value;

template<typename T> struct is_floating_point : _is_included<remove_cv_t<T>, float, double, long double> {};
template<typename T> constexpr bool is_floating_point_v = is_floating_point<T>::value;

template<typename T> struct is_arithmetic : disjunction<is_integral<T>, is_floating_point<T>> {};
template<typename T> constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

template<typename T> constexpr bool is_signed_v = is_arithmetic_v<T> && (static_cast<T>(-1) < T{});
template<typename T> struct is_signed : bool_constant<is_signed_v<T>> {};

template<typename T> struct is_unsigned : conjunction<is_integral<T>, negation<is_signed<T>>> {};
template<typename T> constexpr bool is_unsigned_v = is_unsigned<T>::value;

template<typename T> struct is_fundamental : disjunction<is_arithmetic<T>, is_void<T>, is_null_pointer<T>> {};
template<typename T> constexpr bool is_fundamental_v = is_fundamental<T>::value;

template<typename T> struct is_enum : bool_constant<__is_enum(T)> {};
template<typename T> constexpr bool is_enum_v = is_enum<T>::value;

template<typename T> struct is_scoped_enum : conjunction<is_enum<T>, negation<is_convertible<T, int>>> {};
template<typename T> constexpr bool is_scoped_enum_v = is_scoped_enum<T>::value;

template<typename T> struct is_member_pointer : bool_constant<_valid<_class_type_t<T>>> {};
template<typename T> constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

template<typename T> constexpr bool is_member_function_pointer_v = requires { requires is_function_v<_member_type_t<T>>; };
template<typename T> struct is_member_function_pointer : bool_constant<is_member_function_pointer_v<T>> {};

template<typename T> struct is_member_object_pointer : conjunction<is_member_pointer<T>, negation<is_member_function_pointer<T>>> {};
template<typename T> constexpr bool is_member_object_pointer_v = is_member_object_pointer<T>::value;

template<typename T> struct is_scalar : disjunction<is_arithmetic<T>, is_enum<T>, is_pointer<T>, is_member_pointer<T>, is_null_pointer<T>> {};
template<typename T> constexpr bool is_scalar_v = is_scalar<T>::value;

template<typename T> struct is_class : bool_constant<__is_class(T)> {};
template<typename T> constexpr bool is_class_v = is_class<T>::value;

template<typename T> struct is_union : bool_constant<__is_union(T)> {};
template<typename T> constexpr bool is_union_v = is_union<T>::value;

template<typename T> struct is_object : conjunction<is_const<const T>, negation<is_void<T>>> {};
template<typename T> constexpr bool is_object_v = is_object<T>::value;

template<typename T> struct is_compound : negation<is_fundamental<T>> {};
template<typename T> constexpr bool is_compound_v = is_compound<T>::value;

template<typename T> struct is_abstract : bool_constant<__is_abstract(T)> {};
template<typename T> constexpr bool is_abstract_v = is_abstract<T>::value;

template<typename T> struct is_empty : bool_constant<__is_empty(T)> {};
template<typename T> constexpr bool is_empty_v = is_empty<T>::value;

template<typename T> struct is_final : bool_constant<__is_final(T)> {};
template<typename T> constexpr bool is_final_v = is_final<T>::value;

template<typename T> struct is_polymorphic : bool_constant<__is_polymorphic(T)> {};
template<typename T> constexpr bool is_polymorphic_v = is_polymorphic<T>::value;

template<typename T> struct is_aggregate : bool_constant<__is_aggregate(T)> {};
template<typename T> constexpr bool is_aggregate_v = is_aggregate<T>::value;

template<typename T> struct is_standard_layout : bool_constant<__is_standard_layout(T)> {};
template<typename T> constexpr bool is_standard_layout_v = is_standard_layout<T>::value;

template<typename T> struct is_trivially_copyable : bool_constant<__is_trivially_copyable(T)> {};
template<typename T> constexpr bool is_trivially_copyable_v = is_trivially_copyable<T>::value;

template<typename T> struct has_virtual_destructor : bool_constant<__has_virtual_destructor(T)> {};
template<typename T> constexpr bool has_virtual_destructor_v = has_virtual_destructor<T>::value;

template<typename T> struct is_destructible : bool_constant<__is_destructible(T)> {};
template<typename T> constexpr bool is_destructible_v = is_destructible<T>::value;

template<typename T> struct is_nothrow_destructible : bool_constant<__is_nothrow_destructible(T)> {};
template<typename T> constexpr bool is_nothrow_destructible_v = is_nothrow_destructible<T>::value;

template<typename T> struct is_trivially_destructible : bool_constant<__is_trivially_destructible(T)> {};
template<typename T> constexpr bool is_trivially_destructible_v = is_trivially_destructible<T>::value;

template<typename T, typename... Ts> struct is_constructible : bool_constant<__is_constructible(T, Ts...)> {};
template<typename T, typename... Ts> constexpr bool is_constructible_v = is_constructible<T, Ts...>::value;

template<typename T, typename... Ts> struct is_nothrow_constructible : bool_constant<__is_nothrow_constructible(T, Ts...)> {};
template<typename T, typename... Ts> constexpr bool is_nothrow_constructible_v = is_nothrow_constructible<T, Ts...>::value;

template<typename T, typename... Ts> struct is_trivially_constructible : bool_constant<__is_trivially_constructible(T, Ts...)> {};
template<typename T, typename... Ts> constexpr bool is_trivially_constructible_v = is_trivially_constructible<T, Ts...>::value;

template<typename T> struct is_default_constructible : is_constructible<T> {};
template<typename T> constexpr bool is_default_constructible_v = is_default_constructible<T>::value;

template<typename T> struct is_nothrow_default_constructible : is_nothrow_constructible<T> {};
template<typename T> constexpr bool is_nothrow_default_constructible_v = is_nothrow_default_constructible<T>::value;

template<typename T> struct is_trivially_default_constructible : is_trivially_constructible<T> {};
template<typename T> constexpr bool is_trivially_default_constructible_v = is_trivially_default_constructible<T>::value;

template<typename T> struct is_copy_constructible : is_constructible<T, const T&> {};
template<typename T> constexpr bool is_copy_constructible_v = is_copy_constructible<T>::value;

template<typename T> struct is_nothrow_copy_constructible : is_nothrow_constructible<T, const T&> {};
template<typename T> constexpr bool is_nothrow_copy_constructible_v = is_nothrow_copy_constructible<T>::value;

template<typename T> struct is_trivially_copy_constructible : is_trivially_constructible<T, const T&> {};
template<typename T> constexpr bool is_trivially_copy_constructible_v = is_trivially_copy_constructible<T>::value;

template<typename T> struct is_move_constructible : is_constructible<T, T> {};
template<typename T> constexpr bool is_move_constructible_v = is_move_constructible<T>::value;

template<typename T> struct is_nothrow_move_constructible : is_nothrow_constructible<T, T> {};
template<typename T> constexpr bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<T>::value;

template<typename T> struct is_trivially_move_constructible : is_trivially_constructible<T, T> {};
template<typename T> constexpr bool is_trivially_move_constructible_v = is_trivially_move_constructible<T>::value;

template<typename T, typename A> struct is_assignable : bool_constant<__is_assignable(T, A)> {};
template<typename T, typename A> constexpr bool is_assignable_v = is_assignable<T, A>::value;

template<typename T, typename A> struct is_nothrow_assignable : bool_constant<__is_nothrow_assignable(T, A)> {};
template<typename T, typename A> constexpr bool is_nothrow_assignable_v = is_nothrow_assignable<T, A>::value;

template<typename T, typename A> struct is_trivially_assignable : bool_constant<__is_trivially_assignable(T, A)> {};
template<typename T, typename A> constexpr bool is_trivially_assignable_v = is_trivially_assignable<T, A>::value;

template<typename T> struct is_copy_assignable : is_assignable<T&, const T&> {};
template<typename T> constexpr bool is_copy_assignable_v = is_copy_assignable<T>::value;

template<typename T> struct is_nothrow_copy_assignable : is_nothrow_assignable<T&, const T&> {};
template<typename T> constexpr bool is_nothrow_copy_assignable_v = is_nothrow_copy_assignable<T>::value;

template<typename T> struct is_trivially_copy_assignable : is_trivially_assignable<T&, const T&> {};
template<typename T> constexpr bool is_trivially_copy_assignable_v = is_trivially_copy_assignable<T>::value;

template<typename T> struct is_move_assignable : is_assignable<T&, T> {};
template<typename T> constexpr bool is_move_assignable_v = is_move_assignable<T>::value;

template<typename T> struct is_nothrow_move_assignable : is_nothrow_assignable<T&, T> {};
template<typename T> constexpr bool is_nothrow_move_assignable_v = is_nothrow_move_assignable<T>::value;

template<typename T> struct is_trivially_move_assignable : is_trivially_assignable<T&, T> {};
template<typename T> constexpr bool is_trivially_move_assignable_v = is_trivially_move_assignable<T>::value;

[[nodiscard]] constexpr bool is_constant_evaluated() noexcept { return __builtin_is_constant_evaluated(); }
template<typename T> add_rvalue_reference_t<T> declval() noexcept { static_assert(_always_false<T>); }
template<typename T> constexpr remove_reference_t<T>&& move(T&& t) noexcept { return static_cast<remove_reference_t<T>&&>(t); }
template<typename T> constexpr T&& forward(remove_reference_t<T>& t) noexcept { return static_cast<T&&>(t); }
template<typename T> constexpr T&& forward(remove_reference_t<T>&& t) noexcept requires is_rvalue_reference_v<T&&> { return static_cast<T&&>(t); }

template<typename T, typename U> struct _copy_cv : type_identity<U> {};
template<typename T, typename U> struct _copy_cv<const T, U> : add_const<U> {};
template<typename T, typename U> struct _copy_cv<volatile T, U> : add_volatile<U> {};
template<typename T, typename U> struct _copy_cv<const volatile T, U> : add_cv<U> {};
template<typename T, typename U> using _copy_cv_t = typename _copy_cv<T, U>::type;

template<typename T, typename U> struct _copy_reference : remove_reference<U> {};
template<typename T, typename U> struct _copy_reference<T&, U> : add_lvalue_reference<U> {};
template<typename T, typename U> struct _copy_reference<T&&, U> : add_rvalue_reference<remove_reference_t<U>> {};
template<typename T, typename U> using _copy_reference_t = typename _copy_reference<T, U>::type;

template<typename T, typename U> struct _copy_cvref : _copy_reference<T, _copy_cv_t<remove_reference_t<T>, remove_reference_t<U>>> {};
template<typename T, typename U> using _copy_cvref_t = typename _copy_cvref<T, U>::type;

template<nat N, bool Signed> struct _make_signed_n {};
template<bool Signed> struct _make_signed_n<1, Signed> : conditional<Signed, signed char, unsigned char> {};
template<bool Signed> struct _make_signed_n<2, Signed> : conditional<Signed, short, unsigned short> {};
template<bool Signed> struct _make_signed_n<4, Signed> : conditional<Signed, int, unsigned int> {};
template<bool Signed> struct _make_signed_n<8, Signed> : conditional<Signed, long long, unsigned long long> {};

template<typename T, typename R = remove_cv_t<T>> struct _make_signed {};
template<typename T> struct _make_signed<T, bool> {};
template<typename T> struct _make_signed<T, long> : type_identity<T> {};
template<typename T> struct _make_signed<T, unsigned long> : _copy_cv<T, long> {};
template<typename T, typename R> requires is_integral_v<T> struct _make_signed<T, R> : _copy_cv<T, typename _make_signed_n<sizeof(T), true>::type> {};

template<typename T> struct make_signed : _make_signed<T> {};
template<typename T> using make_signed_t = typename make_signed<T>::type;

template<typename T, typename R = remove_cv_t<T>> struct _make_unsigned {};
template<typename T> struct _make_unsigned<T, bool> {};
template<typename T> struct _make_unsigned<T, long> : _copy_cv<T, unsigned long> {};
template<typename T> struct _make_unsigned<T, unsigned long> : type_identity<T> {};
template<typename T, typename R> requires is_integral_v<T> struct _make_unsigned<T, R> : _copy_cv<T, typename _make_signed_n<sizeof(T), false>::type> {};

template<typename T> struct make_unsigned : _make_unsigned<T> {};
template<typename T> using make_unsigned_t = typename make_unsigned<T>::type;

template<typename T> struct decay : remove_cvref<T> {};
template<typename T> requires is_array_v<remove_reference_t<T>> struct decay<T> : add_pointer<remove_extent_t<remove_reference_t<T>>> {};
template<typename T> requires is_function_v<remove_reference_t<T>> struct decay<T> : add_pointer<T> {};
template<typename T> using decay_t = typename decay<T>::type;
}
#endif
#pragma endregion // <type_traits>

#ifndef ywstd_import
ywstd_export namespace std {

template<typename T, typename U> concept _half_same_as = is_same_v<T, U>;
template<typename T, typename U> concept same_as = _half_same_as<T, U> && _half_same_as<U, T>;
template<typename T, typename U> concept derived_from = is_base_of_v<U, T> && is_convertible_v<const volatile T*, const volatile U*>;
template<typename T, typename U> concept convertible_to = is_convertible_v<T, U> && requires { static_cast<U>(declval<T>()); };

template<typename T> concept integral = is_integral_v<T>;
template<typename T> concept signed_integral = integral<T> && is_signed_v<T>;
template<typename T> concept unsigned_integral = integral<T> && !signed_integral<T>;
template<typename T> concept floating_point = is_floating_point_v<T>;
template<typename T> concept _arithmetic = integral<T> || floating_point<T>;
}
#endif
