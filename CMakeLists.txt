cmake_minimum_required(VERSION 3.31)
project(cmt C)

# Build static library
add_library(${PROJECT_NAME} STATIC cmt.c)

target_compile_features(${PROJECT_NAME} PUBLIC c_std_11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
target_compile_options(${PROJECT_NAME} PUBLIC -W4)

# Build test executable
add_executable(${PROJECT_NAME}_test test.c)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
