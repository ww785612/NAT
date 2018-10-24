all: NATTable.o
	g++ -std=c++11 -o main NATTable.o main.cpp
NATTable.o:
	g++ -std=c++11 -c NATTable.cpp
clean:
	rm -rf *.o
	rm -rf main
	rm RESULT.txt
