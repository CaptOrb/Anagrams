cmake_minimum_required(VERSION 3.15)
project(SEProject C)

set(CMAKE_C_STANDARD 99)

add_executable(SEProject src/main.c src/readInput.c src/readInput.h src/sort.c src/sort.h src/anagram.c src/anagram.h src/extra.h src/outputResults.c src/outputResults.h)