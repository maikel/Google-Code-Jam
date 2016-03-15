cmake_minimum_required (VERSION 2.6)
project(Google-Code-Jam)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Werror -Wfatal-errors -std=c++11 -O2")

add_executable(t9_spelling t9_spelling.cpp)
add_executable(reverse_words reverse_words.cpp)
add_executable(minimum_scalar_product minimum_scalar_product.cpp)
add_executable(milkshake milkshake.cpp)

add_subdirectory(2011)
add_subdirectory(2008)