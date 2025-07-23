# 7. Compiling C++ Sources with CMake

Commands for configuration of compilation
```cmake
target_compile_features()
target_sources()
target_include_directories()  # set up preprocessor's "include path"
target_compile_definitions()  # preprocessor's definitions
target_compile_options()  # compiler-specific flags
target_precompile_headers()
```
The arguments look similar
```cmake
target_...(target INTERFACE | PUBLIC | PRIVATE args...)
```
Properties set on targets with these commands will follow the transitive usage
requirements rules. These commands support generator expressions.

## Compiler features
There are many features supported by CMake, but the recommended use is a
"meta-feature" like
```cmake
target_compile_features(ccsd PUBLIC cxx_std_26)
```
This differs from the global `set(CMAKE_CXX_STANDARD 26)` with
`set(CMAKE_CXX_STANDARD_REQUIRED ON)` as it works on a per-target basis.

## Adding sources
The `target_sources` command enables conditional sources
```cmake
add_target(app main.cpp)
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    target_sources(app gui_linux.cpp)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    target_sources(app gui_windows.cpp)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
    target_sources(app gui_macos.cpp)
else()
    message(FATAL_ERROR "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME} unsupported.")
endif()
```

## Providing paths to included files
The preprocessor resolves the c++ include statements
```cpp
#include <path-spec>
#include "path-spec"
```
The `<path>` files are typically search in the standard include directories,
while the `"path"` files are searched in the current directory. To specify the
list of of directories where the preprocessor should search for header files,
CMake provides the `target_include_directories` command
```cmake
target_include_directories(target [SYSTEM] [AFTER|BEFORE]
    INTERFACE | PUBLIC | PRIVATE item...
    ...
)
```
the provided paths will be used by adding them as the arguments of the `-I` flag
to the preprocessor calls.

The `target_include_directories` command modifies the `INCLUDE_DIRECTORIES`
property of the target. The `AFTER` and `BEFORE` keywords specify if the new
paths are prepended or appended. It's still up to the compiler to chose if these
manually specified directories will be checked before or after the default ones
(usually it's before).

The `SYSTEM` keyword specifies that the directories should be treated as
standard system directories. Many compiles use the `-isystem` flag for this
purpose.

## Optimalizations
The compiler optimizations are configured with the compiler flags
```cmake
target_compile_options(target [BEFORE]
    PRIVATE | PUBLIC | INTERFACE flag...
    ...
)
```
The `BEFORE` keyword will prepend the options to the flag list, as sometimes the
order matters.

Levels of optimization:
- O0, no optimizations
- O2, full optimization
- O3, full optimization with more aggressive inlining and loop vectorization
- Ofast, -O3 plus optimization's that don't comply with the standard, might
  break precision as it uses `-ffinite-math` and `-ffast-math`.

CMake has a few pre-configurations saved. See `CMAKE_CXX_FLAGS_DEBUG`,
`CMAKE_CXX_FLAGS_RELEASE`, and other `CMAKE_<LANG>_FLAGS_<CONFIG>` global
variables. The per-target granular control is recommended over the global
settings.

The `-On` flags are "meta-flags" that set a series of more fine-tuned
optimization options. These fine-tuned optimization options can be controlled
with the `-f<option>` and `-fno<option>` for activating and deactivating,
respectively, the desired optimization. These more granular flags may depend on
the compiler used, e.g.,
 - `-finline-functions-called-once`: GCC
 - `-finline-functions`: GCC and Clang
 - `-finline-hint-functions`: Clang
 - `-floop-unroll`: GCC
 - `-funroll-loops`: Clang

### Unity Builds
Enable unity builds with
```sh
cmake -D CMAKE_UNITY_BUILD:BOOL=ON
```
If parts of your code break with unity builds, disable them with
```cmake
set_target_properties(target... PROPERTIES UNITY_BUILD false)
```

## Debugging
### Compiler flags
The compiler flags `-Wall` and `-Wextra` will produces warnings that are worth
addressing right away. The next level is `-Wpedantic` which flags non-standard
use of C or C++. Setting `-Werror` turns warnings into errors; this flags is
recommended for development of public libraries. Read the manual of your
compiler to learn about the remaining flags.

### Compilation intermediates
Use the `-save-temps=obj` flag to save the output of preprocessor (`<build
tree>/CMakeFiles/<target>.dir/<source>.ii`) and the output of the linguistic
analysis stage to a file (`the/same/<source>.s`).

### Precise include paths
The `-H` flag lists the included paths
```cmake
target_compile_options(target PRIVATE -H)
```

### Debug symbols
CMake sets different default flags for different builds, e.g.,
`CMAKE_CXX_FLAGS_DEBUG` contains the `-g` flag, which includes the debug symbols
in the final executable, while `CMAKE_CXX_FLAGS_RELEASE` would define `-DNDEBUG`
variable, which is used in macros like `assert` from `assert.h`, which some
programs use to remove the parts of its functionality that is designed for debug
purposes.
