#include <iostream>

int *fun(int b) {
  b = 100;
  int a = 10;
  return &a;
}

int main() {
  int *p = fun(10);
  // p指向的内存已经被释放，访问它是未定义行为
  std::cout << *p << std::endl; // 可能输出10，也可能输出垃圾值，甚至崩溃
  std::cout << *p << std::endl; // 可能输出10，也可能输出垃圾值，甚至崩溃
  return 0;
}