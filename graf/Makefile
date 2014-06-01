CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj graf
		./graf

obj:
	mkdir obj

graf: obj/graf.o obj/main.o obj/benchmark.o
	g++ ${LDFLAGS} -o graf obj/graf.o obj/main.o obj/benchmark.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/graf.o: src/graf.cpp inc/graf.hh 
	g++ -c ${CPPFLAGS} -o obj/graf.o src/graf.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh 
	g++ -c ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

clean:
	rm -f graf core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
