#pragma once
#include <string>
using std::string;

class User
{
protected:
	string name;
	string email;
	string password;
	int* arrayPass;
public:
	User(string,string,string);
	void setName(string);
	string getName();
	void setEmail(string);
	string getEmail();
	void setPassword(string);
	string getPassword();
	virtual void setArray();
	virtual ~User();
	virtual string toString();
};