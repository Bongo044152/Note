cmake_minimum_required(VERSION 3.31.0-rc2)

project(main)

# 以便可以找到 hello.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/module)

# 創建靜態庫
add_library(lib_hello STATIC module/hello.c)

# 創建可執行檔
add_executable(${PROJECT_NAME} main.c)

# 這邊是為了找到 good.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(lib_good STATIC good.c)

# 進行連接
target_link_libraries(${PROJECT_NAME} lib_hello)
target_link_libraries(${PROJECT_NAME} lib_good)
