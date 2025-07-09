cmake_minimum_required(VERSION 3.30)
project(Printer LANGUAGES CXX)

set(myvar "small text")
set(myvar2 "small text >")
set(myvar3 "small > text")

file(GENERATE OUTPUT nested CONTENT "
    1. $<UPPER_CASE:${myvar}>
    2. $<UPPER_CASE:${myvar2}>
    2. $<UPPER_CASE:${myvar3}>
")

file(GENERATE OUTPUT boolean CONTENT "
    1. $<0:TRUE>  # prints nothing
    2. $<0:TRUE,FALSE>  # likely a mistake
    3. $<1:True,False>   # also, a likely mistake
    4. $<IF:0,True,False>   # most likely works as intended
    5. $<IF:0,True,>   # most likely works as intended
")
