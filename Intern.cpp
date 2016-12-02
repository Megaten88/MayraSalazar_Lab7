#include "Intern.h"
#include "User.h"
#include <string>
#include <sstream>
using std::stringstream;
using std::string;

Intern::Intern(string nombre,string correo,string contra, int dias):User(nombre,correo,contra){
	workDays = dias;
	setArray();
}
void Intern::setWorkDays(int dias){
	workDays = dias;
}
int Intern::getWorkDays(){
	return workDays;
}
Intern::~Intern(){
	delete arrayPass;
}
void Intern::setArray(){
	arrayPass = new int[8];
	for (int i = 0; i < 8; ++i)
	{
		arrayPass[i] = password.at(i);
	}
}
string Intern::toString(){
	stringstream ss;
	ss<<name<<" "<<email<<" "<<password<<" "<<workDays<<" ";
	return ss.str();
}