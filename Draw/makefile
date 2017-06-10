run:main.o Draw.o
	g++ -o run main.o Draw.o
main.o:main.cc
	g++ -c main.cc -I./
Draw.o:Draw.cc
	g++ -c Draw.cc -I./
clean:
	rm run main.o Draw.o
