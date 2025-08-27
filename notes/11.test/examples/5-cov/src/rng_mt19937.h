#pragma once

#include "rng.h"

// Mersenne Twister pseudo-random generator with uniform distribution
class RandomNumberGeneratorMt19937 : public RandomNumberGenerator {
public:
  int uniform() override;
};
