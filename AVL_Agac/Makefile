all: derle bagla

derle:
	g++ -g -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -g -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -g -c -I "./include" ./src/AVLAgac.cpp -o ./lib/AVLAgac.o
bagla:
	g++ -g ./lib/Dugum.o ./lib/AVLAgac.o ./lib/main.o -o ./bin/program.exe
