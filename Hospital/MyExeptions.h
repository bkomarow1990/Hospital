#pragma once
#include <iostream>
using namespace std;
class MyException
{
public:
	MyException(const  string& errMessage = "Unknown error!")
		: errMessage{ errMessage }
	{}
	virtual const string& what() const
	{
		return errMessage;
	}
private:
	string  errMessage;
};
class InvalidNameException : public MyException
{
public:
	InvalidNameException(const  string& message = "Error name!")
		: MyException(message)
	{}
	// what()
}; 
class InvalidLastNameException : public MyException
{
public:
	InvalidLastNameException(const  string& message = "Error lastname!")
		: MyException(message)
	{}
	// what()
};
class InvalidFatherNameException : public MyException
{
public:
	InvalidFatherNameException(const  string& message = "Error fathername!")
		: MyException(message)
	{}
	// what()
};
class InvalidAgeException : public MyException
{
public:
	InvalidAgeException(const  string& message = "Error Age!")
		: MyException(message)
	{}
	// what()
};
class InvalidVacation : public MyException
{
public:
	InvalidVacation(const  string& message = "Error Age!")
		: MyException(message)
	{}
	// what()
};
class InvalidArgumentChoise : public MyException
{
public:
	InvalidArgumentChoise(const  string& message = "Invalid type choice!")
		: MyException(message)
	{}
	// what()
};