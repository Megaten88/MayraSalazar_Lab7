main: Admin.o Manager.o Intern.o Supervisor.o main.o
	g++ Admin.o Manager.o Intern.o Supervisor.o main.o -o main

main.o: Admin.h Manager.h Intern.h Supervisor.h main.cpp
	g++ -c main.cpp

Admin.o: Admin.h Admin.cpp User.h
	g++ -c Admin.cpp

Manager.o: Manager.h Manager.cpp User.h
	g++ -c Manager.cpp

Intern.o: Intern.h Intern.cpp User.h
	g++ -c Intern.cpp

Supervisor.o: Supervisor.h Supervisor.cpp User.h
	g++ -c Supervisor.cpp

clean:
	rm -f *.o main