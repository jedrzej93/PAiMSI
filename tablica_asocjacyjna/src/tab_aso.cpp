#include <iostream>
#include <vector>

using namespace std;

template <class T>

class Tablica_Asocjacyjna
{
	private:
		
		struct Dane
		{
			T dane;
			string nazwa;
		};
		
		vector<Dane> stos;
	
	public:
		
		long Rozmiar()
		{
			return stos.size();
		}
		
		bool CzyJestElement(string nazwa)
		{
			for(int i = 0; i < Rozmiar(); i++)
			{
				if(stos[i].nazwa == nazwa)
				return true;
			}
		
		return false;
		}
		// funkcja dodajaca element do tablicy asocjacyjnej
		bool DodajElement(string nazwa, T dane)
		{
			if(CzyJestElement(nazwa))
				return false;
			Dane _dane;
			_dane.nazwa = nazwa;
			_dane.dane = dane;
			stos.push_back(_dane);
			
			return true;
		}
		// funkcja dodajaca element do tablicy asocjacyjnej za pomoca operatora indeksu
		T& operator [] (string nazwa)
		{
			for(int i = 0; i < Rozmiar(); i++)
			{
				if(stos[i].nazwa == nazwa)
					return stos[i].dane;
			}
			
			long wsk = Rozmiar();
			Dane _dane;
			_dane.nazwa = nazwa;
			stos.push_back(_dane);
			
			return stos[wsk].dane;
		}
		// funkcja przypisujaca nazwe dodanego elementu
		string WezNazweElementu(long wskaznik)
		{
			if(wskaznik < 0)
				wskaznik = 0;
			for(int i = 0; i < Rozmiar(); i++)
				if(i == wskaznik)
				return stos[i].nazwa;
			
			return "";
		}
		// funkcja przypisujaca nazwe dodanego elementu za pomocą operatora indeksu
		T& operator [] (long wskaznik)
		{
			if(wskaznik < 0)
				wskaznik = 0;
			for(int i = 0; i < Rozmiar(); i++)
			{
				if(i == wskaznik)
				return stos[i].dane;
			}
			
			return stos[0].dane;
		}

		bool UsunElement(T dane)
		{
			string nazwa;

			if(CzyJestElement(nazwa))
				return false;
			
			Dane _dane;
			_dane.nazwa = nazwa;
			_dane.dane = dane;
			stos.pop(_dane);
			
			return true;
		}
};

int main()
{
	Tablica_Asocjacyjna<int> Tab_Aso;
	int opcja, klucz;
	string nazwa_elementu;


	cout << "----MENU TAB ASO----" << endl;
	cout << " 1 - DODAJ ELEMENT DO TABLICY ASOCJACYJNEJ " << endl;
	cout << " 2 - USUN ELEMENT Z TABLICY ASOCJACYJNEJ" << endl;
	cout << " 3 - ZNAJDZ ELEMENT O ZADANYM KLUCZU" << endl;
	cout << " 4 -  " << endl;
	cout << " 5 -  " << endl;
	cout << " 6 - ZAKONCZ PROGRAM " << endl;
	cout << "Wybor opcji: ";
	cin >> opcja;

	switch(opcja)
	{
		case 1:	
				cout << "Podaj nazwe elementu: ";
				cin >> nazwa_elementu;
				cout << "->klucz do elementu:";
				cin >> klucz;
				cout << endl;
				Tab_Aso.DodajElement(nazwa_elementu, klucz);
				cout << "Dodany element-> " << Tab_Aso[nazwa_elementu] << ":" << Tab_Aso[klucz] << endl;
				break;
		case 2:
				cout << "Usun element o kluczu: ";
				cin >> klucz;
				Tab_Aso.UsunElement(klucz);
		case 3: break;
		case 4: break;
		case 5: break;
		case 6:
				cout << "Zakonczono program!" << endl;
				break;
	}	
}
