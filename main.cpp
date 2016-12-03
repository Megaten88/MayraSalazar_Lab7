#include "User.h"
#include "Admin.h"
#include "Manager.h"
#include "Intern.h"
#include "Supervisor.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

Admin* admin = new Admin("Mayra","mayrasalazar@unitec.edu","mayrasalazar0210","10/5/1997");
vector<User*>users;
void writeFile();
void readAdmin();
void readManagers();
void readInterns();
void readSupervisors();
int main(int argc, char const *argv[])
{
	/*readSupervisors();
	readInterns();
	readManagers();*/
	int opcion = 0;
	while(opcion!=2){
		cout<<"------LOG IN-------\n 1)Login\n 2)Salir del sistema \n Elija su opcion: \n";
		cin>>opcion;
		if (opcion==1)
		{
			string name;
			string email;
			string password;
			string user;
			string contra;
			bool isAdmin;
			bool isManager;
			bool isIntern;
			bool isSupervisor;
			cout<<"Ingrese nombre de usuario: ";
			cin>>user;
			cout<<"Ingrese contraseña: ";
			cin>>contra;
			if (user == admin->getName() && contra == admin->getPassword())
			{
				isAdmin = true;
			}else{
				for (int i = 0; i < users.size(); ++i)
				{
					if (user == users.at(i)->getName() && contra == users.at(i)->getPassword())
					{
						if(dynamic_cast<Manager*> (users.at(i))!=NULL){
	    					isManager = true;
			    		}else if(dynamic_cast<Intern*> (users.at(i))!=NULL){
			    			isIntern = true;
			    		}else if(dynamic_cast<Supervisor*> (users.at(i))!=NULL){
			    			isSupervisor = true;
			    		}
					}
				}
			}
			int op = 0;
			if(isAdmin){
				int userIs;
				while(op!= 3){
					cout<<"1) Agregar usuarios\n 2)Eliminar Usuarios\n 3)Logout\n Elija una opción: ";
					cin>>op;
					if(op == 1){
						cout<<"\n1)Manager\n 2)Intern\n 3)Supervisor\n Elija su opción: "<<endl;
						cin>>userIs;
						if (userIs == 1)
						{
							double salario;
							cout<<"Nombre: "<<endl;
							cin>>name;
							cout<<"Correo: "<<endl;
							cin>>email;
							cout<<"Contraseña: "<<endl;
							cin>>password;
							if (password.length() == 16)
							{
								cout<<"Salario: "<<endl;
								cin>>salario;
								users.push_back(new Manager(name,email,password,salario));
							}else{
								cout<<"La contraseña no es válida."<<endl;
							}
						}else if (userIs == 2){
							int dias;
							cout<<"Nombre: "<<endl;
							cin>>name;
							cout<<"Correo: "<<endl;
							cin>>email;
							cout<<"Contraseña: "<<endl;
							cin>>password;	
							if (password.length() == 8)
							{
								cout<<"Dias: "<<endl;
								cin>>dias;
								users.push_back(new Intern(name,email,password,dias));
							}else{
								cout<<"La contraseña no es válida."<<endl;
							}
						}else if(userIs == 3){
							cout<<"Nombre: "<<endl;
							cin>>name;
							cout<<"Correo: "<<endl;
							cin>>email;
							cout<<"Contraseña: "<<endl;
							cin>>password;
							if (password.length() == 8)
							{
								users.push_back(new Supervisor(name,email,password));	
							}else{
								cout<<"La contraseña no es válida."<<endl;
							}
						}else{
							cout<<"Ingresó una opción inválida."<<endl;
						}
					}else if(op == 2){
						int pos = 0;
						for (int i = 0; i < users.size(); ++i)
						{
							cout<<i<<")"<<users.at(i)->getName()<<endl;
						}
						cout<<"Ingrese la posición: ";
						cin>>pos;
						users.erase(users.begin()+pos);
					}else{
						cout<<"Ingresó una opción inválida."<<endl;
					}
				}
			}else if(isManager){
				int userIs;
				while(op!= 3){
					cout<<"1) Agregar usuarios\n 2)Eliminar Usuarios\n 3)Logout\n Elija una opción: ";
					cin>>op;
					if(op == 1){
						cout<<"\n1)Intern\n 2)Supervisor\n Elija su opción: "<<endl;
						cin>>userIs;
						if (userIs == 1){
							int dias;
							cout<<"Nombre: "<<endl;
							cin>>name;
							cout<<"Correo: "<<endl;
							cin>>email;
							cout<<"Contraseña: "<<endl;
							cin>>password;
							if (password.length() == 8)
							{
								cout<<"Dias: "<<endl;
								cin>>dias;
								users.push_back(new Intern(name,email,password,dias));
							}else{
								cout<<"La contraseña no es válida."<<endl;
							}	
						}else if(userIs == 2){
							cout<<"Nombre: "<<endl;
							cin>>name;
							cout<<"Correo: "<<endl;
							cin>>email;
							cout<<"Contraseña: "<<endl;
							cin>>password;
							if (password.length() == 8)
							{
								users.push_back(new Supervisor(name,email,password));	
							}else{
								cout<<"La contraseña no es válida."<<endl;
							}
						}else{
							cout<<"Ingresó una opción inválida."<<endl;
						}
					}else if(op == 2){
						int pos = 0;
						for (int i = 0; i < users.size(); ++i)
						{
							cout<<i<<")"<<users.at(i)->getName()<<endl;
						}
						cout<<"Ingrese la posición: ";
						cin>>pos;
						if (dynamic_cast<Manager*> (users.at(pos))!=NULL)
						{
							cout<<"No puede borrar un Manager."<<endl;
						}else{
							users.erase(users.begin()+pos);
						}
					}else{
						cout<<"Ingresó una opción inválida."<<endl;
					}
				}
			}else if(isIntern){
				int userIs;
				while(op!= 3){
					cout<<"1) Ver Usuarios Intern \n 2)Eliminar Usuarios Intern \n 3)Logout\n Elija una opción: ";
					cin>>op;
					if(op == 1){
						for (int i = 0; i < users.size(); ++i)
						{
							if (dynamic_cast<Intern*> (users.at(i))!=NULL)
							{
								cout<<i<<")"<<users.at(i)->getName()<<endl;
							}
						}
					}else if(op == 2){
						int pos = 0;
						for (int i = 0; i < users.size(); ++i)
						{
							cout<<i<<")"<<users.at(i)->getName()<<endl;
						}
						cout<<"Ingrese la posición: ";
						cin>>pos;
						if (dynamic_cast<Manager*> (users.at(pos))!=NULL || dynamic_cast<Supervisor*> (users.at(pos))!=NULL)
						{
							cout<<"No puede borrar el user."<<endl;
						}else{
							users.erase(users.begin()+pos);
						}
					}else if(op ==3){
						cout<<"Salió"<<endl;
					}else{
						cout<<"Ingresó una opción inválida."<<endl;
					}
				}
			}else if(isSupervisor){
				int userIs;
				while(op!= 2){
					cout<<"1) Ver Usuarios Intern \n 2)Logout\n Elija una opción: ";
					cin>>op;
					if(op == 1){
						for (int i = 0; i < users.size(); ++i)
						{
							cout<<i<<")"<<users.at(i)->toString()<<endl;
						}
					}else if(op == 2){
						cout<<"Salió."<<endl;
					}else{
						cout<<"Ingresó una opción inválida."<<endl;
					}
				}
			}else{
				cout<<"No existe el user."<<endl;
			}
			op = 0;
			isAdmin = false;
			isManager = false;
			isIntern = false;
			isSupervisor = false;
		}else if(opcion ==2){
			cout<<"Salió."<<endl;
			return 1;
		}else{
			cout<<"Ingresó una opcion no válida."<<endl;
		}
	}
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
	string name;
	string correo;
	string password;
	ifstream supervisors;
	supervisors.open("Supervisors.txt");
	if(supervisors.fail()){
		cout<<"Falló el archivo."<<endl;
	}else{
		while(!supervisors.eof()){
			getline(supervisors, name,';');
			getline(supervisors, correo,';');
			getline(supervisors, password,';');
			users.push_back(new Supervisor(name,correo,password));
		}
	}
	supervisors.close();
}
