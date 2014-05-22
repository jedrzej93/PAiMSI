#include <iostream>
#include "graf.hh"
/*!
 *\file Definicje poszczegolnych funkcji dla klasy Graf - szukanie DFS, BFS.
 */
using namespace std;

Graf::Graf(string nazwa_pliku)
{
	string linijka;
	fstream plik;
	plik.open(nazwa_pliku.c_str());
	if(!plik)
	{
		cout << "Nie mozna otworzyc pliku!!!" << endl;
	}

	while(getline(plik, linijka))
	{
		string wezel;
		vector<string> temp;
		istringstream iss(linijka);
		string wartosc;
		while(iss >> wartosc)
		{
			temp.push_back(wartosc);
		}
		wezel = temp[0];
		temp.erase(temp.begin());
		Graf_lista[wezel] = temp;
		Wezly[wezel] = false;
	}
	Wyswietl_Graf();
}

void Graf::Wyswietl_Graf()
{
	cout << "Zawartosc grafu na liscie sasiedztwa: " << endl;
	for(map<string, vector<string> >::iterator i = Graf_lista.begin(); i != Graf_lista.end(); i++ )
	{
		cout << i->first << " ";
		for(vector<string>::iterator j = i->second.begin(); j != i->second.end(); j++)
		{
			cout << " " << *j;
		}
		cout << endl;
	}
		cout << endl;
		cout << "Odwiedzone wezly: " << endl;
		for(map<string, bool>::iterator w = Wezly.begin(); w != Wezly.end(); w++)
		{	
			cout << w->first << " " << w->second << endl;
		}
		cout << endl;
}

void Graf::Czysc_Odwiedzone()
{
	for(map<string, bool>::iterator i = Wezly.begin(); i != Wezly.end(); i++)
	{
		i->second = false;
	}
}

void Graf::BFS(string start)
{
	Czysc_Odwiedzone();
	Wezly[start] = true;
	queue<string> wezly_bfs;
	vector<string> odwiedzone;
	odwiedzone.push_back(start);
	for(vector<string>::iterator i = Graf_lista[start].begin(); i != Graf_lista[start].end(); i++)
	{
		wezly_bfs.push(*i);
		Wezly[*i] = true;
	}
	while(!wezly_bfs.empty())
	{
		string p = wezly_bfs.front();
		wezly_bfs.pop();
		odwiedzone.push_back(p);
		for(vector<string>::iterator i = Graf_lista[p].begin(); i != Graf_lista[p].end(); i++)
		{
			if(!Wezly[*i])
			{
				wezly_bfs.push(*i);
				Wezly[*i] = true;
			}
		}
	}
	cout << "Droga jaka przeszedl BFS podczas szukania: ";
	for(vector<string>::iterator i = odwiedzone.begin(); i != odwiedzone.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void Graf::DFS(string start)
{
	Czysc_Odwiedzone();
	Wezly[start] = true;
	stack<string> wezly_dfs;
	vector<string> odwiedzone;
	odwiedzone.push_back(start);
	for(vector<string>::iterator i = Graf_lista[start].begin(); i != Graf_lista[start].end(); i++)
	{
		wezly_dfs.push(*i);
		Wezly[*i] = true;
	}
	while(!wezly_dfs.empty())
	{
		string p = wezly_dfs.top();
		wezly_dfs.pop();
		odwiedzone.push_back(p);
		for(vector<string>::iterator i = Graf_lista[p].begin(); i != Graf_lista[p].end(); i++)
		{
			if(!Wezly[*i])
			{
				wezly_dfs.push(*i);
				Wezly[*i] = true;
			}
		}
	}
	cout << "Droga jaka przeszedl DFS podczas szukania: ";
	for(vector<string>::iterator i = odwiedzone.begin(); i != odwiedzone.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}