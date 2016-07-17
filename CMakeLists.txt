cmake_minimum_required(VERSION 3.5)
project(algorithm_drawer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    avl_tree/avl.cpp
    avl_tree/avl.h
        binary_search_tree/binary_search_tree.cpp
        binary_search_tree/binary_search_tree.h
        binary_search_tree/test_bst.h
        binary_search_tree/test_bst.cpp
        main.cpp
        max_heap/max_heap.h
        min_heap/min_heap.h
        min_heap/min_heap.cpp)

add_executable(algorithm_drawer ${SOURCE_FILES})