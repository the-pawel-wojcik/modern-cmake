#include "rng_mt19937.h"
#include <random>

int RandomNumberGeneratorMt19937::uniform() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 6);
  return distrib(gen);
}
