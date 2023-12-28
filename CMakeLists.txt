cmake_minimum_required(VERSION 3.28)

project(la.cpp)

# building parameters
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(LACPP_BUILD_DEMO "Build Demo" ON)
option(LACPP_BUILD_TEST "Build Test" OFF)
option(LACPP_BUILD_DOCS "Build Docs" OFF)
option(LACPP_BUILD_BENC "Build Benc" OFF)

# lacpp library
add_subdirectory(src)

# export lacpp target
add_library(lacpp INTERFACE)
target_link_libraries(lacpp INTERFACE lacpp_core)

# demos
if(LACPP_BUILD_DEMO)
  add_subdirectory(demo)
endif()

# tests
if(LACPP_BUILD_TEST)
  enable_testing()
  add_subdirectory(test)
endif()

# benchmarks
if(LACPP_BUILD_BENC)
  add_subdirectory(benchmark)
endif()

if(LACPP_BUILD_DOCS)
  add_subdirectory(doc)
endif()
