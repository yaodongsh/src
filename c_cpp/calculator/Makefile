main: main.o Calculator.o Input.o StackSeq.o IStack.o
	g++ -o main main.o Calculator.o Input.o StackSeq.o IStack.o
main.o: main.cpp
	g++ -c main.cpp
Calculator.o: Calculator.h Calculator.cpp
	g++ -c Calculator.cpp
Input.o: Input.h Input.cpp
	g++ -c Input.cpp
StackSeq.o: StackSeq.h StackSeq.cpp
	g++ -c StackSeq.cpp
IStack.o: IStack.h IStack.cpp
	g++ -c IStack.cpp  
clean:
	rm -rf *.o main
