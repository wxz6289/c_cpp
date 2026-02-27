#include <iostream>

void swap(int &x, int &y);
void swap2(int *x, int *y);
void swap3(int x, int y);

int main() {
    int a = 5;
    int b = 10;
    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    int c = 15;
    int d = 20;
    std::cout << "Before swapping: c = " << c << ", d = " << d << std::endl;
    swap2(&c, &d);
    std::cout << "After swapping: c = " << c << ", d = " << d << std::endl;

    int e = 25;
    int f = 30;
    std::cout << "Before swapping: e = " << e << ", f = " << f << std::endl;
    swap3(e, f);
    std::cout << "After swapping: e = " << e << ", f = " << f << std::endl;
    return 0;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap2(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap3(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

