#include <iostream>
int a() {
  std::cout << "Calling a() from one.cpp" << std::endl;
  return 0;
}

void duplicated() {
  std::cout << "Calling duplicated() from one.cpp" << std::endl;
}
