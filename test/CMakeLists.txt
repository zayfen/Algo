cmake_minimum_required(VERSION 2.8)
project(algo_test)

set(CMAKE_BUILD_TYPE Debug)

# bring the headers,
include_directories(../src/search)
include_directories(../thirdparty)

# set SOURCES
file(GLOB SOURCES "search/*.cpp")

# print sources
message( ${SOURCES})

# add executable
add_executable(algo_test ${SOURCES})
