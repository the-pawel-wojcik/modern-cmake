#include <iostream>

#define str(s) #s
#define xstr(s) str(s)

int main() {
#if defined(SHA)
  std::cout << "GIT commit: " << xstr(SHA) << "." << std::endl;
#endif
}
