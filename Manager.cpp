#include "Manager.h"
#include "User.h"
#include <string>
#include <sstream>
using std::stringstream;
using std::string;

Manager::Manager(string nombre, string correo, string contra, double salario):User(nombre,correo,contra){
	salary = salario;
	setArray();
}
Manager::~Manager(){
	delete arrayPass;
}
void Manager::setSalary(double salario){
	salary = salario;
}
double Manager::getSalary(){
	return salary;
}
void Manager::setArray(){
	arrayPass = new int[16];
	for (int i = 0; i < 16; ++i)
	{
		arrayPass[i] = password.at(i);
	}
}
string Manager::toString(){
	stringstream ss;
	ss<<name<<" "<<email<<" "<<password<<" "<<salary<<" ";
	return ss.str();
}