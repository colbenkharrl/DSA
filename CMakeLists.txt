cmake_minimum_required(VERSION 3.0)
project(main)
set(SOURCE main.cpp sort.cpp heap.cpp stack.cpp queue.cpp sort.h heap.h stack.h queue.h)
add_executable(${PROJECT_NAME} ${SOURCE})