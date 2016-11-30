main: main.o Calculator.o Input.o StackSeq.o IStack.o
	g++ -g -o main main.o Calculator.o Input.o StackSeq.o IStack.o
main.o: main.cpp
	g++ -g -c main.cpp
Calculator.o: Calculator.h Calculator.cpp
	g++ -g -c Calculator.cpp
Input.o: Input.h Input.cpp
	g++ -g -c Input.cpp
StackSeq.o: StackSeq.h StackSeq.cpp
	g++ -g -c StackSeq.cpp
IStack.o: IStack.h IStack.cpp
	g++ -g -c IStack.cpp  
clean:
	rm -rf *.o main
