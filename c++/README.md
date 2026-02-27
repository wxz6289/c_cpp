# 快速学习C++项目结构

本项目采用如下目录结构，便于源码管理、编译、测试和学习：

- src/      —— 源代码文件（.cpp/.h）
- test/     —— 测试代码（可选）
- build/    —— 构建输出目录（建议在此目录下执行cmake和make）
- bin/      —— 可执行文件由CMake自动生成到此目录
- CMakeLists.txt —— CMake配置文件

## 编译与运行

1. 进入build目录：
   cd build
2. 生成Makefile：
   cmake ..
3. 编译：
   cmake --build .
4. 运行：
   ./bin/modern_cpp

## 添加测试支持

如需添加测试，可以在test目录下编写测试代码，并在CMakeLists.txt中配置如下：

# 查找测试源文件
file(GLOB_RECURSE TEST_SOURCES ${CMAKE_SOURCE_DIR}/test/*.cpp)

# 添加测试可执行文件
add_executable(test_runner ${TEST_SOURCES})
set_target_properties(test_runner PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 可选：链接gtest等测试库
# target_link_libraries(test_runner PRIVATE gtest)

## 头文件管理

如有多个头文件目录，可在CMakeLists.txt中添加：
target_include_directories(modern_cpp PRIVATE ${SRC_DIR})

---
建议所有编译、测试操作都在build目录下进行，保持源码目录干净。
