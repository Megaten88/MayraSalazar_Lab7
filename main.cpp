#include "User.h"
#include "Admin.h"
#include "Manager.h"
#include "Intern.h"
#include "Supervisor.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

Admin* admin = new Admin("Mayra","mayrasalazar@unitec.edu","mayrasalazar0210","10/5/1997");
User* login;
vector<User*>users;
void writeFile();
void readAdmin();
void readManagers();
void readInterns();
void readSupervisors();
int main(int argc, char const *argv[])
{
	/*int opcion;
	cout<<<"------LOG IN-------\n 1)Login\n 2)Logout\n Elija su opcion: \n";
	cin>>opcion;
	*/
	users.push_back(new Manager("ewe", "holita@hola.com", "ewewewewewewwewe",22.5));
	users.push_back(new Manager("nana","asja","mayrasal44444444",3.5));
	writeFile();
	for (int i = 0; i < users.size(); ++i){
	    users.erase(users.begin() + i);
	}
    users.clear();
    readAdmin();
    readManagers();

    for (int i = 0; i < users.size(); ++i)
    {
    	cout<<users.at(i)->toString()<<endl;
    	cout<<users.at(i)->getName()<<endl;
    }
    for (int i = 0; i < users.size(); ++i){
	    users.erase(users.begin() + i);
	}
    users.clear();
	return 0;
}
void writeFile(){
	ofstream administrador;
	ofstream managers;
	ofstream interns;
	ofstream supervisors;
    administrador.open("Administrador.txt");
    managers.open("Managers.txt");
    interns.open("Interns.txt");
    supervisors.open("Supervisors.txt");
    if(admin!= NULL){
    	administrador<< admin-> toString();
    }
    if (users.size()>0)
    {
    	for (int i = 0; i < users.size(); ++i)
    	{
    		if(dynamic_cast<Manager*> (users.at(i))!=NULL){
    			managers<<users.at(i)->toString()<<endl;
    		}else if(dynamic_cast<Intern*> (users.at(i))!=NULL){
    			interns<<users.at(i)->toString()<<endl;
    		}else{
    			supervisors<<users.at(i)->toString()<<endl;
    		}
    	}

    }
    administrador.close();
    managers.close();
	interns.close();
	supervisors.close();
}
void readAdmin(){
	string fecha;
	string name;
	string correo;
	string password;
	ifstream admins;
	admins.open("Administrador.txt");
	if(admins.fail()){
		cout<<"Falló el archivo."<<endl;
	}else{
		while(!admins.eof()){
			getline(admins, name,';');
			getline(admins, correo,';');
			getline(admins, password,';');
			getline(admins, fecha,';');
			admin = new Admin(name,correo,password,fecha);
		}
	}
	admins.close();
}
void readManagers(){
	string salario;
	string name;
	string correo;
	string password;
	ifstream managers;
	managers.open("Managers.txt");
	if(managers.fail()){
		cout<<"Falló el archivo."<<endl;
	}else{
		while(!managers.eof()){
			getline(managers, name,';');
			getline(managers, correo,';');
			getline(managers, password,';');
			getline(managers, salario,';');
			users.push_back(new Manager(name,correo,password,atof(salario.c_str())));
		}
	}
	managers.close();
}
void readInterns(){
	string dias;
	string name;
	string correo;
	string password;
	ifstream interns;
	interns.open("Interns.txt");
	if(interns.fail()){
		cout<<"Falló el archivo."<<endl;
	}else{
		while(!interns.eof()){
			getline(interns, name,';');
			getline(interns, correo,';');
			getline(interns, password,';');
			getline(interns, dias,';');
			users.push_back(new Intern(name,correo,password,atoi(dias.c_str())));
		}
	}
	interns.close();
}
void readSupervisors(){
	string salario;
	string name;
	string correo;
	string password;
	ifstream managers;
	managers.open("Managers.txt");
	if(managers.fail()){
		cout<<"Falló el archivo."<<endl;
	}else{
		while(!managers.eof()){
			getline(managers, name,';');
			getline(managers, correo,';');
			getline(managers, password,';');
			getline(managers, salario,';');
			users.push_back(new Manager(name,correo,password,atof(salario.c_str())));
		}
	}
	managers.close();
}
