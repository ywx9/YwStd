#include "ywstd"

int main() {
  // testing <thread>
  std::thread t([]() {
    std::cout << "Hello, world!" << std::endl;
  });
  t.join();
  return 0;
}
