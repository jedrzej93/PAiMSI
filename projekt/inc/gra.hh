#ifndef GRA_HH
#define GRA_HH

#include <iostream>
#include <iomanip>

using namespace std;

const char czlowiek = 'X'; // symbol gracza
const char komputer = 'O'; // symbol uzywany w grze przez komputer
// typ wyliczeniowy typu danych, gdzie mamy wartosci dla gracza oraz komputera
enum Gracz { CZLOWIEK, KOMPUTER };
// struktura odpowiedzialna za wspolrzedne ruchow gracza oraz komputera na planszy
struct Ruch 
{
	int x;
	int y;
};
// klasa glowna gry, zawierajaca wszystkie funkcji oraz zmienne
class Gra
{
	private:
		
		char Plansza[3][3]; // plansza o rozmiarach 3x3

	public:
		// konstruktor klasy w ktorym tworzone sa znaczniki pola '-'
		Gra();
		// funkcja wyswietlajaca stworzona plansze o wymiarach [3][3]
		void Wyswietl_Plansze();
		// funkcja ktora sprawdza czy zakonczyc gre
		bool Koniec_Gry();
		// funkcja odpowiedzialna za sprawdzanie kto wygral dana gre, poprzez sprawdzanie na planszy symboli
		// ktore tworza poziomo, pionowo badz tez po przekatnych ciag trzech tych samych symboli
		bool Kto_Wygral(Gracz gracz);
		// funkcja zaczyna gre pomiedzy uzytkownikiem a komputer, zwraca rowniez kto wygral dana gre
		void Graj();
		// funkcja w ktorej czytamy ruch gracza, czyli uzytkownika programu poprzez funkcje getline()
		void Ruch_Czlowieka();
		// funkcja zwracaja wynik gry
		// Jezeli gracz wygral zwracana jest liczba 1, jezeli wygral komputer zwraca -1, przy remisie mamy 0.
		int wynik();
		// Funkcja minimax zwraca najlepsze mozliwe posuniecie dla komputera.
		Ruch MiniMax(char KOMPUTER_Plansza[3][3]);
		//funkcja pomocnicza dla funkcji minimax pomagajaca komputerowi poruszac sie
		// z jak najmniejszym wynikiem 
		int Szukaj_Min(char KOMPUTER_Plansza[3][3]);
		// funkcja pomocnicza funkcji minimax, ktora znajduje sciezke gracza
		// o jak najwiekszej wartosci posuniecia
		int Szukaj_Max(char KOMPUTER_Plansza[3][3]);

		
};
#endif