translator : useDNS.o DNS.o
	g++ useDNS.o DNS.o -o hw6
useDNS.o : useDNS.cpp DNS.cpp DNS.h
	g++ -Wall -c useDNS.cpp

DNS.o : DNS.cpp DNS.h
	g++ -Wall -c DNS.cpp

clean :
	rm *.o hw6
