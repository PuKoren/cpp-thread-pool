project(TP1)
cmake_minimum_required(VERSION 2.8)

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -Wall -pthread -ftest-coverage -fprofile-arcs")

find_package(Threads)

include_directories(include)

file(GLOB SRCS src/*.cpp)
file(GLOB HDRS include/*.h)

add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

