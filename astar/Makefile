CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj astar
		./astar

obj:
	mkdir obj

astar: obj/astar.o obj/main.o obj/benchmark.o
	g++ ${LDFLAGS} -o astar obj/astar.o obj/main.o obj/benchmark.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/astar.o: src/astar.cpp inc/astar.hh 
	g++ -c ${CPPFLAGS} -o obj/astar.o src/astar.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh 
	g++ -c ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp	

clean:
	rm -f astar core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
