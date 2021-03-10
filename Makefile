client: Main_Client.o Client.o Line.o Semaphore.o Socket.o Failure.o
	g++ -o client Main_Client.o Client.o Line.o Semaphore.o Socket.o Failure.o -lpthread
	rm -f Main_Client.o Client.o Line.o Semaphore.o Socket.o Failure.o
server: Main_Server.o Server.o Socket.o Failure.o
	g++ -o server Main_Server.o Server.o Socket.o Failure.o
	rm -f Main_Server.o Server.o Socket.o Failure.o
Main_Client.o: Main_Client.cpp
	g++ -c Main_Client.cpp
Client.o: Client.cpp Client.h
	g++ -c Client.cpp 
Main_Server.o: Main_Server.cpp
	g++ -c Main_Server.cpp
Server.o: Server.cpp Server.h
	g++ -c Server.cpp
Line.o: Line.cpp Line.h
	g++ -c Line.cpp
Semaphore.o: Semaphore.cpp Semaphore.h
	g++ -c Semaphore.cpp
Socket.o: Socket.cpp Socket.h
	g++ -c Socket.cpp
Failure.o: Failure.cpp Failure.h
	g++ -c Failure.cpp
