#pragma once
#include "User.h"
#include <string>
using std::string;
class Manager:public User
{
private:
	double salary;
public:
	Manager(string,string,string,double);
	virtual ~Manager();
	void setSalary(double);
	double getSalary();
	virtual void setArray();
	virtual string toString();
	
};