#include<iostream>
using namespace std;

void show(const int &a) {
  cout << "a:" << a << endl;
  // a = 20;
}

int main() {
  int b = 20;
  show(b);

  // int &a = 10; // 引用需要合法的内存空间
  const int &a = 10; // 常量引用可以绑定到字面值;
  return 0;
}