CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj simplex
		./simplex

obj:
	mkdir obj

simplex: obj/simplex.o obj/main.o 
	g++ ${LDFLAGS} -o simplex obj/simplex.o obj/main.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/simplex.o: src/simplex.cpp inc/simplex.hh 
	g++ -c ${CPPFLAGS} -o obj/simplex.o src/simplex.cpp

clean:
	rm -f simplex core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
