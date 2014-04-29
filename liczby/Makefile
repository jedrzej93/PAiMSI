CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj liczby
		./liczby

obj:
	mkdir obj

liczby: obj/dane.o obj/main.o obj/benchmark.o
	g++ ${LDFLAGS} -o liczby obj/dane.o obj/main.o obj/benchmark.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/dane.o: src/dane.cpp inc/dane.hh 
	g++ -c ${CPPFLAGS} -o obj/dane.o src/dane.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh 
	g++ -c ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

clean:
	rm -f liczby core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
