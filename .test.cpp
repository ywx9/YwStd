// #include "ywstd"

template<typename T> using add_extent = T[2];
int main() {
  // testing <thread>
  using type = int[2][16];
  constexpr type a{};
  static_assert(sizeof(a) == 4 * 2 * 16);
  static_assert(sizeof(a[0]) == 4 * 16);
  static_assert(sizeof(a[0]) == 4 * 2);

  using type2 = add_extent<int[16]>;
  constexpr type2 b{};
  static_assert(sizeof(b) == 4 * 2 * 16);
  static_assert(sizeof(b[0]) == 4 * 16);
  static_assert(sizeof(b[0]) == 4 * 2);
}
