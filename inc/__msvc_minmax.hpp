/// \file __msvc_minmax.hpp
/// \copyright (c) 2022 ywx9.com

#pragma once

#include "cstdint"

extern "C" {
struct _Min_max_element_t {
  const void *_Min, *_Max;
};

struct _Min_max_1i {
  int8_t _Min, _Max;
};

struct _Min_max_1u {
  uint8_t _Min, _Max;
};

struct _Min_max_2i {
  int16_t _Min, _Max;
};

struct _Min_max_2u {
  uint16_t _Min, _Max;
};

struct _Min_max_4i {
  int32_t _Min, _Max;
};

struct _Min_max_4u {
  uint32_t _Min, _Max;
};

struct _Min_max_8i {
  int64_t _Min, _Max;
};

struct _Min_max_8u {
  uint64_t _Min, _Max;
};

struct _Min_max_f {
  float _Min, _Max;
};

struct _Min_max_d {
  double _Min, _Max;
};

struct _Min_max_p {
  void *_Min, *_Max;
};
}
