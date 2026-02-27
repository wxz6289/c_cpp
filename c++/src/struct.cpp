#include <iostream>

using namespace std;

struct Student {
  string name;
  int age;
  int score;
} s3; // Global variable of type Student

int main() {
  Student s1;
  s1.name = "Alice";
  s1.age = 20;
  s1.score = 85;

  // struct 关键字可以省略，直接使用 Student 来定义变量
  struct Student s2 = {"Bob", 22, 90 };

  cout << "Name: " << s1.name << endl;
  cout << "Age: " << s1.age << endl;
  cout << "Score: " << s1.score << endl;

  cout << "Name: " << s2.name << endl;
  cout << "Age: " << s2.age << endl;
  cout << "Score: " << s2.score << endl;

  s3.name = "Charlie";
  s3.age = 21;
  s3.score = 88;

  cout << "Name: " << s3.name << endl;
  cout << "Age: " << s3.age << endl;
  cout << "Score: " << s3.score << endl;

  return 0;
}
