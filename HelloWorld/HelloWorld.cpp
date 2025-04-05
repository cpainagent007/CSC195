
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

string line = "----------";

class Person{
public:
    std::string name;
    int age;
    float weight;
    void f(){}
};

int main() {
    Student student;
    student.SetName("Test");
    student.Write();

    //----------
    cout << line << endl;
    //----------

    Person person;
    person.age = 20;

    unsigned int i = -23;
    printf("%d\n", i);
    std::cout << i << std::endl;

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(person) << std::endl;

    char c = 'A';
    cout << (int)c << endl;

    int firstInit = 67;
    cout << firstInit << endl;
    cout << (char)firstInit << endl;
    cout << &firstInit << endl;

    firstInit++;

    cout << firstInit << endl;
    cout << ++firstInit << endl;
    cout << firstInit-- << endl;
    cout << firstInit << endl;

    //----------
    cout << line << endl;
    //----------

    f();

    cout << "Hello, World!" << endl;
    cout << "Git is now tracking this project!" << endl;

    return 0;
}