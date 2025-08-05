# Dynamically linked duplicated symbols
Build two shared libraries with duplicated symbols. The main defines these
symbols using the `extern` keyword. The outcome is such that depending on the
order of linking, different symbol is called.

Use namespaces to avoid these problem.
