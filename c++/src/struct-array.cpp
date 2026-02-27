#include<iostream>
using namespace std;

struct Student {
  string name;
  int age;
  int score;
};

int main() {
  Student students[3] = {
    {"Alice", 20, 85},
    {"Bob", 22, 90},
    {"Charlie", 21, 88}
  };

  for (int i = 0; i < 3; i++) {
    cout << "Name: " << students[i].name << endl;
    cout << "Age: " << students[i].age << endl;
    cout << "Score: " << students[i].score << endl;
  }

  return 0;
}
