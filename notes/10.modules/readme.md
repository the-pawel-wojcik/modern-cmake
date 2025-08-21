# 10. Using c++20 modules
Pretty simple
```cmake
add_library(math)
target_sources(math PUBLIC FILE_SET CXX_MODULES FILES math.cxx)
```
GNU Make 4.4.1 seems to lack module support, and cmake 4.0.3 says it.
```bash
cmake -S src -B build -G Ninja
```
