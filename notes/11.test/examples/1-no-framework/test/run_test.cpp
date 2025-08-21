#include <iostream>
#include <sstream>
#include <string>

int run();

void test_run() {
  std::string expected{"1 + 2 = 3\n3 * 4 = 9\n"};
  std::stringstream buffer;
  // redirect cout
  auto prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
  run();
  auto output = buffer.str();
  // restore original buffer
  std::cout.rdbuf(prevcoutbuf);
  if (expected != output) {
    std::cout << "Expected output:\n" << expected << std::endl;
    std::cout << "Got output:\n" << output << std::endl;
    exit(1);
  }
}
