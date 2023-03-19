all: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/ListeDugum.cpp -o ./lib/ListeDugum.o
	g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o
bagla:
	g++ ./lib/Dugum.o ./lib/Kuyruk.o ./lib/Radix.o ./lib/ListeDugum.o ./lib/Liste.o ./lib/main.o -o ./bin/program.exe

calistir:
	./bin/program.exe
