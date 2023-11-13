cmake_minimum_required(VERSION 3.24)

project(cuda_cpp LANGUAGES CUDA CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")



add_executable(main src/main.cpp )

add_library(kernels src/kernel.cu src/kernel.cuh)
add_library(gpu src/gpu.cpp src/gpu.hpp)

target_link_libraries(main PUBLIC gpu)
target_link_libraries(main PUBLIC kernels)
# target_link_libraries(gpu PUBLIC CUDA::cudart)

find_package(CUDAToolkit)

