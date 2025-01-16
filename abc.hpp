/// \file abc.hpp
/// \brief primary header file for `ywstd`
/// \copyright (c) 2022 ywx9.com

// clang-format off
#pragma once

#define nat size_t
#define wchar wchar_t

#if ywstd_is_exported
#else
#define ywstd_export
#endif

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
template<typename T> struct remove_volatile : type_identity<T> {};
template<typename T> struct remove_volatile<volatile T> : type_identity<T> {};
template<typename T> struct remove_cv : remove_const<remove_volatile_t<T>> {};
template<typename T> struct remove_reference : type_identity<T> {};
template<typename T> struct remove_reference<T&> : type_identity<T> {};
template<typename T> struct remove_reference<T&&> : type_identity<T> {};
template<typename T> struct remove_cvref : remove_cv<remove_reference_t<T>> {};
template<typename T> struct remove_pointer : type_identity<T> {};
template<typename T> struct remove_pointer<T*> : type_identity<T> {};
template<typename T> struct remove_pointer<T* const> : type_identity<T> {};
template<typename T> struct remove_pointer<T* volatile> : type_identity<T> {};
template<typename T> struct remove_pointer<T* const volatile> : type_identity<T> {};
template<typename T> struct remove_extent : type_identity<T> {};
template<typename T> struct remove_extent<T[]> : type_identity<T> {};
template<typename T, nat N> struct remove_extent<T[N]> : type_identity<T> {};
template<typename T> struct remove_all_extents : type_identity<T> {};
template<typename T> struct remove_all_extents<T[]> : remove_all_extents<T> {};
template<typename T, nat N> struct remove_all_extents<T[N]> : remove_all_extents<T> {};
template<typename T> using remove_const_t = typename remove_const<T>::type;
template<typename T> using remove_volatile_t = typename remove_volatile<T>::type;
template<typename T> using remove_cv_t = typename remove_cv<T>::type;
template<typename T> using remove_reference_t = typename remove_reference<T>::type;
template<typename T> using remove_cvref_t = typename remove_cvref<T>::type;
template<typename T> using remove_pointer_t = typename remove_pointer<T>::type;
template<typename T> using remove_extent_t = typename remove_extent<T>::type;
template<typename T> using remove_all_extents_t = typename remove_all_extents<T>::type;

template<typename T> struct add_const : type_identity<const T> {};
template<typename T> struct add_volatile : type_identity<volatile T> {};
template<typename T> struct add_cv : type_identity<const volatile T> {};
template<typename T> struct add_lvalue_reference : type_identity<T> {};
template<typename T> requires _valid<T&> struct add_lvalue_reference<T> : type_identity<T&> {};
template<typename T> struct add_rvalue_reference : type_identity<T> {};
template<typename T> requires _valid<T&&> struct add_rvalue_reference<T> : type_identity<T&&> {};
template<typename T> struct add_pointer : type_identity<T> {};
template<typename T> requires _valid<remove_reference_t<T>*> struct add_pointer<T> : type_identity<remove_reference_t<T>*> {};
template<typename T> using add_const_t = typename add_const<T>::type;
template<typename T> using add_volatile_t = typename add_volatile<T>::type;
template<typename T> using add_cv_t = typename add_cv<T>::type;
template<typename T> using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
template<typename T> using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
template<typename T> using add_pointer_t = typename add_pointer<T>::type;

template<typename T> add_rvalue_reference_t<T> declval() noexcept { static_assert(_always_false<T>); }
template<typename T> constexpr remove_reference_t<T>&& move(T&& t) noexcept { return static_cast<remove_reference_t<T>&&>(t); }
template<typename T> constexpr T&& forward(auto&& t) noexcept {
  if constexpr (is_lvalue_reference_v<decltype(t)>) return static_cast<T&&>(t);
  else if constexpr (!is_lvalue_reference_v<T>) return static_cast<T&&>(t);
  else static_assert(_always_false<T>);
}
}
#endif
