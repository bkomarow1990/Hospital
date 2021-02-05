#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person abstract
{
public:
	Person(const string& name="NoName",const string& last_name="NoLastName",const string&father_name="NoFatherName",const int & age=18)
		:name(name),last_name(last_name),father_name(father_name),age(age)
	{}
	virtual void setName(const string& name)=0;
	virtual void setLastName(const string& last_name)=0;
	virtual void setFatherName(const string& father_name)=0;
	virtual void setAge(const int& age)=0;
	virtual const string& getName()const=0;
	virtual const string& getLastName()const=0;
	virtual const string& getFatherName()const=0;
	virtual const int& getAge()const=0;
	virtual void print()const=0;
protected:
	string name;
	string last_name;
	string father_name;
	int age;
};

