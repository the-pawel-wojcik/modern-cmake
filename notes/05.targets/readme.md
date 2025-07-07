# 5. Working with Targets
CMake has three commands that create targets
```cmake
add_executable()
add_library()
add_custom_target()
```

Syntax for `add_executable`
```cmake
add_executable(name [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL] [source...])
```
`EXCLUDE_FROM_ALL` disables auto build of the target unless explicitly asked for
with
```sh
cmake --build <build dir> -t <target name>
```
headers can be added with `target_include_directories` or using `FILE_SET` with
`target_sources`. See chapter 7.

The `add_library`'s syntax does not include the GUI commands
```cmake
add_library(name [STATIC|SHARED|MODULE] [EXCLUDE_FROM_ALL] [source...])
```
See chapter 8. for details.

Finally,
```cmake
add_custom_target(name [ALL] [COMMAND command args... ...])
```
`ALL` is the opposite of `EXCLUDE_FROM_ALL` as custom targets are not executed
by default.

## Dependency graph
Use the `add_dependencies` to control the build order of top-level targets or
specify custom targets' dependecies.
```cmake
add_dependencies(target [dependency...])
```

Create a visualization of the dependency graph with
```sh
cd build
cmake --graphviz=test.doc .
```
view the result with `https://dreampuf.github.io/GraphvizOnline`

## Target properties
To view or set target properties use
```cmake
get_target_property(var target property)
set_target_properties(target... PROPERTY
    property_name value
    property_name value ...
)
```
There are also more general, lower-level commands that can acheive similar
results
```cmake
get_property(var TARGET target PROPERTY property_name)
set_property(TARGET target PROPERTY property_name value)
```

A few popular properties `COMPILE_{DEFINITIONS,FEATURES,OPTIONS}`,
`INCLUDE_DIRECTORIES`, `LINK_{DEPENDS,DIRECTORIES,LIBRARIES,OPTIONS}`,
`POSITION_INDEPENDENT_CODE`, `PRECOMPILE_HEADERS`, `SOURCES`.

## Build dependecies
Use
```cmake
target_link_libraries(target
    PUBLIC | PRIVATE | INTERFACE item...
    ...
)
```

If a target depends on two items with conflicting property CMake produces an
error. To resolve such problems a custom property might be used, e.g.,
```cmake
set_target_properties(target PROPERTY INTERFACE_LIBRARY_VERSION 3.13)
```
to propagate the property the property name needs to be appended to one of
`COMPATIBLE_INTERFACE_{BOOL,STRING,NUMBER_{MAX,MIN}}`

## Custom command
A concept similar to custom target
```cmake
add_custom_command(
    OUTPUT output...
    COMMAND command [ARGS args...]
    ...
    [MAIN_DEPENDENCY dependency]
    [DEPNEDS [depends...]]
    [BYPRODUCTS [files...]]
    [IMPLICIT_DEPENDS <lang1> depend1]
    [WORKING_DIRECTORY dir]
    [COMMENT comment]
    [DEPTFILE depfile]
    [JOB_POOL job_pool]
    [VERBATIM] [APPEND] [USES_TERMINAL]
    [COMMAND_EXPAND_LISTS]
)
```
The other format of the `add_custom_command` enables target hooks.
```cmake
add_custom_command(
    TARGET target PRE_BUILD | PRE_LINK | POST_BUILD
    <the rest>
)
```
