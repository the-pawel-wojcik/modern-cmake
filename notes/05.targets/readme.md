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
