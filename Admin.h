#pragma once
#include "User.h"
#include <string>
using std::string;
class Admin: public User
{
private:
	string date;
public:
	Admin(string,string,string,string);
	void setDate(string);
	string getDate();
	virtual ~Admin();
	virtual void setArray();
	virtual string toString();
};