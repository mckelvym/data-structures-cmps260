excercise3 : excercise3.o arrayListType.o
	CC -o excercise3 excercise3.o arrayListType.o
excercise3.o : excercise3.cpp arrayListType.h
	CC -c excercise3.cpp
arrayListType.o : arrayListType.cpp arrayListType.h
	CC -c arrayListType.cpp
clean :
	rm -rf *.o SunWS_cache
