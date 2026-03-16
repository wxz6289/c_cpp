#include<iostream>
using namespace std;

int* fun(){
  int* p = new int(10); // 在堆上分配一个整数并初始化为10

  int *arr = new int[10]; // 在堆上分配一个整数数组
  for (int i = 0; i < 10; ++i) arr[i] = i; // 初始化数组
  delete[] arr; // 释放数组内存

  return p; // 返回指向该整数的指针
}

int main() {
  int* p = fun(); // 获取指向堆上整数的指针
  cout << *p << endl; // 输出10
  cout << *p << endl; // 输出10
  delete p; // 释放堆内存，防止内存泄漏
  cout << *p << endl; // 输出10
  return 0;
}