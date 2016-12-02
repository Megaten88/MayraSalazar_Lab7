#include "Supervisor.h"
#include "User.h"
#include <string>
#include <sstream>
using std::stringstream;
using std::string;

Supervisor::Supervisor(string nombre, string correo, string contra):User(nombre,correo,contra){
	countDays = 0;
	setArray();
}
void Supervisor::setCountDays(){
	countDays++;
}
int Supervisor::getCountDays(){
	return countDays;
}
Supervisor::~Supervisor(){
	delete arrayPass;
}
void Supervisor::setArray(){
	arrayPass = new int[8];
	for (int i = 0; i < 8; ++i)
	{
		arrayPass[i] = password.at(i);
	}
}
string Supervisor::toString(){
	stringstream ss;
	ss<<name<<";"<<email<<";"<<password<<";"<<countDays<<";\n";
	return ss.str();
}