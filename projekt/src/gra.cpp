#include <iostream>
#include <sstream>
#include <iomanip>
#include "gra.hh"

using namespace std;

Gra::Gra()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			Plansza[i][j] = '-';
		}
	}
}

void Gra::Wyswietl_Plansze()
{
	cout << "-------------------";
	for(int i = 0; i < 3; i++)
	{
		cout << endl << "|";
		for(int j = 0; j < 3; j++)
		{
			cout << setw(3) << Plansza[i][j] << setw(3) << "|";
		}
	}
	cout << endl << "-------------------" << endl;
}

bool Gra::Koniec_Gry()
{
	if(Kto_Wygral(CZLOWIEK))
		return true;
	else if(Kto_Wygral(KOMPUTER))
		return true;

	bool puste_miejsce = false;
	for(int i = 0; i < 3; i++)
	{
		if(Plansza[i][0] == '-' || Plansza[i][1] == '-' || Plansza[i][2] == '-')
			puste_miejsce = true;
	}

	return !puste_miejsce;
}
// sprawdzamy czy znaki gracza badz tez komputera tworza odpowiednio ciag symboli zdefiniowanych w pliku naglowkowym
// w petli sprawdzamy czy w poziome, w pionie badz tez po przekatnych mamy te same symbole, jesli tak to mamy zwracany true
// co odpowiada temu iz gracz lub komputer wygrywa dana gre, jesli nie mamy 3 znakow pod rzad to zwracamy false to jest jednoznaczne z remisem.
bool Gra::Kto_Wygral(Gracz gracz)
{
	char gracz_znak;

	if(gracz == CZLOWIEK)
		gracz_znak = czlowiek;
	else
		gracz_znak = komputer;

	for(int i = 0; i < 3; i++)
	{
		// sprawdzenie poziomo
		if(Plansza[i][0] == gracz_znak && Plansza[i][1] == gracz_znak && Plansza[i][2] == gracz_znak)
			return true;

		// sprawdzenie pionowo
		if(Plansza[0][i] == gracz_znak && Plansza[1][i] == gracz_znak && Plansza[2][i] == gracz_znak)
			return true;
	}

	// sprawdzenie po przekatnych
	if(Plansza[0][0] == gracz_znak && Plansza[1][1] == gracz_znak && Plansza[2][2] == gracz_znak)
	{
		return true;
	}
	else if(Plansza[0][2] == gracz_znak && Plansza[1][1] == gracz_znak && Plansza[2][0] == gracz_znak)
	{
		return true;
	}

	return false;
}

int Gra::wynik()
{
	if(Kto_Wygral(CZLOWIEK))
	{
		return 1;
	}
	else if(Kto_Wygral(KOMPUTER))
	{
		return -1;
	}

	return 0; // zwracamy 0 przy remisie
}
// algorytm ktory steruje ruchem komputera
Ruch Gra::MiniMax(char KOMPUTER_Plansza[3][3])
{
	int najlepszePosunieciePkt = 10;
	Ruch najlepszePosuniecie;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(KOMPUTER_Plansza[i][j] == '-')
			{
				KOMPUTER_Plansza[i][j] = komputer;
				int tmp_najlepszePosunieciePkt = Szukaj_Max(KOMPUTER_Plansza);
				if(tmp_najlepszePosunieciePkt <= najlepszePosunieciePkt)
				{
					najlepszePosunieciePkt = tmp_najlepszePosunieciePkt;
					najlepszePosuniecie.x = i;
					najlepszePosuniecie.y = j;
				}
				KOMPUTER_Plansza[i][j] = '-';
			}
		}
	}

	return najlepszePosuniecie;
}

int Gra::Szukaj_Max(char KOMPUTER_Plansza[3][3])
{
	if(Koniec_Gry())
		return wynik();

	Ruch najlepszePosuniecie;
	int najlepszePosunieciePkt = -100;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(KOMPUTER_Plansza[i][j] == '-')
			{
				KOMPUTER_Plansza[i][j] = czlowiek;
				int tmp_najlepszePosunieciePkt = Szukaj_Min(KOMPUTER_Plansza);
				if(tmp_najlepszePosunieciePkt >= najlepszePosunieciePkt)
				{
					najlepszePosunieciePkt = tmp_najlepszePosunieciePkt;
					najlepszePosuniecie.x = i;
					najlepszePosuniecie.y = j;
				}
				KOMPUTER_Plansza[i][j] = '-';
			}
		}
	}

	return najlepszePosunieciePkt;
}

int Gra::Szukaj_Min(char KOMPUTER_Plansza[3][3])
{
	if(Koniec_Gry())
		return wynik();

	Ruch najlepszePosuniecie;

	int najlepszePosunieciePkt = 100;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(KOMPUTER_Plansza[i][j] == '-')
			{
				KOMPUTER_Plansza[i][j] = komputer;
				int tmp_najlepszePosunieciePkt = Szukaj_Max(KOMPUTER_Plansza);
				if(tmp_najlepszePosunieciePkt <= najlepszePosunieciePkt)
				{
					najlepszePosunieciePkt = tmp_najlepszePosunieciePkt;
					najlepszePosuniecie.x = i;
					najlepszePosuniecie.y = j;
				}
				KOMPUTER_Plansza[i][j] = '-';
			}
		}
	}

	return najlepszePosunieciePkt;
}

void Gra::Ruch_Czlowieka()
{
	int x, y = -1;
	while(x < 0 || x > 2 || y < 0 || y > 2)
	{
		cout << "Wprowadz wspolrzedna swojego ruchu, czyli np (2,1)." << endl;
		cout << "Teraz twoj ruch: ";
		char znak;
		string reszta_linii;
		cin >> znak >> znak;
		x = znak - '0' - 1;
		cin >> znak >> znak;
		y = znak - '0' - 1;
		getline(cin, reszta_linii);
	}

	Plansza[x][y] = czlowiek;
}

void Gra::Graj()
{
	int kolej = 0;
	Wyswietl_Plansze();

	while(!Kto_Wygral(CZLOWIEK) && !Kto_Wygral(KOMPUTER) && !Koniec_Gry())
	{
		//kolej czlowieka
		if(kolej % 2 == 0)
		{
			Ruch_Czlowieka();
			kolej++;
			Wyswietl_Plansze();
			if(Kto_Wygral(CZLOWIEK))
				cout << "Brawo! Wygrales z Komputerem!" << endl;
			else if(!Kto_Wygral(CZLOWIEK) && !Kto_Wygral(KOMPUTER))
				cout << "Zremisowales z komputerem! Sprobuj ponownie!" << endl << endl;
		}
		else
		{
			//kolej komputera
			cout << endl << "Teraz kolej Komputera: " << endl;
			Ruch KOMPUTER_Ruch = MiniMax(Plansza);
			Plansza[KOMPUTER_Ruch.x][KOMPUTER_Ruch.y] = komputer;
			kolej++;
			Wyswietl_Plansze();
			if(Kto_Wygral(KOMPUTER))
			{
				cout << "Slabo! Komputer wygral z Toba!" << endl;
				cout << "Zagraj jeszcze raz!" << endl << endl;
			}
		}
	}
}
