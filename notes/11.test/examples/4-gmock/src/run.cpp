#include "calc.h"
#include "rng_mt19937.h"
#include <iostream>

int run() {
  RandomNumberGeneratorMt19937 *rng = new RandomNumberGeneratorMt19937();
  Calc calculator(rng);
  std::cout << "Random dice throw + 1 = " << calculator.add_random(1) << "."
            << std::endl;
  delete rng;
  return 0;
}
