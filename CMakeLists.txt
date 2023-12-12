cmake_minimum_required(VERSION 3.7...3.27)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(fcomp
    VERSION 0.1
    LANGUAGES C CXX
)

# C++ language standard. gtest requires C++ 14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Directories
set(INCLUDE_DIRS include/)
include_directories(${INCLUDE_DIRS})

set(LEXER_LIB_SRC src/Lexer.cc)
set (LEXER_LIB_H include/Lexer.h include/Lexer.h) 
add_library(lexer ${LEXER_LIB_SRC} ${LEXER_LIB_H})

# option to build gtest tests
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()