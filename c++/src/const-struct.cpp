#include<iostream>
using namespace std;

struct Student {
  string name;
  int age;
  int score;
};

void printStudent(const Student *s);

int main() {
  Student s1 = { "King", 20, 85 };
  Student s2 = { "Queen", 22, 90 };
  Student *s = &s2;
  printStudent(&s1);
  printStudent(s);
  return 0;
}

void printStudent(const Student *s) {
  cout << "Name: " << s->name << endl;
  cout << "Age: " << s->age << endl;
  cout << "Score: " << s->score << endl;
  // s->name = "Changed Name"; // Error: cannot modify a const reference
}