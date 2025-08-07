# 9. Managing Dependencies in CMake
## Using packages already installed on the system
CMake's `find_package` is the recommended command
```cmake
find_package(name [version] [EXACT] [QUIET] [REQUIRED])
```
if the package is found the variables such as `name_INCLUDES` or
`name_LIBRARIES` are set and possibly event imported targets like
`name::name` become accessible.

The `find_package` would also work with find-modules and config-modules.

The config-modules are part of packages offering easy integration with other
CMake projects.

If a package does not provide a config-module, one may write a find-module which
would live separate from the wanted package, but it would enable the integration
of the wanted package into a CMake project.

### Writing a custom find module
A find-module searches for a package files and sets appropriate variables and
targets. A find-module would be called `FindPackageName.cmake`.

When writing a find-module one should complete the following duties
1. If `find_package` call sets the `REQUIRED` keyword, CMake sets the variable
   `PkgName_FIND_REQUIRED` to `1`. The find module should call
   `message(FATAL_ERROR)` if the package is not found.
2. Similarly `PkgName_FIND_QUIETLY` is set to `1` for the `QUIET` keyword, and
   `PkgName_FIND_VERSION` is set to the value of `version` when given.
The above duties may be handled with the `find_package_handle_standard_args`
command from the `FindPackageHandleStandardArgs` module.

The `find_library` helper command, searches for libraries in various paths
```cmake
find_library(
    <ZLIB_LIBRARY_PATH> # output variable
    NAMES libz zlib z  # names of the library
    PATHS
        ${_DIR_LIBZ}/lib/${CMAKE_LIBRARY_ARCHITECTURE}
        $ENV{HOME}/.local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
        /usr/lib
        /lib
    [NO_DEFAULT_PATH]
)
```
if the library is not found the `<ZLIB_LIBRARY_PATH>-NOTFOUND` is set to `1`.

The `find_path` command does the same job for finding header files. The only
difference is that the `find_library` automatically adds the system-specific
extensions, while `find_path` expects a complete name of the file.

### Debugging the `find_package` process
Call CMake with an additional flag
```bash
cmake -S src -B build --debug-find-pkg=PACKAGE_NAME
```

## Using dependencies unavailable at the system
The go-to options is the `FetchContent` module, a user-friendly wrapper around
the `ExternalProject` module. `FetchContent` works at configuration stage, while
`ExternalProject` works at the build stage.

### `FetchContent`
Three steps:
1. `include(FetchContent)`.
2. `FetchContent_Declare()`.
3. `FetchContent_MakeAvailable()`.
