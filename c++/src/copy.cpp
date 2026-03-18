#include<iostream>
using namespace std;

class Person {
  public:
    string name;
    int* age;
    Person(string name, int age) : name(name), age(new int(age)) {}
    Person(const Person& p) : name(p.name), age(new int(*p.age)) {
      cout << "Copy constructor called for " << name << endl;
    }
    ~Person() {
      if(age != nullptr)
        delete age;
      cout << "Destructor called for " << name << endl;
    }
};

int main() {
  Person p1("Alice", 30);
  Person p2 = p1; // Copy constructor is called
  cout << "p1: " << p1.name << ", age: " << *p1.age << endl;
  cout << "p2: " << p2.name << ", age: " << *p2.age << endl;
  p2.age = new int(35); // Modify p2's age
  cout << "After modifying p2's age:" << endl;
  cout << "p1: " << p1.name << ", age: " << *p1.age << endl; // p1's age should remain unchanged
  cout << "p2: " << p2.name << ", age: " << *p2.age << endl;
  return EXIT_SUCCESS;
}