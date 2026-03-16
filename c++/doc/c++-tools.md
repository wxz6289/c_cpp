
# C++开发工具链简介

## 1. 编译器（Compiler）
- **GCC (g++)**：GNU编译器套件，跨平台，Linux/Unix主流。
- **Clang/LLVM**：现代C/C++编译器，编译速度快，错误提示友好，macOS默认。
- **MSVC**：微软Visual C++，Windows平台主流，集成于Visual Studio。
- **MinGW/MinGW-w64**：Windows下的GCC移植版。

## 2. 构建系统（Build System）
- **Make/Makefile**：经典自动化构建工具，适合小型项目。
- **CMake**：跨平台主流构建系统，生成Makefile、Ninja、Visual Studio等工程文件，适合中大型项目。
- **Ninja**：高效的构建工具，常与CMake配合。
- **Bazel、Meson、SCons**：现代化构建系统，适合大型工程。

## 3. 包管理器（Package Manager）
- **vcpkg**：微软主推，跨平台，适合Windows和Linux。
- **Conan**：流行的C/C++包管理器，支持多平台和多编译器。
- **Hunter**：CMake集成的包管理器。
- **Homebrew/apt/yum**：系统级包管理器，可安装C++库。

## 4. 调试器（Debugger）
- **gdb**：GNU调试器，Linux/Unix主流。
- **lldb**：Clang/LLVM调试器，macOS主流。
- **Visual Studio Debugger**：Windows平台强大调试工具。
- **Valgrind**：内存错误和泄漏检测工具。

## 5. 静态分析与代码质量
- **clang-tidy**：Clang生态静态分析工具，支持现代C++风格检查。
- **cppcheck**：独立的C/C++静态分析工具。
- **include-what-you-use**：头文件依赖分析。
- **Sanitizer**：如ASan（地址）、UBSan（未定义行为）、TSan（线程）等，编译器内建。

## 6. 集成开发环境（IDE）与编辑器
- **Visual Studio**：Windows下功能最全的C++ IDE。
- **CLion**：JetBrains出品，跨平台，CMake集成好。
- **Qt Creator**：适合Qt开发，也支持纯C++。
- **VS Code**：轻量级编辑器，配合C++插件（如ms-vscode.cpptools、CMake Tools）可高效开发。
- **Vim/Emacs**：高级用户可定制化编辑器。

## 7. 其他辅助工具
- **Doxygen**：自动生成文档。
- **Ccache**：编译缓存，加速增量编译。
- **Gprof/Perf**：性能分析工具。
- **CMake GUI**：可视化配置CMake工程。

---
如需详细安装、配置或某一工具链的实战示例，请查阅相关章节或向我提问！
