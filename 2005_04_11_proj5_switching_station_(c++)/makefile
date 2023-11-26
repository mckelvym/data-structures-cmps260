main : main.o linkedList.o
	g++ -o main main.o linkedList.o
main.o : main.cpp linkedList.h
	g++ -c main.cpp
linkedQueue.o : linkedQueue.cpp linkedQueue.h linkedNode.h
	g++ -c linkedQueue.cpp
linkedStack.o : linkedStack.cpp linkedStack.h linkedNode.h
	g++ -c linkedStack.cpp
linkedList.o : linkedList.cpp linkedList.h linkedNode.h
	g++ -c linkedList.cpp

clean:
	rm -rf *.o SunWS_cache
