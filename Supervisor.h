#pragma once
#include "User.h"
#include <string>
using std::string;
class Supervisor:public User
{
private:
	int countDays;
public:
	Supervisor(string, string, string);
	void setCountDays();
	int  getCountDays();
	virtual~Supervisor();
	virtual void setArray();
	virtual string toString();	
};