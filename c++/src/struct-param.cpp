#include<iostream>
using namespace std;

struct Student {
  string name;
  int age;
  int score;
};

void printStudent(Student s);
void printStudent(Student *s);

int main() {
  Student s1;
  s1.name = "Alice";
  s1.age = 20;
  s1.score = 85;
  Student *s2 = &s1;

  printStudent(s1);
  printStudent(&s1);
  printStudent(s2);
  return 0;
}

void printStudent(Student s) {
  cout << "Name: " << s.name << endl;
  cout << "Age: " << s.age << endl;
  cout << "Score: " << s.score << endl;
  s.name = "Changed Name";
}

void printStudent(Student *s) {
  cout << "Name: " << s->name << endl;
  cout << "Age: " << s->age << endl;
  cout << "Score: " << s->score << endl;
  s->name = "Changed Name via Pointer";
}