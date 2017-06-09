run:main.o Thread.o ThreadCond.o ThreadPool.o
	g++ -o run main.o Thread.o ThreadCond.o ThreadPool.o  -lpthread -g -Wall
main.o:main.cc CMutex.h
	g++ -c main.cc  -g
Thread.o:Thread.cc
	g++ -c Thread.cc -g
ThreadCond.o:ThreadCond.cc
	g++ -c ThreadCond.cc -g
ThreadPool.o:ThreadPool.cc
	g++ -c ThreadPool.cc -g
clean:
	rm run main.o Thread.o ThreadCond.o ThreadPool.o

