CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj graf
		./graf

obj:
	mkdir obj

graf: obj/graf.o obj/main.o
	g++ ${LDFLAGS} -o graf obj/graf.o obj/main.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/graf.o: src/graf.cpp inc/graf.hh 
	g++ -c ${CPPFLAGS} -o obj/graf.o src/graf.cpp

clean:
	rm -f graf core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
