@all:
	g++ -c object.cpp -o object.o
	g++ -c utils.cpp -o utils.o
	g++ -c main.cpp -o main.o
	g++ main.o object.o utils.o -o main.exe

run:
	./main.exe

clean:
	rm -f *.o *.e
