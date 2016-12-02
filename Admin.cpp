#include "Admin.h"
#include "User.h"
#include <string>
#include <sstream>
using std::stringstream;
using std::string;

Admin::Admin(string nombre, string correo, string contra, string fecha): User(nombre,correo,contra){
	date = fecha;
	setArray();
}
void Admin::setDate(string fecha){
	date = fecha;
}
string Admin::getDate(){
	return date;
}
Admin::~Admin(){
	delete arrayPass;
}
void Admin::setArray(){
	arrayPass = new int[16];
	for (int i = 0; i < 16; ++i)
	{
		arrayPass[i] = password.at(i);
	}
}
string Admin::toString(){
	stringstream ss;
	ss<<name<<";"<<email<<";"<<password<<";"<<date<<";\n";
	return ss.str();
}