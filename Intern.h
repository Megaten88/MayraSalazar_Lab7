#pragma once
#include "User.h"
#include <string>
using std::string;

class Intern:public User
{
private: 
	int workDays;
public:
	Intern(string,string,string,int);
	void setWorkDays(int);
	int getWorkDays();
	virtual ~Intern();
	virtual void setArray();
	virtual string toString();
};