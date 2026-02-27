---

# C++ 学习笔记

## 编译命令

```sh
# 常用编译命令
# g++ 或 clang++ 均可

g++ -std=c++17 -O2 -Wall -Wextra -o hello hello.cpp
clang++ -std=c++17 -O2 -o hello hello.cpp
clang++ -std=c++17 -O2 -o function function.cpp max.cpp

# 使用 C++20
# g++ -std=c++20 ...

# 编译多个文件
# g++ -std=c++17 *.cpp -o myprog
```

- 推荐在 build 目录下用 CMake 管理项目，所有可执行文件输出到 bin 目录，源码和二进制分离，便于管理。
- VSCode 可用 Ctrl+Alt+N 或右键 Run Code 快速编译运行（需 Code Runner 插件）。

---

## 基础语法

### 注释
- 单行注释：`// 这是一个注释`
- 多行注释：`/* 这是一个多行注释 */`

### 变量声明与初始化
```cpp
int a = 10;               // 整数变量
double b = 3.14;         // 浮点数变量
char c = 'A';            // 字符变量
std::string str = "Hello"; // 字符串变量
bool flag = true;        // 布尔变量
```

### 常量
```cpp
const int MAX_SIZE = 100; // 常量声明
#define PI 3.14159        // 宏定义常量
```

### 宏常量与宏函数
```cpp
#define SQUARE(x) ((x) * (x)) // 宏定义函数
```

### 关键字与类型
- 基本类型：`int`, `double`, `char`, `bool`, `void`
- 条件语句：`if`, `else`, `switch`, `case`
- 循环语句：`for`, `while`, `do`
- 其它：`return`, `class`, `struct`, `public`, `private`, `protected`, `namespace`, `using`, `const`, `#include`, `#define`, `template`, `try`, `catch`, `throw`, `virtual`, `override`, `static`, `friend`, `this`, `new`, `delete`, `enum`, `typedef`, `auto`, `nullptr`, `constexpr`, `inline`, `volatile`, `extern`, `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`, `sizeof`, `typeid`, `static_assert`, `alignas`, `alignof`, `noexcept`, `thread_local`, `concept`, `co_await`, `co_yield`, `co_return`, `requires`, `import`, `module`, `consteval`, `constinit`, `explicit`, `mutable`

### 标识符命名规则
- 只能包含字母、数字和下划线，不能以数字开头，区分大小写。
- 不能使用 C++ 关键字作为标识符。
- 建议有意义的名称，推荐驼峰或下划线命名法。

### 数据类型
- 基本类型：`int`, `short`, `long`, `long long`, `float`, `double`, `char`, `bool`
- 派生类型：指针（`*`）, 引用（`&`）, 数组（`[]`）, 函数
- 用户自定义类型：类（`class`）, 结构体（`struct`）, 枚举（`enum`）
- 空类型：`void`

### 内存分布
- 栈区（Stack）：局部变量、函数调用信息，自动分配释放。
- 堆区（Heap）：动态分配内存，需手动管理。
- 全局区（Global/Static）：全局变量、静态变量，程序运行期间一直存在。
- 常量区（Constant）：常量字符串和常量数据。

### sizeof 关键字
- 获取类型或变量所占字节数。

---

## 函数

### 定义与调用
```cpp
返回类型 函数名(参数类型 参数名, ...) {
    // 函数体
    return 返回值; // 如果返回类型不是 void
}

// 调用
函数名(实参1, 实参2, ...);
```

### 值传递与引用传递
- 值传递：形参为变量副本，函数内修改不影响实参。
- 引用传递：形参为实参的别名，函数内修改会影响实参。

### 函数声明与定义
- 声明可以多次，定义只能有一次。

---

## 指针与引用

### 指针
```cpp
int a = 10;
int* p = &a; // p 指向 a 的地址
int value = *p; // 通过指针获取 a 的值
```
- 空指针：指向地址0，不可访问。
- 野指针：未初始化的指针，指向未知地址。

### const 修饰指针
- `const int *p`：常量指针，指向可变，值不可变。
- `int *const p`：指针常量，指向不可变，值可变。
- `const int *const p`：指向常量的指针常量，指向和值都不可变。

### 地址传递与值传递
- 地址传递：通过指针传递参数，函数内对指针的修改会影响实参。
- 值传递：将实参的值复制给形参，函数内对形参的修改不会影响实参。

---

## 模板函数获取数组长度

在C++中，可以通过模板函数在编译期安全地获取静态数组的长度：

```cpp
// 定义模板函数
template<typename T, size_t N>
constexpr size_t array_size(T (&)[N]) noexcept {
    return N;
}

// 使用示例
int arr[10];
size_t len = array_size(arr); // len为10
```

### 解释
- `template<typename T, size_t N>`：模板参数，T为元素类型，N为数组长度。
- `T (&)[N]`：参数类型，表示“引用一个长度为N、元素类型为T的数组”，只能传递真正的数组，不能传指针。
- `constexpr`：可在编译期求值，无运行时开销。
- `noexcept`：承诺不会抛出异常。
- `return N;`：直接返回数组长度。

### 优点
- 类型安全，不能误传指针。
- 编译期求值，效率高。
- 语法简洁，调用时只需 `array_size(arr)`。

### 注意
- 只能用于静态数组，不能用于指针或动态分配的数组。

---

## 结构体

结构体（struct）用于将多个不同类型的数据组合在一起，常用于描述复杂数据。

### 定义结构体
```cpp
struct Person {
    std::string name;
    int age;
    double height;
};
```

### 声明和初始化
```cpp
Person p1; // 默认初始化
p1.name = "Alice";
p1.age = 20;
p1.height = 1.65;

Person p2 = {"Bob", 25, 1.80}; // 列表初始化
```

### 访问成员
```cpp
std::cout << p1.name << " " << p1.age << " " << p1.height << std::endl;
```

### 结构体数组

```cpp
Person group[3] = {
    {"Tom", 18, 1.70},
    {"Jerry", 19, 1.68},
    {"Spike", 21, 1.75}
};
```

### 指针与结构体

结构体指针可以通过 `->` 运算符访问成员：

```cpp
Person *ptr = &p1;
ptr->age = 22; // 用 -> 访问成员
```

### 结构体与函数

结构体可作为参数传递，也可作为返回值。

```cpp
void printPerson(const Person &p) {
    std::cout << p.name << ", age: " << p.age << std::endl;
}
```

### 结构体与类的区别

- struct 默认成员为 public，class 默认为 private。
- struct 支持成员函数、构造函数、继承等，功能与 class 基本一致。

---