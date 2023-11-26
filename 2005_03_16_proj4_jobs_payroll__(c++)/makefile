# jmm0468
# cmps260 s3
# makefile

main : main.o employee.o arrayListType.o
	g++ -o main main.o employee.o arrayListType.o
main.o : main.cpp employee.h arrayListType.h
	g++ -c main.cpp
employee.o : employee.cpp employee.h
	g++ -c employee.cpp
arrayListType.o : arrayListType.cpp arrayListType.h
	g++ -c arrayListType.cpp

clean:
	rm -rf *.o SunWS_cache
