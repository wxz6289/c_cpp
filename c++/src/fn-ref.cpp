#include<iostream>
using namespace std;

int & fn() {
  static int a = 10; // 静态局部变量，生命周期贯穿整个程序
  return a; // 返回a的引用
}

int main() {
  int &ref = fn(); // ref是fn()返回的引用，ref和a是同一个变量的别名
  cout << "ref: " << ref << endl; // 输出10
  ref = 20; // 修改ref会修改a
  cout << "ref: " << ref << endl; // 输出20
  cout << "fn(): " << fn() << endl; // 输出20，说明fn()返回的引用指向的变量已经被修改
  fn() = 30; // 可以通过函数返回的引用修改静态变量
  cout << "fn(): " << fn() << endl; // 输出30
  cout << "ref:" << ref << endl;
  return 0;
}