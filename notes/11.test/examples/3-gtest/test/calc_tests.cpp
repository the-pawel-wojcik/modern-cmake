#include "calc.h"
#include <gtest/gtest.h>

class CalcTestSuite : public ::testing::Test {
protected:
  Calc calculator;
};

TEST_F(CalcTestSuite, add) { EXPECT_EQ(5, calculator.add(3, 2)); }

TEST_F(CalcTestSuite, times) { EXPECT_EQ(6, calculator.times(3, 2)); }
