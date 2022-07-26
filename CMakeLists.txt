cmake_minimum_required(VERSION 3.5)

project(Calculator LANGUAGES CXX)

#set ouput directories
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )
# set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib )

if(MSVC)
    message("Using VSCode")
endif(MSVC)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("Using gcc/g++")
endif()

set(TARGET_LIST
	${CMAKE_PROJECT_NAME}
)
add_executable(${CMAKE_PROJECT_NAME} main.cpp token.hpp lexer.hpp lexer.cpp)


foreach (target ${TARGET_LIST})
    # set warning levels
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        message("MSVC build")
        target_compile_options(${target} PUBLIC /W4 /permissive- /bigobj)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message("GCC build")
        target_compile_options(${target} PUBLIC -Wall -Wextra -pedantic -Wconversion -pthread)
    endif ()

    # define DEBUG_BUILD
    target_compile_definitions(${target} PUBLIC "$<$<CONFIG:DEBUG>:DEBUG_BUILD>")

    # static runtime library
    set_property(TARGET ${target} PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

    # set binary filenames
    set_target_properties(${target} PROPERTIES OUTPUT_NAME_DEBUG ${target}-debug)
    set_target_properties(${target} PROPERTIES CXX_STANDARD 17)
    set_target_properties(${target} PROPERTIES OUTPUT_NAME_RELWITHDEBINFO ${target}-relwithdebinfo)
    set_target_properties(${target} PROPERTIES OUTPUT_NAME_RELEASE ${target}-release)
    set_target_properties(${target} PROPERTIES OUTPUT_NAME_MINSIZEREL ${target}-minsizerel)

    # if (CMAKE_BUILD_TYPE STREQUAL "Release")
    #     message("Enabling LTO for target ${target}")
    #     set_property(TARGET ${target} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    # else ()
    #     message("Not enabling LTO for target ${target} (not a release build)")
    # endif ()
endforeach ()
