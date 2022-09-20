cmake_minimum_required(VERSION 3.14)
project(counting_sort)

set(CMAKE_CXX_STANDARD 20)

option(COUNTING_SORT_ENABLE_UT "Enable UTs" ON)

if(COUNTING_SORT_ENABLE_UT)
    add_subdirectory(ut)
endif()

