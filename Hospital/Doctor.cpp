#include "Doctor.h"

void Doctor::setName(const string& name)
{
	if (name.empty() )//|| name.size() <= 3 || name.size() > 50)
	{
		throw InvalidNameException("Name must be not empty");
		return;
	}
	else if (name.size() < 3)
	{
		throw InvalidNameException("Name must be more than 3 symbols");
	}
	else if (name.size() > 50)
	{
		throw InvalidNameException("Name must be less than 50 symbols");
	}
	this->name = name;
}

void Doctor::setLastName(const string& last_name)
{
	if (name.empty())//|| name.size() <= 3 || name.size() > 50)
	{
		throw InvalidLastNameException("Name must be not empty");
		return;
	}
	else if (name.size() < 3)
	{
		throw InvalidNameException("Name must be more than 3 symbols");
	}
	else if (name.size() > 50)
	{
		throw InvalidNameException("Name must be less than 50 symbols");
	}
	this->last_name = last_name;
}

void Doctor::setFatherName(const string& father_name)
{
	if (name.empty())//|| name.size() <= 3 || name.size() > 50)
	{
		throw InvalidFatherNameException("Name must be not empty");
		return;
	}
	else if (name.size() < 3)
	{
		throw InvalidFatherNameException("Name must be more than 3 symbols");
	}
	else if (name.size() > 50)
	{
		throw InvalidFatherNameException("Name must be less than 50 symbols");
	}
	this->father_name = father_name;
}

void Doctor::setAge(const int& age)
{
	if (age==0)
	{
		throw InvalidAgeException("Age must be more than 0");
	}
	this->age = age;
}

void Doctor::setVocation(const string& vocation)
{
	if (vocation.empty())
	{
		throw InvalidVacation("Vocation must be not empty");
	}
	else {
		this->vocation = vocation;
	}

}

const string& Doctor::getName() const
{
	return name;
	// TODO: insert return statement here
}

const string& Doctor::getLastName() const
{
	return last_name;
}

const string& Doctor::getFatherName() const
{
	return father_name;
}

const string& Doctor::getVocation() const
{
	return vocation;
}

const int& Doctor::getAge() const
{
	return age;
}

void Doctor::print() const
{
	cout << "-----Doctor-----" << endl
		<< "Name : " << name << endl
		<< "LastName : " << last_name << endl
		<< "FatherName : " << father_name << endl
		<< "Age : " << age << endl
		<< "Vocation : " << vocation << endl;
}
