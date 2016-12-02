#include "User.h"
#include <string>
using std::string;

User::User(string nombre, string correo, string contra){
	name = nombre;
	email = correo;
	password = contra;
}
void User::setName(string nombre){
	name = nombre;
}
string User::getName(){
	return name;
}
void User::setEmail(string correo){
	email = correo;
}
string User::getEmail(){
	return email;
}
void User::setPassword(string contra){
	password = contra;
}
string User::getPassword(){
	return password;
}
void User::setArray(){

}
User::~User(){
	delete arrayPass;
}
string User::toString(){

}
