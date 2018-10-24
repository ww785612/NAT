all:
	g++ -std=c++11 -o main main.cpp
clean:
	rm -rf main
	rm RESULT.txt