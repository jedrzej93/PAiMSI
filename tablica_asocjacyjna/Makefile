CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

__start__: obj tab_aso
		./tab_aso

obj:
	mkdir obj

tab_aso: obj/tablica_asocjacyjna.o obj/main.o 
	g++ ${LDFLAGS} -o tab_aso obj/tablica_asocjacyjna.o obj/main.o 

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/tablica_asocjacyjna.o: src/tablica_asocjacyjna.cpp inc/tablica_asocjacyjna.hh 
	g++ -c ${CPPFLAGS} -o obj/tablica_asocjacyjna.o src/tablica_asocjacyjna.cpp

clean:
	rm -f tablica_asocjacyjna core obj/*
help:
	@echo
	@echo "Copyright by Patryk Jędrzejko"
