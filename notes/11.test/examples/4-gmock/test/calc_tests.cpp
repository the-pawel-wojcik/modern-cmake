#include "calc.h"
#include "mocks/rng_mock.h"
#include <gtest/gtest.h>

class CalcTestSuite : public ::testing::Test {
protected:
  RandomNumberGeneratorMock rng_mock_;
  Calc calculator{&rng_mock_};
};

TEST_F(CalcTestSuite, add) { EXPECT_EQ(5, calculator.add(3, 2)); }

TEST_F(CalcTestSuite, times) { EXPECT_EQ(6, calculator.times(3, 2)); }

TEST_F(CalcTestSuite, random_add) {
  EXPECT_CALL(rng_mock_, uniform()).Times(1).WillOnce(::testing::Return(3));
  EXPECT_EQ(4, calculator.add_random(1));
}
