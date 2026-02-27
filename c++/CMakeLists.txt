cmake_minimum_required(VERSION 3.10)
project(modern-cpp)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置源码和头文件目录

# 源码目录
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
# 测试目录
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)


# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 单独编译每个main文件为独立可执行程序
# add_executable(function ${SRC_DIR}/function.cpp ${SRC_DIR}/max.cpp)
# add_executable(hello ${SRC_DIR}/hello.cpp)
# add_executable(swap ${SRC_DIR}/swap.cpp)
# add_executable(array ${SRC_DIR}/array.cpp)
# add_executable(pinter ${SRC_DIR}/pinter.cpp)
# add_executable(bubbleSort ${SRC_DIR}/bubbleSort.cpp)
# add_executable(struct ${SRC_DIR}/struct.cpp)
# add_executable(struct_array ${SRC_DIR}/struct-array.cpp)
# add_executable(struct_pointer ${SRC_DIR}/struct-pointer.cpp)
# add_executable(struct_in_struct ${SRC_DIR}/struct-in-struct.cpp)
add_executable(const_struct ${SRC_DIR}/const-struct.cpp)

# 包含头文件目录
# target_include_directories(function PRIVATE ${SRC_DIR})
# target_include_directories(hello PRIVATE ${SRC_DIR})
# target_include_directories(swap PRIVATE ${SRC_DIR})
# target_include_directories(array PRIVATE ${SRC_DIR})
# target_include_directories(pinter PRIVATE ${SRC_DIR})
# target_include_directories(bubbleSort PRIVATE ${SRC_DIR})
# target_include_directories(struct PRIVATE ${SRC_DIR})
# target_include_directories(struct_array PRIVATE ${SRC_DIR})
# target_include_directories(struct_pointer PRIVATE ${SRC_DIR})
target_include_directories(const_struct PRIVATE ${SRC_DIR})
# target_include_directories(test_runner PRIVATE ${SRC_DIR} ${TEST_DIR})
