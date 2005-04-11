# jmm0468
# cmps260 s3
# makefile 

main : main.o employee.o arrayListType.o
	CC -o main main.o employee.o arrayListType.o
main.o : main.cpp employee.h arrayListType.h
	CC -c main.cpp
employee.o : employee.cpp employee.h
	CC -c employee.cpp
arrayListType.o : arrayListType.cpp arrayListType.h
	CC -c arrayListType.cpp

clean:
	rm -rf *.o SunWS_cache
