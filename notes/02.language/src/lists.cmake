cmake_minimum_required(VERSION 3.30)
# set(five_primes 2 3 5 7 11)
set(five_primes 2;3;5;7;11)  # both are equivalent
message("Unquoted (message takes many arguments): "${five_primes})
message("Quoted (message takes only one argument): ${five_primes}")

list(LENGTH five_primes len_five_primes)
message("Length of the five_primes list: ${len_five_primes}.")

list(JOIN five_primes " < " glued_primes)
message("Glued primes: ${glued_primes}.")
