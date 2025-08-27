#pragma once
#include "gmock/gmock.h"

class RandomNumberGeneratorMock : public RandomNumberGenerator {
public:
  MOCK_METHOD(int, uniform, (), (override));
  /* The general expression for the mock method
   * MOCK_METHOD(
   *    <return type>, <method name>,
   *    (<argument list>), (<keywords>)
   * );
   */
};
