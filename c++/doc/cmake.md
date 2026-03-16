## CMake用法实践

### 1. 基本CMakeLists.txt示例

```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloCMake)

set(CMAKE_CXX_STANDARD 17)

add_executable(hello main.cpp)
```

### 2. 构建流程

```bash
# 创建构建目录
mkdir build && cd build
# 生成构建文件
cmake ..
# 编译
cmake --build .
# 运行
./hello
```

### 3. 常用CMake命令说明

- `project()`：定义项目名称和语言。
- `set()`：设置变量，如C++标准。
- `add_executable()`：添加可执行文件目标。
- `add_library()`：添加库目标。
- `target_link_libraries()`：链接库。
- `include_directories()`：添加头文件搜索路径。

### 4. 查找和链接第三方库

以查找并链接Boost为例：

```cmake
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(hello ${Boost_LIBRARIES})
```

### 5. 结合IDE和多平台

CMake可生成多种工程文件：

```bash
cmake -G "Visual Studio 17 2022" ..
cmake -G "Ninja" ..
```

---

更多CMake高级用法（如自定义模块、条件编译、安装规则等），可参考[CMake官方文档](https://cmake.org/cmake/help/latest/)。