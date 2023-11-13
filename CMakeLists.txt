cmake_minimum_required(VERSION 3.24)

project(cuda_cpp LANGUAGES CUDA CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(main src/main.cpp )

add_library(kernels src/kernel.cu src/kernel.cuh)
add_library(gpu src/gpu.cpp src/gpu.hpp)

target_link_libraries(main PRIVATE gpu)
target_link_libraries(main PRIVATE kernels)


# target_include_directories(main PUBLIC include)

find_package(CUDAToolkit)

target_link_libraries(main PUBLIC CUDA::cudart)
