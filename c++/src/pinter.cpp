#include <iostream>

using namespace std;

int main() {
    int* p = nullptr; // 初始化指针为nullptr
    int value = 42;
    p = &value; // 指针指向变量value的地址

    cout << "Value: " << *p << endl; // 通过指针访问值

    *p = 100; // 通过指针修改值
    cout << "Modified Value: " << value << endl; // 输出修改后的值
    cout << "Size of Pointer: " << sizeof(p) << " bytes and double point type:" << sizeof(double *)<< endl; // 输出指针大小

    cout << "Pointer Address: " << p  << ":" << &p <<":" << &value << endl; // 输出指针地址

    return 0;
}