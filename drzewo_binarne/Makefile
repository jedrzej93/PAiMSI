CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj drzewo_binarne
		./drzewo_binarne

obj:
	mkdir obj

drzewo_binarne: obj/drzewo_binarne.o obj/main.o 
	g++ ${LDFLAGS} -o drzewo_binarne obj/drzewo_binarne.o obj/main.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/drzewo_binarne.o: src/drzewo_binarne.cpp inc/drzewo_binarne.hh 
	g++ -c ${CPPFLAGS} -o obj/drzewo_binarne.o src/drzewo_binarne.cpp

clean:
	rm -f drzewo_binarne core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
