#include<iostream>
using namespace std;

struct Student {
  string name;
  int age;
  int score;
};

int main() {
  Student *s1 = new Student; // Dynamically allocate memory for a Student object
  s1->name = "Alice";
  s1->age = 20;
  s1->score = 85;

  cout << "Name: " << s1->name << endl;
  cout << "Age: " << s1->age << endl;
  cout << "Score: " << s1->score << endl;

  cout << "Name: " << (*s1).name << endl; // Accessing members using dereference operator
  cout << "Age: " << (*s1).age << endl;
  cout << "Score: " << (*s1).score << endl;

  delete s1; // Free the allocated memory

  return 0;
}