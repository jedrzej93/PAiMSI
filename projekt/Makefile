CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj kolko_i_krzyzyk
		./kolko_i_krzyzyk

obj:
	mkdir obj

kolko_i_krzyzyk: obj/gra.o obj/main.o 
	g++ ${LDFLAGS} -o kolko_i_krzyzyk obj/gra.o obj/main.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/gra.o: src/gra.cpp inc/gra.hh 
	g++ -c ${CPPFLAGS} -o obj/gra.o src/gra.cpp

clean:
	rm -f kolko_i_krzyzyk core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
