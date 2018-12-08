cmake_minimum_required (VERSION 3.12)
project (cpp-fizzbuzz)

file (GLOB cpp-fizzbuzz_SRC "src/*.cpp")

add_executable (cpp-fizzbuzz ${cpp-fizzbuzz_SRC})
