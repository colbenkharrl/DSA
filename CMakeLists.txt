cmake_minimum_required(VERSION 3.0)
project(main)
set(SOURCE source/main.cpp source/sort.cpp source/heap.cpp source/stack.cpp source/queue.cpp source/sort.h source/heap.h source/stack.h source/queue.h)
add_executable(${PROJECT_NAME} ${SOURCE})