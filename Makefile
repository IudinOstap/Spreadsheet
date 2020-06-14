CC=g++
CFLAGS=-c -g -std=c++14 -Wall -pedantic -Wno-long-long -O0 -ggdb
CLIBS=-std=c++14 -fsanitize=address


all: doc iudinost

iudinost: CCell.o CText.o CDigit.o CEmpty.o CTable.o CInterface.o CProgram.o main.o 
	$(CC) CCell.o CText.o CDigit.o CEmpty.o CTable.o CInterface.o CProgram.o main.o -o iudinost $(CLIBS)

CCell.o: src/CCell.cpp src/CCell.hpp
	$(CC) $(CFLAGS) src/CCell.cpp -o $@

CInterface.o: src/CInterface.cpp src/CInterface.hpp src/CTable.hpp src/CCell.hpp src/CEmpty.hpp src/CDigit.hpp src/CText.hpp 
	$(CC) $(CFLAGS) src/CInterface.cpp -o $@

CProgram.o: src/CProgram.cpp src/CProgram.hpp src/CInterface.hpp src/CTable.hpp
	$(CC) $(CFLAGS) src/CProgram.cpp -o $@

CTable.o: src/CTable.cpp src/CTable.hpp src/CCell.hpp src/CEmpty.hpp src/CDigit.hpp src/CText.hpp
	$(CC) $(CFLAGS) src/CTable.cpp -o $@

CEmpty.o: src/CEmpty.cpp src/CEmpty.hpp src/CCell.hpp
	$(CC) $(CFLAGS) src/CEmpty.cpp -o $@

CText.o: src/CText.cpp src/CText.hpp src/CCell.hpp
	$(CC) $(CFLAGS) src/CText.cpp -o $@

CDigit.o: src/CDigit.cpp src/CDigit.hpp src/CCell.hpp
	$(CC) $(CFLAGS) src/CDigit.cpp -o $@

main.o: src/main.cpp src/CProgram.hpp
	$(CC) $(CFLAGS) src/main.cpp -o $@

doc:
	doxygen doxygen.conf
	mv doc/html/* doc/
	rm -r doc/html

documentation: doc
	firefox doc/index.html

clean:
	rm -f *.o
	rm -f iudinost
	rm -rf doc
	rm -rf *.dSYM

compile: doc iudinost

run: doc iudinost
	./iudinost
	

