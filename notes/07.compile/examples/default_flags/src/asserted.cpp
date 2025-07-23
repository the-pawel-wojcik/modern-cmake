#include <assert.h>
#include <iostream>

int main() {
  assert(false);
  std::cout << "Code execution did not stop at assert(false)." << std::endl;
  return 0;
}
