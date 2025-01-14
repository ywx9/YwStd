/// \file corecrt_malloc.h
/// \copyright (c) 2022 ywx9.com

#pragma once

#include "corecrt.h"

#if ywstd_is_exported
extern "C" {
__declspec(allocator) __declspec(restrict) void* __cdecl _calloc_base(size_t, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl calloc(size_t, size_t);
int __cdecl _callnewh(size_t);
__declspec(allocator) void* __cdecl _expand(void*, size_t);
void __cdecl _free_base(void*);
void __cdecl free(void*);
__declspec(allocator) __declspec(restrict) void* __cdecl _malloc_base(size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl malloc(size_t);
size_t __cdecl _msize_base(void*) throw();
size_t __cdecl _msize(void*);
__declspec(allocator) __declspec(restrict) void* __cdecl _realloc_base(void*, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl realloc(void*, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl _recalloc_base(void*, size_t, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl _recalloc(void*, size_t, size_t);
void __cdecl _aligned_free(void*);
__declspec(allocator) __declspec(restrict) void* __cdecl _aligned_malloc(size_t, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl _aligned_offset_malloc(size_t, size_t, size_t);
size_t __cdecl _aligned_msize(void*, size_t, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl _aligned_offset_realloc(void*, size_t, size_t, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl _aligned_offset_recalloc(void*, size_t, size_t, size_t, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl _aligned_realloc(void*, size_t, size_t);
__declspec(allocator) __declspec(restrict) void* __cdecl _aligned_recalloc(void*, size_t, size_t, size_t);
}
#endif
