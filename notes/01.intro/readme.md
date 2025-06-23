# 1. First Steps with CMake
Using the `cmake` command

## Creating and modifying the build-system
The first thing to do with a CMake project is to generate the build-system
```sh
cmake -S <source tree> -B <build tree>
```
one of the two flags can be skipped and cmake will infer what the current
directory was meant to represent.
```sh
cmake -B build  # current directory will be used as the source tree
cmake -S ..  # current directory will be used as the build tree
```
**Warning** skipping both arguments results in an in-source build.

Use different generator with the flag `-G <generator>`. Available generators can
be viewed towards the end of the listing produced by
```sh
cmake --help
```

### Cache variables
The cache variables can be populated from a file containing a list of `set`
function calls, passed to cmake with the `-C` flag
```sh
cmake -C <initial cache script> -S <source tree> -B <build tree>
```

The cache variables can be set from the command line with the `-D` flags.
```sh
cmake -D <variable>[:<type>]=<value> -S <source tree> -B <build tree>
```
The optional `<type>` can be `BOOL`, `FILEPATH`, `PATH`, `STRING`, `INTERNAL`.

The most popular cache variable used from the command line is
`CMAKE_BUILD_TYPE`. The popular values of this variable are `Release`, `Debug`,
`MinSizeRel`, or `RelWithDebInfo`, e.g.
```sh
cmake -S . -B build_release -D CMAKE_BUILD_TYPE:STRING=Release
```

Ask for listing of all cached variables with the `-L[A][H]` flag. The optional
flag `A` lists the "advanced" variables too. The optional `H` flag lists the
help strings too. User-set variables will only be displayed if the `:TYPE` was
used when setting the variable.
```sh
cmake -S . -B build -LA
```

Cache variables can be removed with the `-U` flag
```sh
cmake -S . -B build -U <globbing expression>
```
in the globbing expression the `*` symbol represents anything and the `?` symbol
represents any single character.

### Debugging and tracing
```sh
cmake --system-information [save_to_this_file]
```
Pick log level with
```sh
cmake --log-level=<level>
```
where `<level>` can be any of `ERROR`, `WARNING`, `NOTICE`, `STATUS`, `VERBOSE`,
`DEBUG`, `TRACE`. Use the `CMAKE_MESSAGE_LOG_LEVEL` cache variable for the same
purpose.

The `trace` mode
```sh
cmake --trace -S <source> -B <build>  # prints more than you can imagine
```

### Presets
A `CMakePresets.json` file. List available ones with
```sh
cmake --list-presets
```
use one with
```sh
cmake --preset=<preset> -S <source> -B <build>
```

### Cleaning up the build
```sh
rm -fr build
# or 
cmake --fresh -S <source> -B <build>
```

## building
```
cmake --build <build> [<options>] [-- <build-tool-options>]
```

For parallel builds use either
```sh
cmake --build <build> --parallel [<number of jobs>]
cmake --build <build> -j [<number of jobs>]
```
or set the `CMAKE_BUILD_PARALLEL_LEVEL` variable.

Build only selected targets
```sh
cmake --build <build tree> --target <target name>
# short version
cmake --build <build tree> -t <target name>
```
pass as many `-t`s as you wish.

The `clean` target
```sh
cmake --build <build> --target clean
```
removes all build artifacts. There exists an alias that runs `clean` before
regular build
```sh
cmake --build <build> --clean-first
```

For multi-config generators specify the build type with
```sh
cmake --build <build> --config <config name>
```

The verbose mode is useful for debugging
```sh
cmake --build <build tree> --verbose
```
the corresponding cache variable is called `CMAKE_VERBOSE_MAKEFILE`.

## installing
```sh
cmake --install <build tree> [<options>]
```

A popular option is the `install-prefix`
```sh
cmake --install <build tree> --install-prefix <prefix>
```

Another option is `--component <component>`. Set default directory permissions
with the `--default-directory-permissions u=rwx,g=rx,o=rx` flag. Run a script
with `-P <script>`.

## Other files
The presents are stored in `CMakePresets.json`. User-customized presents are
stored in `CMakeUserPresets.json`.
