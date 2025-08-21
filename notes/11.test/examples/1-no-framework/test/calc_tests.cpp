#include "calc.h"
#include <cstdlib>

void test_add() {
  Calc calculator;
  if (calculator.add(2, 2) != 4) {
    std::exit(1);
  }
}

void test_times() {
  Calc calculator;
  if (calculator.times(8, 7) != 56) {
    std::exit(1);
  }
}
