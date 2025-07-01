# 4. Setting Up Your First CMake Project

The `cmake_minimum_required` command goes first.

The `project` command goes right after. The `<project name>` is required all
other fields are optional
```cmake
project(<project name>
    VERSION major[.minor[.patch[.tweak]]]
    DESCRIPTION <doc string>
    HOMEPAGE_URL <url>
    LANGUAGES <language name>...
)
```
Calling the `project` command populates following variables `PROJECT_NAME`,
`CMAKE_PROJECT_NAME` (only in the top-level `CMakeLists.txt`),
`PROJECT_IS_TOP_LEVEL`, `<project name>_IS_TOP_LEVEL`, `PROJECT_SOURCE_DIR`,
`<project name>_SOURCE_DIR`, `PROJECT_BINARY_DIR`, `<project name>_BINARY_DIR`.

Simiarily, specifying the other argumens will set additional variables.

## Cross compilation
Set the `CMAKE_SYSTEM_NAME` and `CMAKE_SYSTEM_VERSION` to the desired system
(target system). The machine where the compilation takes place is called host,
and uses the corresponding variables containing the `HOST` string.
