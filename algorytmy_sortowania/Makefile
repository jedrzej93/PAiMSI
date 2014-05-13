CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj bench
		./bench

obj:
	mkdir obj

bench: obj/benchmark.o obj/main.o obj/kolejka_tablica.o 
	g++ ${LDFLAGS} -o bench obj/benchmark.o obj/main.o obj/kolejka_tablica.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh 
	g++ -c ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

obj/kolejka_tablica.o: src/kolejka_tablica.cpp inc/kolejka_tablica.hh 
	g++ -c ${CPPFLAGS} -o obj/kolejka_tablica.o src/kolejka_tablica.cpp

clean:
	rm -f bench core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
