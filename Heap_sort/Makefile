all: derle bagla

derle:
	g++ -g -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -g -c -I "./include" ./src/HeapSort.cpp -o ./lib/HeapSort.o
bagla:
	g++ -g ./lib/HeapSort.o ./lib/main.o -o ./bin/program.exe
