# Defining imported targets
function(define_imported_target library headers)
    add_library(zlib::zlib UNKNOWN IMPORTED)
    set_target_properties(
        zlib::zlib PROPERTIES
        IMPORTED_LOCATION ${library}
        INTERFACE_INCLUDE_DIRECTORIES ${headers}
    )
    set(zlib_FOUND 1 CACHE INTERNAL "zlib found" FORCE)
    set(zlib_LIBRARIES ${libraries} CACHE STRING "zlib libraries path" FORCE)
    set(zlib_INCLUDES ${headers} CACHE STRING "zlib headers path" FORCE)
    mark_as_advanced(FORCE zlib_LIBRARIES)
    mark_as_advanced(FORCE zlib_INCLUDES)
endfunction()

# Case 1. Paths are already provided (either by the user or by the previous
# config runs).
if(zlib_LIBRARIES AND zlib_INCLUDES)
    define_imported_target("${zlib_LIBRARIES}" "${zlib_INCLUDES}")
    return()
endif()

find_library(
    zlib_LIBRARY_PATH
    NAMES zlib z
)

find_path(
    zlib_HEADER_PATH
    NAMES zlib.h
)

# The commented-out checks below, error handling, and setting variables is
# handled by the module Find PackageHandleStandardArgs

# if (${zlib_LIBRARY_PATH-NOTFOUND} EQUAL 1)
#     message("Zlib was not found")
# else()
#     message("Zlib was found in ${zlib_LIBRARY_PATH}")
# endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    zlib DEFAULT_MSG zlib_LIBRARY_PATH zlib_HEADER_PATH
)

if (zlib_FOUND) 
    define_imported_target("${zlib_LIBRARY_PATH}" "${zlib_HEADER_PATH}")
elseif(zlib_FIND_REQUIRED)
    message(FATAL_ERROR "Required zlib library not found.")
endif()
