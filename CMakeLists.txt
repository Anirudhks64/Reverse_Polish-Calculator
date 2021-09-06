cmake_minimum_required(VERSION 3.11)
project(PS5 C)

set(CMAKE_C_STANDARD 99)

add_executable(PS5 main.c node.c node.h rpn.c rpn.h stack.c stack.h errors.c errors.h)