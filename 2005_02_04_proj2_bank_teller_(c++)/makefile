bank : bank.o teller.o account.o
	g++ -o bank bank.o teller.o account.o
bank.o : bank.cpp account.h teller.h
	g++ -c bank.cpp
teller.o : teller.cpp teller.h account.h
	g++ -c teller.cpp
account.o : account.cpp account.h
	g++ -c account.cpp
clean :
	rm -rf *.o SunWS_cache
