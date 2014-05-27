/*!
 *\file Plk glowny klasy Graf.
 * Zawarte sa ty definicje poszczegolnych funkcji 
 * z klasy Graf.
 */
#include <iostream>
#include <iomanip>
#include "astar.hh"

using namespace std;

void Graf::Stworz_Siatke()
{
	Wspolrzedne start, meta;
	start.x = 1; start.y = 4; meta.y = 4; meta.x = 7;

	for(int i = start.x; i <= meta.x; i++)
	{
		for(int j = start.y; j <= meta.y; j++)
			w[i][j].typ = Wierzcholek_Typ_W;
	}
}

void Graf::Ustaw_Wspolrzedne()
{
	poczatek.x = 3; poczatek.y = 1; koniec.x = 6; koniec.y = 7;

	w[poczatek.x][poczatek.y].typ = Wierzcholek_Typ_P;
	w[koniec.x][koniec.y].typ = Wierzcholek_Typ_P;
}

void Graf::Oblicz_H()
{
	for(int i = 0; i < w.size(); i++)
	{
		for(int j = 0; j < w.size(); j++)
		{
			w[i][j].h = fabs(w[i][j].punkt.x - koniec.x) + fabs(w[i][j].punkt.y - koniec.y);
		}
	}
}

void Graf::Oblicz_G()
{
	for(int i = 0; i < w.size(); i++)
	{
		for(int j = 0; j < w.size(); j++)
		{
			w[i][j].g = fabs(w[i][j].punkt.x - poczatek.x) + fabs(w[i][j].punkt.y - poczatek.y);
		}
	}
}

void Graf::Oblicz_F()
{
	for(int i = 0; i < w.size(); i++)
	{
		for(int j = 0; j < w.size(); j++)
		{
			w[i][j].f = w[i][j].h + w[i][j].g;
		}
	}
}

void Graf::Oblicz_H(Wspolrzedne _w)
{
	w[_w.x][_w.y].h = fabs(w[_w.x][_w.y].punkt.x - koniec.x) + fabs(w[_w.x][_w.y].punkt.y - koniec.y);
}

void Graf::Oblicz_F(Wspolrzedne _w)
{
	w[_w.x][_w.y].f = w[_w.x][_w.y].h + w[_w.x][_w.y].g;
}

void Graf::Zapisz_Graf_Do_Pliku()
{
	fstream plik("...astar/graf.txt");
	for(int i = 0; i < w.size(); i++)
	{
		for(int j = 0; j < w.size(); j++)
		{
			plik << w[i][j].typ << " ";
		}
		plik << endl;
	}
}

void Graf::Wyswietl_Rozwiazanie()
{
	Wspolrzedne p = koniec;
	while(p != w[poczatek.x][poczatek.y].rodzic)
	{
		w[p.x][p.y].typ = Wierzcholek_Typ_P;
		p = w[p.x][p.y].rodzic;
	}
	Zapisz_Graf_Do_Pliku();
}

Graf::Graf()
{
	w.resize(WYSOKOSC);
	for(int i = 0; i < w.size(); i++)
	{
		w[i].resize(SZEROKOSC);
	}

	for(int i = 0; i < w.size(); i++)
	{
		for(int j = 0; j < w.size(); j++)
		{
			w[i][j].punkt.x = i;
			w[i][j].punkt.y = j;
		}
	}
	Stworz_Siatke();
	Ustaw_Wspolrzedne();
}

void Graf::AStar()
{
    multimap<int, Wierzcholek> zamkniety, otwarty;
        
    w[poczatek.x][poczatek.y].g = 0;
    Oblicz_H(poczatek);
    Oblicz_F(poczatek);
    w[poczatek.x][poczatek.y].rodzic = poczatek;

    otwarty.insert(make_pair(w[poczatek.x][poczatek.y].f, w[poczatek.x][poczatek.y]));
        
    while (!otwarty.empty()) 
    {
        Wierzcholek p = otwarty.begin()->second;
        otwarty.erase(otwarty.begin());
        if (p.punkt.x == koniec.x && p.punkt.y == koniec.y) 
        {
            cout << " Znaleziono cel! " << endl;
            break;
        }
        
        zamkniety.insert(make_pair(w[p.punkt.x][p.punkt.y].f, w[p.punkt.x][p.punkt.y]));
            
        for (int i = -1; i <= 1; ++i) 
        {
            for (int j = -1; j <= 1; ++j) 
            {
                int koszt;
				// zmiana kosztu szukania
                if (i && j)
                    koszt = 2;
                else
                    koszt = 1;
                    
                if (i && j)
                    continue;
                    
               	Wspolrzedne v;
                v.x = p.punkt.x + i;
                v.y = p.punkt.y + j;
                if (v.x < 0 || v.x >= w.size() || v.y < 0 || v.y >= w[v.x].size() || w[v.x][v.y].typ == Wierzcholek_Typ_W) 
                {
                	continue;
                }
                
                if (zamkniety.find(w[v.x][v.y].f) != zamkniety.end()) 
                {
                    continue;
                }
                
                if (otwarty.find(w[v.x][v.y].f) == otwarty.end()) 
                {
                    w[v.x][v.y].g = w[p.punkt.x][p.punkt.y].g + koszt;
                    Oblicz_H(v);
                    Oblicz_F(v);
                    w[v.x][v.y].rodzic = p.punkt;
					
                    otwarty.insert(make_pair(w[v.x][v.y].f, w[v.x][v.y]));
                }
                else 
                {
                    Wierzcholek x = otwarty.find(w[v.x][v.y].f)->second;
                    if (x.g < w[v.x][v.y].g) 
                    {
                        otwarty.erase(w[x.punkt.x][x.punkt.y].f);
                        otwarty.insert(make_pair(w[v.x][v.y].f, w[v.x][v.y]));
                    }
                }
            }
        }
    }
    Wyswietl_Rozwiazanie();
}