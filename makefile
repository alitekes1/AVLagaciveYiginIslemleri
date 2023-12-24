all: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/avlAgaci.cpp -o ./lib/avlAgaci.o
	g++ -c -I "./include" ./src/dugum.cpp -o ./lib/dugum.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/yigin.cpp -o ./lib/yigin.o
	g++ -c -I "./include" ./src/agacIslemleri.cpp -o ./lib/agacIslemleri.o

bagla: derle
	g++ ./lib/dugum.o ./lib/avlAgaci.o ./lib/yigin.o ./lib/agacIslemleri.o ./lib/main.o  -o ./bin/program

calistir: bagla
	./bin/program

