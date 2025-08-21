#include <string>

void test_add();
void test_times();
void test_run();

int main(int argc, char **argv) {
  if (argc < 2 || argv[1] == std::string("1")) {
    test_add();
  }
  if (argc < 2 || argv[1] == std::string("2")) {
    test_times();
  }
  if (argc < 2 || argv[1] == std::string("3")) {
    test_run();
  }
}
