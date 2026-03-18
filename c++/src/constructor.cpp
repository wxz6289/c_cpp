#include<iostream>
using namespace std;

class Point
{
    private:
        int x;
        int y;
    public:
      Point() {
        this->x = 0;
        this->y = 0;
        cout << "Default constructor called for Point(" << x << "," << y << ")" << endl;
      };
      Point(int x, int y) {
        this->x = x;
        this->y = y;
        cout << "Parameterized constructor called for Point(" << x << "," << y << ")" << endl;
      };
      Point(const Point& p) {
        this->x = p.x;
        this->y = p.y;
        cout << "Copy constructor called for Point(" << x << "," << y << ")" << endl;
      };
      ~Point() {
        cout<<"Destructor called for Point("<<x<<","<<y<<")"<<endl;
      }
};

void test(Point p) {
  cout << "Inside test function" << endl;
}

Point createPoint() {
  Point p(5, 6);
  cout << "Inside createPoint function" << endl;
  cout << "ptr createPoint: " << &p << endl; // Print the address of the local variable
  return p; // Return by value, will invoke copy constructor
}

int main() {
  // 无参构造函数不能加()，否则会被当作函数声明
  // Point p0;
  // Point p1(1, 2); //匿名对象，执行完立即释放对象
  // Point p2 = p1; // 隐式转换
  // Point p3(p2);
  Point p4 = Point(3, 4); // Copy constructor is called
  test(p4); // Copy constructor is called
  Point p5 = createPoint(); // Copy constructor is called
  cout << "ptr main: " << &p5 << endl; // Print the address of the returned object
  return EXIT_SUCCESS;
}