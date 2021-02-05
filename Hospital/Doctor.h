#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "MyExeptions.h"
using namespace std;
class Doctor : public Person
{
public:
	Doctor(const string& name = "NoName", const string& last_name = "NoLastName", const string& father_name = "NoFatherName", const int& age = 18,const string& vocation="NoVacation")
		:Person()
	{
		setName(name);
		setLastName(last_name);
		setFatherName(father_name);
		setAge(age);
		setVocation(vocation);
	}
	virtual void setName(const string& name) override;
	virtual void setLastName(const string& last_name) override;
	virtual void setFatherName(const string& father_name) override;
	virtual void setAge(const int& age) override;
	virtual void setVocation(const string& vocation);
	virtual const string& getName()const override;
	virtual const string& getLastName()const override;
	virtual const string& getFatherName()const override;
	virtual const string& getVocation()const;
	virtual const int& getAge()const override;
	virtual void print()const override;
protected:
	string vocation;
};

