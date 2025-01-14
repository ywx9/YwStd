/// \file corecrt_terminate.h
/// \copyright (c) 2022 ywx9.com

#pragma once

#include "corecrt.h"

#if ywstd_is_exported
extern "C" {
using terminate_handler = void(__cdecl*)(void);
[[noreturn]] void __cdecl abort();
[[noreturn]] void __cdecl terminate() throw();
terminate_handler __cdecl set_terminate(terminate_handler) throw();
terminate_handler __cdecl _get_terminate();
}
#endif
