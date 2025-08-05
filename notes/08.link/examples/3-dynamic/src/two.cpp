#include <iostream>

[[nodiscard]] int b() {
  std::cout << "Calling b() from two.cpp" << std::endl;
  return 0;
}

void duplicated() {
  std::cout << "Calling duplicated() from two.cpp" << std::endl;
}
