all: main.o model.o tgaimage.o
	g++ -o simple main.o model.o tgaimage.o
main.o:main.cpp
	g++ -o main.o -c main.cpp
model.o:model.cpp
	g++ -o model.o -c model.cpp
tgaimage.o: tgaimage.cpp
	g++ -o tgaimage.o -c tgaimage.cpp
clean:
	rm  *.o