#include<iostream>
using namespace std;

int main() {
  int a = 12;
  // 1. 引用必须初始化 2. 不可改变引用对象 3. 引用本质上是一个别名，不占用额外内存
  int &ref = a;
  cout << "a: " << a << endl; // 输出12
  cout << "ref: " << ref << endl; // 输出12
  ref = 20; // 修改ref会修改a
  cout << "a: " << a << endl; // 输出20
  cout << "ref: " << ref << endl; // 输出20
  int c = 20;
  // &ref = c; // 错误：引用不可改变绑定对象
  return 0;
}