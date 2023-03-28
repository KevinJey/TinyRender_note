all: main.o tgaimage.o
	g++ -o simple main.o tgaimage.o
main.o: main.cpp
	g++ -o main.o -c main.cpp
tgaimage.o: tgaimage.cpp
	g++ -o tgaimage.o -c tgaimage.cpp
clean:
	rm simple main.o tgaimage.o
