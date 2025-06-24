# 2. The CMake Language

Run the examples from `src` with
```sh
cmake -P SCRIPT_NAME.cmake
```

Command names are case-insensitive but arguments are case-sensitive.

## Accessing variables
```cmake
${var}  # accesses NORMAL or CACHED variable
$ENV{var}  # accesses ENVIRONMENTAL variables
$CACHE{var}  # accesses CACHED variables
```
[List](https://cmake.org/cmake/help/latest/manual/cmake-env-variables.7.html) of
environmental variables used by CMake 

## Defining variables and assigning values
Normal variables are defined with the `set` function
```cmake
set(variable_name value)
```

Cache variables have longer syntax
```cmake
set(variable_name value CACHE TYPE "docstring" [FORCE])  # FORCE is optional
```
The `TYPE` has to be one of `BOOL`, `FILEPATH`, `PATH`, `STRING`, or `INTERNAL`.
For `STRING` one may specify an extra help for GUI 
```cmake
set_property(CACHE variable_name STRINGS "option 1" "option 2" "...")
```
`INTERNAL` automatically triggers `FORCE`.

The cache variables are similar to the environment variables, in the sense that
their modifications do not escape the current script. Except for two cases:
1) if the cached variable is unset in the CMakeCache.txt
2) if the `FORCE` keyword is present.
In these two cases, the cache variable is saved to the cache and persists.
