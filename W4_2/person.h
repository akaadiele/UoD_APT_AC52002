#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);
	void setName(string name);
	string getName() const;
	void setAge(int age);
	int getAge() const;
	void display() const;
};

#endif // !PERSON_H
