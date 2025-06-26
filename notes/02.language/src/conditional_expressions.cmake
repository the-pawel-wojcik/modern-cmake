cmake_minimum_required(VERSION 3.30)

set(HiddenVar "SurelyNotTrue")
set(Number "HiddenVar")

if("Number")
    message("Quoted string: \"Number\" is true.")
else()
    message("Quoted string: \"Number\" is  false.")
endif()

if("${Number}")
    message("Quoted variable expansion: \"HiddenVar\" is true.")
else()
    message("Quoted variable expansion: \"HiddenVar\" is false.")
endif()

if(${Number})
    message("Unquoted variable expansion: SurelyNotTrue is in fact true.")
else()
    message("Unquoted variable expansion: SurelyNotTrue is false.")
endif()

if(Number)
    message("Unquoted variable name: SurelyNotTrue is in fact true.")
else()
    message("Unquoted variable name: SurelyNotTrue is false.")
endif()
