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

## Position Independent Code
Dependencies of shared libraries need to be flagged extra
```cmake
set_target_properties(dependency PROPERTIES POSITION_INDEPENDENT_CODE ON)
```

## One Definition Rule (ODR)
Within the scope of a single translation a symbol is required to be declared
exactly once. Symbols cannot be defined more than once.

ODR is the reason behind the "safe guards" `#ifdef` in the header files.

## Linking unused static library objects
The compiler-depended version would look like this
```cmake
target_link_options(tgt INTERFACE
    -Wl,--whole-archive $<TARGET_FILE:lib1> -Wl,--no-whole-archive
)
```
while the compiler-independed one looks like this
```cmake
target_link_libraries(tgt INTERFACE "$<LINK_LIBRARY:WHOLE_ARCHIVE,lib1>")
```
