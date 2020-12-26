#https://zhuanlan.zhihu.com/p/267803605
cmake_minimum_required(VERSION 3.5)

include_directories ("${PROJECT_SOURCE_DIR}/Dependencies/GLEW/include")
 
add_subdirectory("./animation")

#aux_source_directory(./sparky-core ENGINE_SRC_LIST)

file(GLOB ENGINE_SRC_LIST "./*.cpp")
 
add_library(sparky-core ${ENGINE_SRC_LIST})


 