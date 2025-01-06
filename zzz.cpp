#include "ywstd"

int main() {
  // Test std::sort
  std::vector<int> vec = {5, 3, 1, 4, 2};
  std::sort(vec.begin(), vec.end());
  std::cout << "Sorted vector: ";
  for (int n : vec) { std::cout << n << " "; }
  std::cout << std::endl;

  // Test std::find
  auto it = std::find(vec.begin(), vec.end(), 3);
  if (it != vec.end()) {
    std::cout << "Element 3 found at position: " << std::distance(vec.begin(), it) << std::endl;
  } else {
    std::cout << "Element 3 not found" << std::endl;
  }

  // Test std::reverse
  std::reverse(vec.begin(), vec.end());
  std::cout << "Reversed vector: ";
  for (auto n : vec) { std::cout << n << " "; }
  std::cout << std::endl;

  // Test std::accumulate
  auto sum = std::accumulate(vec.begin(), vec.end(), 0);
  std::cout << "Sum of elements: " << sum << std::endl;

  // Test std::count
  auto count = std::count(vec.begin(), vec.end(), 3);
  std::cout << "Count of element 3: " << count << std::endl;

  return 0;
}
