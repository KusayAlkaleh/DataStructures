all: derle bagla

derle:
	g++ -g -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -g -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -g -c -I "./include" ./src/IkiliAramaAgac.cpp -o ./lib/IkiliAramaAgac.o
bagla:
	g++ -g ./lib/IkiliAramaAgac.o ./lib/Dugum.o ./lib/main.o -o ./bin/program.exe
