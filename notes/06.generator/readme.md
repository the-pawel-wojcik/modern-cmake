# 6. Using Generator Expressions

## The syntax
```cmake
$<EXPRESSION:arg,...>
```
args can use nesting, both generator expressions and variables are allowed
```cmake
$<EXPRESSION:$<GENERATOR:expression>,$ENV{PATH}>
```

### Conditional Logic
Conditional logic is supported with `IF`. There are two syntaxes for the if
clause. The better one always takes three arguments
```cmake
$<IF:condition,do_if_true,do_if_false>
```
It's common to do nothing if the condition is not satisfied
```cmake
$<IF:condition,do_if_true,>
```
for which there is an un-recommended shortcut
```cmake
$<condition:do_if_true>
```

Booleans are 0 and 1. Everything else is a string. The expressions used in
conditional expressions must evaluate to Booleans.

There are four logical operators
```cmake
$<NOT:arg>
$<AND:arg,...>
$<OR:arg,...>
$<BOOL:string>
```
The conversion to a boolean value returns true, `1`, if none of the following
three conditions are met:
1. The string is empty.
2. The string is one of the seven (case-insensitive) keys: `0`, `FALSE`, `OFF`,
   `N`, `NO`, `NOTFOUND`, `IGNORE`.
3. The string ends with (case-insensitive) `-NOTFOUND`.

The most popular comparisons are
```cmake
$<STREQUAL:left,right>  # case-insensitive
$<EQUAL:left,right>  # converts string to a number
$<IN_LIST:token,list>
$<VERSION_{EQUAL,LESS,GREATER,LESS_EQUAL,GREATER_EQUAL}:v1,v2>
$<PATH_EQUAL:left,right>
```

There are also queries which return boleans
```cmake
$<TARGET_EXISTS:arg>
```

### Querying and transforming
For strings
```cmake
$<LOWER_CASE:string>, $<UPPER_CASE:string>
```

For lists
```cmake
$<IN_LIST:token,list>
$<JOIN,list,delimiter>
$<REMOVE_DUPLICATES:list>
$<FILTER:list,INCLUDE|EXCLUDE,regex>
```
Since 3.27 a lot more operators are available
```cmake
$<LIST:OPERATION>
```
where `OPERATION` may be one of the following `LENGTH`, `GET`, `SUBLIST`,
`FIND`, `JOIN`, `APPEND`, `PREPEND`, `INSERT`, `POP_BACK`, `POP_FRONT`,
`REMOVE_ITEM`, `REMOVE_AT`, `REMOVE_DUPLICATES`, `FILER`, `TRANSFORM`,
`REVERSE`, `SORT`.

Path transformations are also possible since 3.24, with the syntax
`$<PATH:...>`.

## The Usage
Check the build type with `$<CONFIG>`, returns `Debug`, `Release`, or other, or
with `$<CONFIG:configs>` which returns true if current build type is part of the
configs (case-insensitive) strings.

There are the similarly acting `$<PLATFORM_ID>` and `$<PLATFORM_ID:platforms>`.

Example, pick different flags depending on build
```cmake
target_compile_definitions(
    target PRIVATE 
    $<IF:$<CONFIG:Debug>,Test,Production>
)
```

Working with specific compilers and their versions is supported by various
generator expressions containing `COMPILER_ID` or `COMPILER_VERSION` strings, as
well as, the `$<COMPILE_LANGUAGE>` and `$<LINK_LANGUAGE>` generator expressions.
```cmake
target_compile_options(target
    PRIVATE $<IF:$<COMPILE_LANGUAGE:CXX>,-fno-exceptions,>
)
target_compile_definitions(target PRIVATE
    $<IF:$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang>,CXX_CLANG,>
    $<IF:$<COMPILE_LANG_AND_ID:CXX,Intel>,CXX_Intel,>
    $<IF:$<COMPILE_LANG_AND_ID:C,Clang>,C_Clang,>
)
```

There are any target-related generator expressions. The `$<TARGET_FILE...>`
generator expressions query pahts of the target artifact. `$<TARGET_...>`
produce existence checks, object files, ... . There are many generator
expressions supporting installs and libraries.

Finally, there are also escape sequences: `$<ANGLE-R>`, `$<COMMA>`,
`$<SEMICOLON>`.

### Testing the generator expressions
Since `message()` command is executed at the configuration-time, the generator
expressions won't work with it. To see the result of the generator expression
there are two tricks. The first one writes to a file
```cmake
file(GENERATE OUTPUT filename CONTENT "$<...>")
```
The second one requires calling a special target from the command line
```cmake
add_custom_target(gendbg COMMAND ${CMAKE_COMMAND} -E echo "$<...>")
```
Even with this two tricks, not all generator expressions may be viewed, as some
of them depend on the target.

## Examples
Add a compiler-specific compile options through an interface library
```cmake
add_library(enable_rtti INTERFACE)
target_compile_options(enable_rtti INTERFACE
    $<IF:$<OR:$<COMPILER_ID:GCC>,$<COMPILER_ID,Clang>>,-rtti,>
)
```
