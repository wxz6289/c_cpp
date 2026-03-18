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

C++内存分区模型

**概览**
- **定义**: 进程地址空间按功能划分为若干段（分区），每段有不同用途、权限和生命周期。
- **目的**: 管理代码、只读常量、静态数据、动态分配（堆）、函数调用栈、内存映射文件/设备等，并通过虚拟内存与页表实现隔离与保护。

**典型内存分区（从低地址到高地址）**
- **代码段（Text / Code）**: 存放程序机器码，通常只读或可执行/不可写。
- **只读数据（RO Data）**: 存放字面量字符串与 `const` 对象，通常只读。
- **初始化数据段（Data）**: 存放已初始化的全局/静态变量（可读写），程序启动时存在。
- **未初始化数据段（BSS）**: 存放未初始化或置零的全局/静态变量，运行时初始化为0。
- **堆（Heap）**: 动态内存分配区，由 `malloc`/`free`、`new`/`delete`、`brk`/`sbrk` 或 `mmap` 管理，向高地址增长（实现可变）。
- **映射区（MMAP 区）**: 通过 `mmap` 映射文件或匿名内存，出现在堆或栈附近，支持文件映射与共享内存。
- **栈（Stack）**: 每个线程的函数调用栈，存放局部变量、返回地址和帧信息，通常向低地址增长。
- **内核空间**: 不在用户态地址空间内（受保护），系统调用和内核数据位于此处（虚拟地址映射与硬件相关）。

**增长方向与地址关系**
- **堆向高地址增长**，通过扩展 `brk` 或分配 `mmap` 实现。
- **栈向低地址增长**（在多数平台），线程栈起始于高地址并向低地址扩展。
- **堆与栈之间的空闲区** 可被 `mmap` 使用，二者冲突会导致内存耗尽或溢出。

**分区权限与保护**
- **页级权限**: 每页可设置为可读/可写/可执行（R/W/X）。
- **不可执行位（NX）**: 防止数据页执行（Mitigation for code injection）。
- **页对齐**: 内存以页为单位分配（通常 4KiB），大对象或 `mmap` 可能按大页分配。
- **守护页（Guard Page）**: 栈下常设置不可访问页面以检测栈溢出。
- **ASLR（地址随机化）**: 随机化基址（可执行、堆、库、栈、mmaps），提高安全性。

**线程、TLS 与每线程栈**
- **每线程独立栈**: 新线程通常由线程库分配固定或可伸缩的栈大小。
- **线程局部存储（TLS）**: 存放 `thread_local` 变量，生命周期与线程相同，位置与实现有关。

**堆的实现与特性**
- **分配器（malloc 实现）**: glibc ptmalloc、tcmalloc、jemalloc 等有不同策略：bin、合并、线程缓存。
- **碎片化**: 小对象大量分配/释放会导致内部/外部碎片。
- **对齐**: 分配通常满足对齐要求（例如 8/16 字节）。
- **大对象直接 `mmap`**: 超过阈值的分配可能直接调用 `mmap` 而非堆内碎块。

**栈帧与函数调用**
- **栈帧包含**: 返回地址、旧帧指针（可选）、局部变量、参数（有时在寄存器）。
- **递归与栈溢出**: 深递归或超大局部数组会耗尽栈（触发段错误）。可用 `ulimit -s` 查看/设置栈大小。
- **栈溢出保护**: 编译器可插入 stack canary（栈金丝雀）检测栈破坏。

**常见内存问题与症状**
- **段错误（SIGSEGV）**: 访问无权限或未映射地址。
- **堆内存泄漏**: 忘记 `free`/`delete`，长期占用内存。
- **双重释放（double free）**: 释放同一块两次，可能被利用或导致崩溃。
- **越界读写**: 访问数组越界导致未定义行为与潜在数据损坏。
- **使用已释放内存（use-after-free）**: 非常危险，可能导致信息泄露或控制流被篡改。

**调试与检测工具**
- **地址消毒器（ASan）**: 编译时启用 `-fsanitize=address` 检测越界、UAF 等（强烈推荐）。
- **内存泄漏检测（LeakSanitizer / ASan）**: 查找未释放内存。
- **Valgrind**: 动态检查内存错误（性能开销大但覆盖面广）。
- **UBSan**: 检测未定义行为（`-fsanitize=undefined`）。
- **gdb / lldb**: 调试断点、查看栈、内存内容与寄存器。
- **strace / dtrace**: 观察系统调用（`mmap`/`brk` 等）。
- **/proc/<pid>/maps**: 查看进程内存映射（Linux）。

**性能与设计建议**
- **短期对象优先栈或池分配**: 频繁分配小对象用对象池或 `std::vector` 预分配可减少开销。
- **避免大局部数组**: 使用堆分配或静态以避免栈溢出。
- **RAII 与智能指针**: 使用 `std::unique_ptr` / `std::shared_ptr` 和容器管理生命周期，减少泄漏。
- **按需使用 `mmap`**: 大文件映射或大对象可用 `mmap` 管理，避免堆碎片。
- **对齐/缓存友好**: 关注结构体填充与缓存行对齐提升性能。

**安全缓解机制（常见）**
- **ASLR**: 随机化地址，增加利用难度。
- **NX**: 禁止数据段执行。
- **Stack Canaries**: 检测栈缓冲区溢出。
- **Control-Flow Integrity（CFI）**: 限制间接调用目标（较新编译器特性）。

**实用命令示例**
- 查看栈大小限制：`ulimit -s`
- 查看内存映射（Linux）：`cat /proc/$(pidof myprog)/maps`
- 用 ASan 编译并运行：`g++ -fsanitize=address -g my.cpp && ./a.out`
- 用 valgrind：`valgrind --leak-check=full ./a.out`


引用
---

## 引用（Reference）

引用是 C++ 提供的一种为变量起别名的机制，常用于函数参数传递、返回值优化等。
引用本质是指针常量，必须在定义时初始化，并且一旦绑定后不可更改指向。
T* const ref = &var; // 等价于 T& ref = var;
解引用操作编译器自动实现
引用必须是一块合法的内存空间

### 定义引用

```cpp
int a = 10;
int &ref = a; // ref 是 a 的引用，ref 和 a 指向同一块内存
ref = 20;     // 修改 ref 就是修改 a，a 变为 20
```

- 引用必须初始化，且一旦绑定后不可更改指向。
- 引用本质上是变量的别名，没有单独的内存空间。

### 引用作为函数参数

- **引用传递**：允许函数直接操作实参，提高效率，避免不必要的拷贝。

```cpp
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
```

- 使用 `const` 修饰可防止函数修改参数：

```cpp
void print(const std::string &s) {
    std::cout << s << std::endl;
}
```

### 引用作为返回值

- 可以返回局部静态变量或全局变量的引用，但不能返回局部变量的引用（会悬垂）。
- 函数的调用可以作为左指针使用 （函数返回值是引用）

静态变量存放在全局区（Global/Static），生命周期贯穿程序始终，且在第一次调用时初始化。返回静态变量的引用是安全的，因为它不会被销毁。

```cpp
int& getStatic() {
    static int x = 0;
    return x;
}
```

### 常量引用

- `const T &` 可绑定到常量、右值或临时对象，常用于高效传递大对象。

```cpp
void show(const std::vector<int> &v);
```

### 引用与指针的区别

- 引用必须初始化，不能为 null，不可更改指向。
- 指针可为 null，可重新赋值指向其他对象。

### 右值引用（C++11）

- 用于实现移动语义和完美转发，语法为 `T &&`。

```cpp
void foo(std::string &&s); // s 可接收临时对象
```

---

函数默认参数

函数默认参数允许在函数声明或定义中为参数指定默认值，调用时可省略这些参数，编译器会使用默认值。 默认参数必须从右向左依次提供，不能在中间或左侧参数提供默认值而跳过右侧参数。

函数声明和实现只能有一个存在默认参数



## C++ 函数详解

### 1. 函数的基本结构

C++ 函数由返回类型、函数名、参数列表和函数体组成：

```cpp
返回类型 函数名(参数类型1 参数名1, 参数类型2 参数名2, ...) {
    // 函数体
    return 返回值; // 如果返回类型不是 void
}
```

- **返回类型**：函数执行后返回的数据类型，可以是基本类型、结构体、类、指针、引用等。
- **参数列表**：函数输入的变量，可以有多个，也可以没有（此时写作 `()`）。
- **函数体**：实现具体功能的代码块。

### 2. 函数声明与定义

- **声明（声明原型）**：告诉编译器函数的名称、返回类型和参数类型，通常放在头文件或源文件顶部。
- **定义**：给出函数的具体实现。

```cpp
// 声明
int add(int a, int b);

// 定义
int add(int a, int b) {
    return a + b;
}
```

### 3. 函数参数传递方式

- **值传递**：传递参数的副本，函数内修改不影响实参。
- **引用传递**：传递参数的引用，函数内修改会影响实参。
- **指针传递**：传递参数的地址，适用于需要修改实参或处理数组。

### 4. 函数的返回值

- 可以返回基本类型、结构体、类、指针、引用等。
- 返回引用时要确保返回的对象在函数外依然有效（如全局变量、静态变量）。

### 5. 函数重载

C++ 支持同名函数根据参数类型或个数不同进行重载：

```cpp
int max(int a, int b);
double max(double a, double b);
```

### 6. 内联函数（inline）

使用 `inline` 关键字建议编译器将函数代码直接插入调用处，适用于短小、频繁调用的函数：

```cpp
inline int square(int x) { return x * x; }
```

### 7. 默认参数

函数参数可以指定默认值，调用时可省略：

```cpp
void print(int x, int y = 10);
print(5); // 等价于 print(5, 10)
```

### 8. 可变参数模板（C++11）

用于实现参数数量不定的函数：

```cpp
template<typename... Args>
void func(Args... args) { /* ... */ }
```

### 9. 函数指针与回调

函数可以作为参数传递，实现回调机制：

```cpp
void callback(int x) { /* ... */ }
void invoke(void (*func)(int)) {
    func(42);
}
```

### 10. Lambda 表达式（C++11）

用于定义匿名函数，常用于算法和回调：

```cpp
auto add = [](int a, int b) { return a + b; };
int result = add(1, 2);
```

### 11. constexpr 函数（C++11）

可在编译期求值的函数：

```cpp
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}
```

### 12. noexcept 说明符（C++11）

声明函数不会抛出异常：

```cpp
void foo() noexcept;
```

### 13. 函数的递归调用

函数可以调用自身，实现递归：

```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

### 14. 函数的命名空间与作用域

函数可以定义在命名空间内，避免命名冲突：

```cpp
namespace math {
    int add(int a, int b) { return a + b; }
}
```

### 15. 函数的特殊类型

- **成员函数**：定义在类内部，操作类成员。
- **静态成员函数**：不依赖对象实例。
- **虚函数**：支持多态，基类指针/引用调用派生类实现。

---

**小结**：C++ 函数是代码复用和模块化的基础，支持多种参数传递方式、重载、模板、默认参数、内联、递归、Lambda 等丰富特性。合理设计和使用函数有助于提升代码的可读性、可维护性和性能。


---

## 占位参数（占位符参数）

占位参数用于函数参数列表中暂时不使用的参数，常见于函数重载、回调接口或保留接口兼容性。C++ 中可用未命名参数或 `[[maybe_unused]]` 标记避免编译器警告。占位参数还可以有默认值。

### 未命名参数

```cpp
void func(int, double) {
    // 参数未命名，无法在函数体中使用
}
```

### `[[maybe_unused]]` 标记（C++17 起）

```cpp
void func(int /*unused*/, [[maybe_unused]] double y) {
    // y 可能未被使用，编译器不会警告
}
```

### 常见用途

- 保持函数签名兼容
- 实现接口但暂时不使用所有参数
- 作为回调函数的占位

---

## 函数重载详解

函数重载（Function Overloading）是 C++ 支持的一种特性，允许在同一作用域内定义多个同名函数，只要它们的参数列表（参数类型、个数或顺序）不同即可。编译器会根据调用时传入的参数自动选择匹配的函数实现。

### 1. 基本规则

- 同名函数必须在同一作用域内。
- 参数列表必须不同（类型、个数或顺序至少有一项不同）。
- 仅返回值不同不能构成重载。

```cpp
void print(int x);
void print(double y);
void print(int x, int y);
```

### 2. 匹配原则

- 编译器根据参数类型、个数、顺序选择最合适的重载版本。
- 如果存在二义性（如类型转换冲突），编译报错。

### 3. 示例

```cpp
#include <iostream>
void show(int x) { std::cout << "int: " << x << std::endl; }
void show(double y) { std::cout << "double: " << y << std::endl; }
void show(const char* s) { std::cout << "string: " << s << std::endl; }

int main() {
    show(10);        // 调用 show(int)
    show(3.14);      // 调用 show(double)
    show("hello");   // 调用 show(const char*)
}
```

### 4. 注意事项

- 默认参数可能导致重载冲突，应避免参数列表产生二义性。
- 函数模板也可与普通函数重载，但模板优先级较低，除非参数完全匹配模板。
- 引用作为重载的条件
- 带默认参数的函数重载可能引起二义性，需谨慎设计。

```cpp
void process(int &x); // 处理左值
void process(const int &x); // 处理右值

int a = 5;
process(a); // 调用 process(int &x)
process(10); // 调用 process(const int &x)
```

### 5. 应用场景

- 提高接口友好性，支持不同类型或数量的参数。
- 实现多种数据类型的统一操作。

**小结**：函数重载让代码更灵活、易用，是 C++ 面向对象和泛型编程的重要基础。

---

## 类与对象

C++ 是面向对象编程语言，类（class）是用户自定义的数据类型，对象是类的实例。类封装了数据成员（属性）和成员函数（方法），实现数据和操作的统一。

### 1. 类的定义与对象的创建

```cpp
class Person {
public:
    std::string name;
    int age;

    void sayHello() {
        std::cout << "Hello, my name is " << name << std::endl;
    }
};

Person p1; // 创建对象
p1.name = "Alice";
p1.age = 20;
p1.sayHello();
```

- `public`：公有成员，外部可访问。
- `private`：私有成员，仅类内部可访问（默认）。
- `protected`：受保护成员，派生类可访问。

### 2. 构造函数与析构函数

- **构造函数**：与类同名，无返回值。用于对象初始化。
- **析构函数**：以 `~类名` 命名，无参数。对象销毁时自动调用。

```cpp
class Person {
public:
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "构造: " << name << std::endl;
    }
    ~Person() {
        std::cout << "析构: " << name << std::endl;
    }
    std::string name;
    int age;
};
```

### 3. 成员函数定义

成员函数可在类内声明、类外实现：

```cpp
class Person {
public:
    void setAge(int a);
    int getAge() const;
private:
    int age;
};

void Person::setAge(int a) { age = a; }
int Person::getAge() const { return age; }
```

- `const` 成员函数：不修改成员变量。

### 4. this 指针

成员函数内部可用 `this` 指针访问当前对象：

```cpp
void setAge(int age) { this->age = age; }
```

### 5. 静态成员

- `static` 数据成员：所有对象共享。
- `static` 成员函数：不依赖具体对象。

```cpp
class Counter {
public:
    static int count;
    Counter() { ++count; }
    static int getCount() { return count; }
};
int Counter::count = 0;
```

### 6. 访问控制

- `public`：外部可访问。
- `private`：仅类内部可访问。
- `protected`：类内部和派生类可访问。

### 7. 对象的创建方式

- 栈上创建：`Person p;`
- 堆上创建：`Person* p = new Person();`，用完需 `delete p;`

### 8. 拷贝构造与赋值运算符

- 拷贝构造：`Person(const Person& other);`
- 赋值运算符：`Person& operator=(const Person& other);`

### 9. 类的继承

```cpp
class Student : public Person {
public:
    int grade;
};
```

- 支持单继承和多继承。
- `public` 继承：基类公有成员变为派生类公有成员。

### 10. 多态与虚函数

- 基类函数前加 `virtual`，派生类重写实现多态。
- 通过基类指针/引用调用派生类方法。

```cpp
class Animal {
public:
    virtual void speak() { std::cout << "Animal" << std::endl; }
};
class Dog : public Animal {
public:
    void speak() override { std::cout << "Dog" << std::endl; }
};
```

### 11. 友元（friend）

- 友元函数/类可访问类的私有成员。

```cpp
class Box {
    friend void show(Box&);
private:
    int value;
};
```

### 12. 内联成员函数

- 类内定义的成员函数自动为 `inline`。

---

**小结**：类与对象是 C++ 面向对象编程的核心，支持封装、继承和多态。合理设计类结构有助于代码复用、扩展和维护。


---

## class 与 struct 的区别

C++ 中 `class` 和 `struct` 都可用于定义自定义类型，二者在语法和功能上非常相似，但有以下主要区别：

### 1. 默认访问权限不同

- `struct` 的成员默认是 `public`（公有）。
- `class` 的成员默认是 `private`（私有）。

```cpp
struct S {
    int x; // 默认 public
};

class C {
    int x; // 默认 private
};
```

### 2. 默认继承权限不同

- `struct` 继承时默认 `public` 继承。
- `class` 继承时默认 `private` 继承。

```cpp
struct Base {};
struct Derived1 : Base {};      // 默认 public 继承
class Derived2 : Base {};       // 默认 private 继承
```

### 3. 功能完全一致

- 都支持成员变量、成员函数、构造/析构、继承、多态、模板等所有面向对象特性。
- 选择 `struct` 还是 `class` 主要取决于代码风格和语义表达。

### 4. 使用建议

- `struct` 常用于简单的数据结构或 POD（Plain Old Data）类型。
- `class` 常用于复杂对象、封装和面向对象设计。

**小结**：`class` 和 `struct` 的唯一区别是默认访问权限和默认继承权限，功能上完全等价。

---

## 成员属性设置为 private 的优势

将类的成员属性（数据成员）设置为 `private`（私有）是面向对象编程中封装（Encapsulation）原则的体现，具有以下优势：

1. **数据安全性**
    - 防止外部代码直接修改对象的内部状态，避免无效或非法赋值，保护数据完整性。

2. **隐藏实现细节**
    - 只暴露必要的接口（如 getter/setter），隐藏内部实现，便于后续修改而不影响外部代码。

3. **便于维护和扩展**
    - 可以在访问成员时增加校验、日志等逻辑，增强灵活性和可维护性。

4. **支持只读/只写属性**
    - 通过只提供 getter 或 setter，可以灵活控制属性的访问权限。

5. **实现不变式约束**
    - 在 setter 中检查和保证对象始终处于有效状态，防止出现不一致的数据。

**示例：**

```cpp
class Person {
private:
     int age;
public:
     void setAge(int a) {
          if (a >= 0 && a <= 150) age = a;
     }
     int getAge() const { return age; }
};
```

**小结**：将成员属性设为 `private` 能有效保护数据、隐藏实现细节、提升代码健壮性，是良好类设计的重要基础。

构造函数和析构函数
构造函数 用于对象创建时初始化成员与资源。名字与类同名且无返回类型。

- 默认构造函数 无参或编译器生成
- 带参构造函数 Foo(int x)
- 拷贝构造函数 Foo(const Foo&)
- 移动构造函数 参数为右值引用 Foo(Foo&& other)
- 删除/禁止 Foo(const Foo&) = delete; // 禁止拷贝构造
- 显式 explicit Foo(int x); // 防止隐式转换

初始化列表： 优先初始化成员和基类，应使用 : member(value) 形式，效率更高且必须用于常量/引用成员。

构造顺序： 先调用基类构造，再按成员在类中声明顺序初始化，最后进入构造函数体。

析构函数（~类名()）：用途与规则。 在对象生命周期结束时释放资源（关闭文件、释放内存等）。若类有虚函数且会通过基类指针删除派生对象，基类析构函数必须为 virtual。

析构顺序： 析构函数体执行后，按成员声明的反向顺序析构成员，最后调用基类析构函数。

异常与安全性： 构造函数若抛出异常，已完成构造的成员会被正确析构；因此在构造中只应管理能被正确清理的资源或使用 RAII（如 std::unique_ptr）避免泄漏。
```cpp
class Resource {
public:
    Resource(int n) : data(new int[n]), n(n) {}
    ~Resource() { delete[] data; }
    Resource(const Resource&) = delete;
    Resource(Resource&&) noexcept : data(nullptr), n(0) {}
private:
    int* data;
    int n;
};
```

实用建议： 使用 RAII 和智能指针管理资源；为可做多态删除的基类声明 virtual ~Base()；优先用 =default / =delete 明确意图，尽量避免手写资源管理代码。

---

## 构造函数调用规则

1. **对象创建时自动调用**
    - 当使用类名创建对象（如 `Person p;` 或 `Person p("Alice", 20);`），会自动调用相应的构造函数。
    - 若未显式提供构造函数，编译器会生成默认构造函数。

2. **成员和基类先于自身初始化**
    - 构造函数执行前，先按成员声明顺序初始化成员，再调用基类构造函数。

3. **初始化列表优先于函数体**
    - 初始化列表中的成员和基类初始化在进入构造函数体之前完成。

4. **拷贝/移动构造函数调用**
    - 当对象以值传递、返回、赋值等方式进行复制或移动时，分别调用拷贝构造或移动构造函数。

5. **禁止拷贝/移动时规则**
    - 若构造函数被 `=delete` 禁止，则相关操作会编译报错。

6. **显式与隐式调用**
    - `explicit` 构造函数只能显式调用，不能用于隐式类型转换。

7. **临时对象与匿名对象**
    - 临时对象（如 `Person("Bob", 25);`）会自动调用构造函数，生命周期仅限当前表达式。

8. **数组对象构造**
    - 创建对象数组时，会为每个元素依次调用构造函数。

**示例：**
```cpp
Person p1;                // 默认构造
Person p2("Alice", 20);   // 带参构造
Person p3 = p2;           // 拷贝构造
Person p4 = std::move(p2);// 移动构造
```

---

1. 每个类都至少添加3个函数：默认构造函数、拷贝构造函数和析构函数。
2. 如果类中没有定义任何构造函数，编译器会自动生成一个默认构造函数。如果类中定义了任何构造函数（包括带参构造函数），编译器将不再生成默认构造函数。若没有定义拷贝构造函数，编译器会生成一个默认的拷贝构造函数。若提供了拷贝构造函数，编译器将不再生成默认的拷贝构造函数。
3. 如果类中定义了析构函数，编译器将不再生成默认的析构函数。


---

## 深拷贝与浅拷贝的区别

拷贝对象时，C++ 支持浅拷贝（默认行为）和深拷贝。两者区别如下：

### 1. 浅拷贝（Shallow Copy）

- 仅复制对象的成员变量值（包括指针地址），不会复制指针指向的实际内容。
- 多个对象共享同一块内存，修改一个对象会影响另一个。
- 默认拷贝构造函数和赋值运算符执行浅拷贝。

```cpp
class Demo {
public:
    int* data;
    Demo(int n) : data(new int(n)) {}
    // 默认拷贝构造函数：仅复制指针地址
};
```

### 2. 深拷贝（Deep Copy）

- 不仅复制成员变量，还会分配新的内存并复制指针指向的内容。
- 每个对象拥有独立的内存，互不影响。
- 需自定义拷贝构造函数和赋值运算符。

```cpp
class Demo {
public:
    int* data;
    Demo(int n) : data(new int(n)) {}
    Demo(const Demo& other) : data(new int(*other.data)) {} // 深拷贝
    Demo& operator=(const Demo& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
};
```

### 3. 适用场景

- **浅拷贝**：适用于成员变量无动态分配内存的简单类。
- **深拷贝**：适用于类成员包含指针或动态资源，避免资源冲突和内存泄漏。

**小结**：浅拷贝只复制指针地址，深拷贝复制指针内容。资源管理类必须实现深拷贝以保证安全。

栈区
指针 堆区

浅拷贝 可能带来堆区的内存重复释放问题，使用深拷贝解决