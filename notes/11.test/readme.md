# 11. Testing Frameworks

## Build and test mode
```bash
ctest --build-and-test SOURCE BUILD --build-generator GENERATOR\
    [OPTIONS...] \
    [--build-options BUILD_OPTIONS...] \
    [--test-command TEST_COMMAND [ARGS...]]
```
Nothing will run unless the `TEST_COMMAND` is set to `ctest`, e.g.,
```bash
ctest \
    --build-and-test src build \
    --build--generator "Unix Makefiles" \
    --test-command ctest
```

## Test mode
The test are build first. The testing is done after. List available tests with
```bash
ctest -N
# or the long options with an argument
ctest --show-only=json-v1
```
The `-R`, `-RE`, `-L`, and `-LE` enable filtering the tests by their name or
label. The `-I` or `--test-information` filter allows to pick test by their
number, e.g.,
```bash
ctest -I ,0,,3,8,2  # run only 3rd, 8th, and 2nd tests
```

For a better test isolation use
```bash
ctest --force-new-ctest-process
ctest --schedule-random
```

For an easier inspection of the failing tests use flags
```bash
ctest --output-on-failure
ctest --rerun-failed
```

`ctest` exits with success when no tests are found. In CI/CD it's usually an
error. Make `ctest` report no tests as an errow with
```bash
ctest --no-tests=error
# ctest --no-tests=ignore # the opposite result
```

Flaky test may be debugged with the repeated runs
```bash
ctest -repeat until-fail:100
ctest -repeat until-pass:100
ctest -repeat after-timeout:100
```

Verbosity of the output may be increased with
```bash
ctest --verbose  # the same as -V
ctest --extra-verbose  # the same as -VV
ctest --debug
```
The `ctest` output may also be suppressed with
```bash
ctest --quiet  # the same as -Q
```

The tests output is saved by default in `Testing/Temporary`. Redirect it with
```bash
ctest --output-log LOG_FILE  # the same as -O LOG_FILE
```

On multi-configuration generators, pick the tested configuration with
```bash
ctest --build-config CONFIG  # -C CONFIG
```

Run in parallel with
```bash
ctest --parallel N  # -j N
```
avoid exceeding a selected CPU load
```bash
ctest --test-load LOAD
```
