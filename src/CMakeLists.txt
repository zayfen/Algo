cmake_minimum_required(VERSION 2.8)

project(Algo)

#find_package(Boost 1.4 COMPONENTS unit_test_framework)
#enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(./_utils  ./_common_models)
set(SRC  ./heap/max_heap.cpp)
add_executable(max_heap ${SRC})

