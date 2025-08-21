#include "calc.h"
#include <iostream>

int run() {
  Calc c;
  std::cout << "1 + 2 = " << c.add(1, 2) << std::endl;
  std::cout << "3 * 4 = " << c.times(3, 4) << std::endl;
  return 0;
}
