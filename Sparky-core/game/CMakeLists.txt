#https://zhuanlan.zhihu.com/p/267803605
cmake_minimum_required(VERSION 3.5)


file(GLOB ENGINE_SRC_LIST "./*.cpp")
 
add_library(sparky-core ${ENGINE_SRC_LIST})


 