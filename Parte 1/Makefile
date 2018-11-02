all: Graph
Graph: Graph.o main.o
	g++ Graph.o main.o 
Graph.o: Graph.cpp
	g++ -o Graph.o -c Graph.cpp -W -Wall -ansi -pedantic
main.o: main.cpp Graph.h
	g++ -o main.o -c main.cpp -W -Wall -ansi -pedantic
clean:
	rm -rf *.o
mrproper: clean
	rm -rf Graph
