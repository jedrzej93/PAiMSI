#ifndef ASTAR_HH_INCLUDED
#define ASTAR_HH_INCLUDED
/*!
 *\file Plk naglowkowy klasy Graf.
 * Klasa Graf zawierajaca definicje poszczegolnych funkcji.
 */
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <fstream>

#define WYSOKOSC 10
#define SZEROKOSC 10

using namespace std;
/*!
*\brief Deklaracja zmiennych przechowujacych ustalone wartosci
* dla odpowiedniego typu danych. F - dla wierzcholkow wolnych,
* W - dla wierzcholkow znajdujacych sie w siatce oraz P - wierzcholki,
* ktore sa rozwiazaniami.
*/
typedef enum
{
	Wierzcholek_Typ_F, 
	
	Wierzcholek_Typ_W, 
	
	Wierzcholek_Typ_P

}Wierzcholek_Typ;
/*!
*\brief Struktura Wspolrzedne.
* W ktorej zdefiniowane sa dwie zmienne x oraz y, ktore
* odpowiadaja za przechowywanie pozycji na siatce.
* Rowniez zdefiniowane sa operator przypisania oraz operator logiczny relacji.
*/
struct Wspolrzedne
{
	/*!
	*\brief Zmienna typu int, odpowiadzialna za przechowywanie wartosci wspolrzednej x.
	*/
	int x;
	/*!
	*\brief Zmienna typu int, odpowiadzialna za przechowywanie wartosci wspolrzednej y.
	*/
	int y;
	/*!
	*\brief Zdefiniowany operator porownania.
	* Jezeli zmienne x i y sa rowne wspolrzednym tych zmiennych to zwracana jest wartosc niezerowa.
	*/
	bool operator == (Wspolrzedne wsp)
	{
		return x == wsp.x && y == wsp.y;
	}
	/*!
	*\brief Zdefiniowany operator relacji.
	*/
	bool operator != (Wspolrzedne wsp)
	{
		return !(*this == wsp);
	}
};
/*!
*\brief Struktura Wierzcholek.
* Przechowuje deklaracje zwiazane z ta klasa.
*/
struct Wierzcholek
{
	/*!
	*\brief Zmienna typu Wierzcholek_Typ, okreslajaca jaki typ wierzcholka bedzie wykorzystywany.
	*/
	Wierzcholek_Typ typ;
	/*!
	*\brief Zmienne pomocnicze typu int odnoszace sie do funkcji obliczajacych sciezki dojscia do celu. 
	*/
	int f, g, h;
	/*!
	*\brief Zmienna typu Wspolrzedne, odnosi sie do danego punktu na siatce.
	*/
	Wspolrzedne punkt;
	/*!
	*\brief Zmienna typu Wspolrzedne zawiera informacje o punktcie przed wezlem.
	*/
	Wspolrzedne rodzic;
};
/*!
*\brief Deklaracja klasy Astar.
*/
class Graf
{
		/*!
		*\brief Zmienna typu Wspolrzedne przechowujaca informajce o wspolrzednej poczatkowej, z ktorej
		* algortym A* startuje.
		*/
		Wspolrzedne poczatek;
		/*!
		*\brief Zmienna typu Wspolrzedne przechowujaca informajce o wspolrzednej koncowej.
		*/
		Wspolrzedne koniec;
		/*!
		*\brief Funkcja tworzaca siatke.
		* Funkcja tworzy siatke na ktorej algorytm AStar przeszukuje wartosci. 
		* Okreslany jest punkt startowy oraz punkt koncowy dla ktorych sa 
		* tworzone wartosci na siatce.
		*/
		void Stworz_Siatke();
		/*!
		*\brief Funkcja ustawiajace wspolrzedne.
		* Funkcja ustala poczatkowe wspolrzedne oraz przydziela je do danego
		* typu wierzcholka.
		*/
		void Ustaw_Wspolrzedne();
		/*!
		*\brief Funkcja heurestyczna.
		* Funkcja oblicza przyblizona droge jaka algorytm musi przejsc, aby odnalezc cel.
		*/
		void Oblicz_H();
		/*!
		*\brief Funkcja obliczajaca droge.
		* Funkcja oblicza odleglosc pomiedzy wierzcholkiem poczatkowym a punktem x na siatce.
		*/
		void Oblicz_G();
		/*!
		*\brief Funkcja obliczajaca wspolczynnik f.
		* Funkcja oblicza wspolczynnik f, ktory okresla dany wierzcholek.
		* Na podstawie tego algorytm A* wybiera wierzcholek o najnizszym wspolczynniku
		* przez ktory przeszukuje graf.
		*/
		void Oblicz_F();
		/*!
		*\brief Funkcja heurestyczna obliczajaca droge o zdanym punkcie.
		*/
		void Oblicz_H(Wspolrzedne _w);
		/*!
		*\brief Funkcja obliczajaca droge o zadanym punkcie.
		*/
		void Oblicz_G(Wspolrzedne _w) {}
		/*!
		*\brief Funkcja obliczajaca wspolczynnik f o zadanym punkcie.
		*/
		void Oblicz_F(Wspolrzedne _w);
		/*!
		*\brief Funkcja zapisujaca graf do pliku.
		* Funkcja za pomoca funkcji fstream zapisuje
		* dane do pliku tekstowego "graf.txt".
		*/
		void Zapisz_Graf_Do_Pliku();
		/*!
		*\brief Funkcja wyswietlajaca rozwiazanie przeszukiwania przez algorytm.
		*/
		void Wyswietl_Rozwiazanie();
	
	public:
		/*!
		*\brief Zmienna vector, zawierajaca vector dotyczacy struktury Wierzcholek.
		*/
		vector< vector<Wierzcholek> > w;
		/*!
		*\brief Konstruktor klasy Graf.
		* W konstruktorze tworzony jest graf o zdefiniowanej szerokosci oraz wysokosci,
		* ustawiane sa punkte startowe oraz tworzona jest siatka dla algorytmu A*.
		*/
		Graf();
		/*!
		*\brief Zdefiniowany operator przesuniecia bitowego.
		* Operator wypisuje na wyjsciu utworzone dane.
		* Zwracany jest /param wyjscie.
		*/
		friend ostream& operator << (ostream& wyjscie, Graf& zmienna)
		{
			for(int i = 0; i < zmienna.w.size(); i++)
			{
				for(int j = 0; j < zmienna.w.size(); j++)
				{
					wyjscie << zmienna.w[i][j].typ << " ";
				}
				wyjscie << endl;
			}
		return wyjscie;
		}
		/*!
		*\brief Funkcja AStar.
		* Funkcja implementujaca algorytm przeszukiwania A*.
		* Zaimplementowala za pomoca standardowych funkcji z biblioteki STL.
		*/
		void AStar();

};
#endif