all: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/DinamikDizi.cpp -o ./lib/DinamikDizi.o

bagla:
	g++ ./lib/DinamikDizi.o ./lib/main.o -o ./bin/program.exe

calistir:
	./bin/program.exe
