#pragma once

#include "rng.h"

class Calc {
  RandomNumberGenerator *rng_;

public:
  Calc(RandomNumberGenerator *rng);
  int add(int a, int b);
  int times(int a, int b);
  int add_random(int a);
};
