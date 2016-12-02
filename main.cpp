#include "User.h"
#include "Admin.h"
#include "Manager.h"
#include "Intern.h"
#include "Supervisor.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Admin* admin = new Admin("Mayra","mayrasalazar@unitec.edu","mayrasalazar0210","10/5/1997");
User* login;
vector<User*>users;
void writeFile();
int main(int argc, char const *argv[])
{
	users.push_back(new Manager("ewe", "holita@hola.com", "ewewewewewewwewe",22.5));
	users.push_back(new Intern("nana","asja","mayrasal",3));
	writeFile();
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