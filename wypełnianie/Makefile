CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj bench
		./bench

obj:
	mkdir obj

bench: obj/benchmark.o obj/main.o obj/stos_tablica.o obj/stos_lista.o obj/kolejka_tablica.o obj/kolejka_lista.o
	g++ ${LDFLAGS} -o bench obj/benchmark.o obj/main.o obj/stos_tablica.o obj/stos_lista.o obj/kolejka_tablica.o obj/kolejka_lista.o

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh 
	g++ -c ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

obj/stos_tablica.o: src/stos_tablica.cpp inc/stos_tablica.hh 
	g++ -c ${CPPFLAGS} -o obj/stos_tablica.o src/stos_tablica.cpp

obj/stos_lista.o: src/stos_lista.cpp inc/stos_lista.hh 
	g++ -c ${CPPFLAGS} -o obj/stos_lista.o src/stos_lista.cpp

obj/kolejka_tablica.o: src/kolejka_tablica.cpp inc/kolejka_tablica.hh 
	g++ -c ${CPPFLAGS} -o obj/kolejka_tablica.o src/kolejka_tablica.cpp

obj/kolejka_lista.o: src/kolejka_lista.cpp inc/kolejka_lista.hh 
	g++ -c ${CPPFLAGS} -o obj/kolejka_lista.o src/kolejka_lista.cpp	

clean:
	rm -f bench core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
