#include<iostream>
using namespace std;

struct Student {
  string name;
  int age;
  int score;
};

struct Class {
  string name;
  Student students[3];
};

int main() {
  Class class1;
  class1.name = "Class A";
  class1.students[0] = {"Alice", 20, 85};
  class1.students[1] = {"Bob", 21, 90};
  class1.students[2] = {"Charlie", 19, 80};

  cout << "Class Name: " << class1.name << endl;
  for (int i = 0; i < 3; i++) {
    cout << "Student " << i + 1 << ": " << class1.students[i].name
         << ", Age: " << class1.students[i].age
         << ", Score: " << class1.students[i].score << endl;
  }

  return 0;
}