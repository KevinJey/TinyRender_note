all:main.o model.o tgaimage.o geometry.o main.o
	g++ -o simple main.o model.o tgaimage.o geometry.o
model.o:model.cpp
	g++ -o model.o -c model.cpp
tgaimage.o:tgaimage.cpp	
	g++ -o tgaimage.o -c tgaimage.cpp
geometry.o:geometry.cpp
	g++ -o geometry.o -c geometry.cpp
main.o:main.cpp
	g++ -c main.cpp -o main.o
clean:
	rm  ./*.o