#include "calc.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("add", "[calc]") {
  Calc calculator;
  CHECK(calculator.add(2, 2) == 4);
}

TEST_CASE("times", "[calc]") {
  Calc calculator;
  CHECK(calculator.times(8, 7) == 56);
}
