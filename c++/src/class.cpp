#include<iostream>
#include<string>
using namespace std;

class Person {
    public:
        Person(const string &name, int age) : name(name), age(age) {}
        void introduce() const {
            cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
        }
        void setAge(int newAge) {
            age = newAge;
        }
        int getAge() const {
            return age;
        }
        ~Person() {
            cout << "Person " << name << " is being destroyed." << endl;
        }
        string name;

   private:
        int age;

};

int main() {
    string name = "Alice";
    Person p(name, 30);
    p.introduce();
    p.name = "Bob"; // 可以修改public成员
    // p.age = 25; // 错误：age是private成员，无法访问
    p.setAge(25); // 通过public成员函数修改private成员
    p.introduce();
    cout << "Person's name is: " << p.name << endl;
    cout << "Person's age is: " << p.getAge() << endl;
    cout << "name: " << name << endl; // 错误：age是private成员，无法访问
    // cout << "Person's age is: " << p.age << endl;
    return 0;
}