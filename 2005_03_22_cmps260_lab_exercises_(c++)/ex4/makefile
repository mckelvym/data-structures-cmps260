test : test.o ovclass.o
	CC -o test test.o ovclass.o
ovclass.o : ovclass.cpp ovclass.h
	CC -c ovclass.cpp
test.o : test.cpp ovclass.h
	CC -c test.cpp
clean :
	rm -rf SunWS_cache
