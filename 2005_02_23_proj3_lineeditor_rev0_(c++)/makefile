lineeditor : lineeditor.o lineEdit.o arrayStringListType.o
	g++ -o lineeditor lineeditor.o lineEdit.o arrayStringListType.o
lineeditor.o : lineeditor.cpp lineEdit.h
	g++ -c lineeditor.cpp
lineEdit.o : lineEdit.cpp lineEdit.h arrayStringListType.h
	g++ -c lineEdit.cpp
arrayStringListType.o : arrayStringListType.cpp arrayStringListType.h
	g++ -c arrayStringListType.cpp

clean :
	rm -rf *.o SunWS_cache
 
 
 
 
 
 
 
 
 
