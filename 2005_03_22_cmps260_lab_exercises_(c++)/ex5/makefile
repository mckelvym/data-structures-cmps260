ex4-2 : ex4-2.o person.o arrayListType.o
	CC -o ex4 ex4-2.o person.o arrayListType.o
ex4-2.o : ex4-2.cpp person.h arrayListType.h
	CC -c ex4-2.cpp
person.o : person.cpp person.h
	CC -c person.cpp
arrayListType.o : arrayListType.cpp arrayListType.h
	CC -c arrayListType.cpp
	
clean :
	rm -rf *.o SunWS_cache
