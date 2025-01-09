/// \file xatomic_wait.h
/// \copyright (c) 2022 ywx9.com

#pragma once

#if ywstd_is_exported
extern "C" {
inline constexpr unsigned long long _Atomic_wait_no_deadline = 0xFFFF'FFFF'FFFF'FFFF;
inline constexpr unsigned long _Atomic_wait_no_timeout = 0xFFFF'FFFF;

inline constexpr unsigned long __std_atomic_wait_no_timeout = 0xFFFF'FFFF;

enum class __std_atomic_api_level : unsigned long {
  __not_set,
  __detecting,
  __has_srwlock,
  __has_wait_on_address,
};

__std_atomic_api_level __stdcall __std_atomic_set_api_level(__std_atomic_api_level) noexcept;
int __stdcall __std_atomic_wait_direct(const void*, void*, size_t, unsigned long) noexcept;
void __stdcall __std_atomic_notify_one_direct(const void*) noexcept;
void __stdcall __std_atomic_notify_all_direct(const void*) noexcept;

using _Atomic_wait_indirect_equal_callback_t = bool(__stdcall*)(const void*, void*, size_t, void*) noexcept;
int __stdcall __std_atomic_wait_indirect(const void*, void*, size_t, void*, _Atomic_wait_indirect_equal_callback_t,
                                         unsigned long) noexcept;
void __stdcall __std_atomic_notify_one_indirect(const void*) noexcept;
void __stdcall __std_atomic_notify_all_indirect(const void*) noexcept;

unsigned long long __stdcall __std_atomic_wait_get_deadline(unsigned long long) noexcept;
unsigned long __stdcall __std_atomic_wait_get_remaining_timeout(unsigned long long) noexcept;
}
#endif
