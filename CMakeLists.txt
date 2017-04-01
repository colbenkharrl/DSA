cmake_minimum_required(VERSION 3.0)
project(main)
set(SOURCE source/main.cpp source/sort.cpp source/heap.cpp source/stack.cpp source/queue.cpp source/dset.cpp source/util.cpp source/validate.cpp source/bst.cpp source/rbt.cpp header/sort.h header/heap.h header/stack.h header/queue.h header/dset.h header/util.h header/validate.h header/bst.h header/rbt.h)
add_executable(${PROJECT_NAME} ${SOURCE})