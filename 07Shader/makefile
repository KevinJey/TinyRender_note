simple: tgaimage.o geometry.o model.o our_gl.o main.o
	g++ -o simple tgaimage.o geometry.o model.o our_gl.o main.o

tgaimage.o:tgaimage.cpp	
	g++ -o tgaimage.o -c tgaimage.cpp
geometry.o:geometry.cpp	
	g++ -o geometry.o -c geometry.cpp
model.o:model.cpp
	g++ -o model.o -c model.cpp
our_gl.o:our_gl.cpp
	g++ -c our_gl.cpp -o our_gl.o
main.o:main.cpp
	g++ -c main.cpp -o main.o
clean:
	rm  ./*.o