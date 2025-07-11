#include <iostream>

int main() {
#if defined(VARIABLE)
  std::cout << "VARIABLE is defined." << std::endl;
#endif
#if (NUMBER > 0 + 0 + 7)
  std::cout << "NUMBER is greater than 7." << std::endl;
#endif
}
