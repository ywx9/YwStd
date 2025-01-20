#include "ywstd"

int test_any = [] {
  std::cout << "** starting `std::any` test" << std::endl;

  std::cout << std::boolalpha;

  // any type
  std::any a = 1;
  std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
  a = 3.14;
  std::cout << a.type().name() << ": " << std::any_cast<double>(a) << '\n';
  a = true;
  std::cout << a.type().name() << ": " << std::any_cast<bool>(a) << '\n';

  // bad cast
  try {
    a = 1;
    std::cout << std::any_cast<float>(a) << '\n';
  } catch (const std::bad_any_cast& e) { std::cout << e.what() << '\n'; }

  // has value
  a = 2;
  if (a.has_value()) std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';

  // reset
  a.reset();
  if (!a.has_value()) std::cout << "no value\n";

  // pointer to contained data
  a = 3;
  int* i = std::any_cast<int>(&a);
  std::cout << *i << '\n';

  std::cout << "** ending `std::any` test" << std::endl;
  return 0;
}();

int test_array = [] {
  std::setlocale(LC_ALL, "en_US.UTF-8");
  std::cout << "** starting `std::array` test" << std::endl;
  std::array<int, 3> a1{{1, 2, 3}}; // Double-braces required in C++11 prior to
                                    // the CWG 1270 revision (not needed in C++11
                                    // after the revision and in C++14 and beyond)

  std::array<int, 3> a2 = {1, 2, 3}; // Double braces never required after =

  // Container operations are supported
  std::sort(a1.begin(), a1.end());
  std::ranges::reverse_copy(a2, std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';

  // Ranged for loop is supported
  std::array<std::string, 3> a3{"E", "ﾆあいうえお", "\u03C0"};
  for (const auto& s : a3) std::cout << s << ' ';
  std::cout << '\n';

  // Deduction guide for array creation (since C++17)
  [[maybe_unused]] std::array a4{3.0, 1.0, 4.0}; // std::array<double, 3>
  // Behavior of unspecified elements is the same as with built-in arrays
  [[maybe_unused]] std::array<int, 2> a5;   // No list init, a5[0] and a5[1] are default initialized
  [[maybe_unused]] std::array<int, 2> a6{}; // List init, both elements are value initialized, a6[0] = a6[1] = 0
  [[maybe_unused]] std::array<int, 2> a7{1}; // List init, unspecified element is value initialized, a7[0] = 1, a7[1] = 0

  std::cout << "** ending `std::array` test" << std::endl;
  return 0;
}();

std::atomic_int atomic_test_acnt;
int atomic_test_cnt;

int test_atomic = [] {
  std::cout << "** starting `std::atomic` test" << std::endl;
  auto f = [] {
    for (auto n{10000}; n; --n) ++atomic_test_acnt, ++atomic_test_cnt;
  };
  {
    std::vector<std::jthread> pool;
    for (int n = 0; n < 10; ++n) pool.emplace_back(f);
  }
  std::cout << "The atomic counter is " << atomic_test_acnt << '\n' << "The non-atomic counter is " << atomic_test_cnt << '\n';
  std::cout << "** ending `std::atomic` test" << std::endl;
  return 0;
}();

int main() {}
