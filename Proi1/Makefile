all: program

program: main.o Unit.o Formation.o Fleet.o FleetManager.o
	g++ -o program main.o Unit.o Formation.o Fleet.o FleetManager.o

main.o: main.cpp Unit.h Formation.h Fleet.h FleetManager.h
	g++ -c main.cpp

Unit.o: Unit.cpp Unit.h Formation.o
	g++ -c Unit.cpp

Formation.o: Formation.cpp Formation.h Unit.h
	g++ -c Formation.cpp

Fleet.o: Fleet.cpp Fleet.h Formation.h Unit.h
	g++ -c Fleet.cpp

FleetManager.o: FleetManager.cpp FleetManager.h Formation.h Unit.h Fleet.h
	g++ -c FleetManager.cpp

clean:
	rm -rf *o program
