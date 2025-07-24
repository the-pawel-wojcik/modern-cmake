# 8. Linking Executables and Libraries
## Shared libraries
By default cmake produces static libraries (`.a`, or `.lib` on Windows)
```cmake
add_libray(name [STATIC] source...)
```
if the configuration is globally changed to shared, with
```cmake
set(BUILD_SHARED_LIBS ON)
```
then the optional `STATIC` keyword enables creation of a static library.
