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
environmental variables used by CMake.

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

## Scopes
Nested scopes get a copy of the outer scope's variables. Any modifications apply
to local copy. Upon exit the local variables are lost and the outer scope's
variables are restored. Two mechanisms can change that
1) Use the `PROPAGATE` keyword in the `block` command 
```cmake
block(PROPAGATE var_name...)
```
2) Use the `PARENT_SCOPE` modifier when setting or unsetting variables
```cmake
set(var_name "value" PARENT_SCOPE)
unset(var_name PARENT_SCOPE)
```
These commands don't change the local-scope copies of the variables.

The `if` command does NOT start a new nested scope.

## Lists
Strings with semicolons are the CMake's representation of lists
```cmake
set(five_primes 2 3 5 7 11)
set(five_primes 2;3;5;7;11)  # both are equivalent
```

## Conditional statements
Strings evaluate to the logical true only if they take one of the five
(case-insensitive) values: `ON`, `Y`, `YES`, `TRUE`, non-zero-number.

The logical `NOT`, `OR`, and `AND` are supported. Parenthesis are also supported
```cmake
if((NOT condition0) AND (condition1 OR condition2))
```

Using variables in the conditional expansion has a fairly long set of rules. The
most similar effect to `C++` is achieved using quoted variables expansion
```cmake
if("${variable_name}")
```
if this case the variable is expanded in the string interpolation and the string
is passed to go through the conditional checks.

A legacy behavior expands unquoted variables even outside of `${}`.
```cmake
set(VarName ON)
if(VarName)  # VarName is expanded to ON
```

Another feature of CMake is that variables in the conditional expressions
experience the cycling expansion
```cmake
set(HiddenVar "SurelyNotTrue")
set(Number "HiddenVar")
if(Number)  # the condition will evaluate to "SurelyNotTrue"
```
According to the rules above, "SurelyNotTrue" is not one of the five values that
result if the logical true, therefore the condition must evaluate to the logical
false. But here comes another CMake's exception:

An expansion of an unquoted variable evaluates to the logical false only if the
following four cases:
1. It is one of the six case-insensitive strings `OFF`, `NO`, `N`, `NOTFOUND`,
   `FALSE`, `IGNORE`.
2. It is a string terminated with `-NOTFOUND`.
3. It is an empty string.
4. It is a zero.

The string `SurelyNotTrue` was produced through an expansion of an unquoted
variable and does not match any of the above false-equivalent strings, therefore
is evaluates to the logical true.

Finally, one may check if a variable is defined with the DEFINE keyword
```cmake
if(DEFINED variable_name)
if(DEFINED ENV{variable_name})
if(DEFINED CACHE{variable_name})
```

### Comparison operators
The keywords `EQUAL`, `LESS`, `LESS_EQUAL`, `GREATER`, `GREATER_EQUAL` allow to
compare numbers. Prepending `VERSION_` prefix to each of the above compares
version numbers. Prepending the `STR` prefix (no underscore) allows for a
lexicographical comparisons. Regex match is allowed in the form
```cmake
<variable|string> MATCHES regex
```
groups are assigned to `CMAKE_MATCH_n` variables.

Finally, there is a `PATH_EQUAL` that collapses multiple `/` symbols.

### Simple checks
```cmake
if(<string|variable> IN_LIST my_list)
if(COMMAND <command name>)  # check if <command name> exists and can be called
if(POLICY <policy id>)
if(TEST <test name>)
if(TARGET <target name>)
if(EXISTS <abs-path-or-filepath>)
if(<file> IS_NEWER_THAN <file>)  # true also if any does not exist
if(IS_DIRECTORY <path>)
if(IS_SYMLINK <path>)
if(IS_ABSOLUTE <path>)
```

## Loops
Everything in CMake is a command. The commands for loops available in CMake are
the `while(<condition>)`, `endwhile()` pair, for a while loop.

The second type of loops provided by CMake are the `foreach(...)`,
`endforeach()` pairs. There are many flavors of the `foreach` command. The most
valuable one is likely the following
```cmake
foreach(var IN LISTS myList0 myList1 ITEMS item0 item1 item2)
```

The loops don't create local scope, yet, the loop variables of `foreach` are
restricted to the local scope of the loop.

## New Commands
Users may define two types of commands: functions and macros. Inside the bodies
of these custom commands CMake provides the following variables
```cmake
ARGC  # number of arguments passed to the command
ARGV  # a list of arguments passed to the command
ARGV<n>  # the nth argument passed to the command
ARGN  # a list of anonymous arguments passed to the command after the last
      # named argument
```

Functions create local scope. In that scope, CMake provides the following
variables
```cmake
CMAKE_CURRENT_FUNCTION
CMAKE_CURRENT_FUNCTION_LIST_DIR
CMAKE_CURRENT_FUNCTION_LIST_FILE
CMAKE_CURRENT_FUNCTION_LIST_LINE
```

## Popular Commands
### `message`
User may provide as the first argument to the command the MODE, which would be
one of: `FATAL_ERROR`, `SEND_ERROR`, `WARNING`, `AUTHOR_WARNING`, `DEPRECATION`,
`NOTICE` (default), `STATUS` (recommended for messages to the user), `VERBOSE`,
`DEBUG`, `TRACE`.

The `DEPRECATION` type of message behaves different depending on which of
`CMAKE_ERROR_DEPRECATION` or `CMAKE_WARN_DEPRECATION` variables is set.

The `CMAKE_MESSAGE_CONTEX` and `CMAKE_MESSAGE_INDENT` lists add extra level of
control in printing. The contex is printed when the cmake executable receives
the `--log-contex` flag.

### `include`
Run cmake code from external file in the current scope.
```cmake
include(<file|module> [OPTIONAL] [RESULT_VARIABLE <var>])
```
Specifying `OPTIONAL` will stop CMake from raising an error if the file is not
found. The `RESULT_VARIABLE` says if the include was a sucess, if so, the
`<var>` will store the absolute path to the included file, otherwise `<var>`
will be set to `NOTFOUND`.

`<file>` should be a full file name. Relative paths will be resolved with
respect to current working directory, not the file itself. Fix it with
`${CMAKE_CURRENT_LIST_DIR}/<file>`.

In case of `<module>`, the `<module>.cmake` file will be searched.
`CMAKE_MODULE_PATH` will be searched first.
