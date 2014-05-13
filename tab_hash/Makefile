CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj tablica_hash
		./tablica_hash

obj:
	mkdir obj

tablica_hash: obj/tab_hash.o obj/main.o
	g++ ${LDFLAGS} -o tablica_hash obj/tab_hash.o obj/main.o

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/tab_hash.o: src/tab_hash.cpp inc/tab_hash.hh 
	g++ -c ${CPPFLAGS} -o obj/tab_hash.o src/tab_hash.cpp

clean:
	rm -f tablica_hash core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
