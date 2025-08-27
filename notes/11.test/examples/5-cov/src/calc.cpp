#include "calc.h"
#include "rng.h"

Calc::Calc(RandomNumberGenerator *rng) : rng_(rng) {}
int Calc::add(int a, int b) { return a + b; }
int Calc::times(int a, int b) { return a * b; }
int Calc::add_random(int a) { return a + rng_->uniform(); }
