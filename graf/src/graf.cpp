#include <iostream>
#include "graf.hh"
/*!
 *\file Definicje poszczegolnych funkcji dla klasy Graf.
 */
using namespace std;

Graf::Graf()
{
	wezel = 0;
}

Graf::~Graf()
{
	if(this->wezel)
		delete this->wezel;
}

ostream& operator << (ostream& wyjscie, const Graf& graf)
{
	wyjscie << "Graf:";
	if(graf.wezel)
	{
		wyjscie << endl;
		wyjscie << *(graf.wezel); 
		wyjscie << endl;
	}
	wyjscie << "";
	return wyjscie;
}

bool Graf::Szukaj_Wezel(int klucz)
{
	Wezel * temp = wezel;
	while(temp)
		if(temp->klucz == klucz)
			return true;
		else
			temp = temp->nastepny;
		return false;
}

bool Graf::empty()
{
	return !wezel;
}

Graf::Wezel * Graf::Znajdz_Wezel(int klucz)
{
	Wezel * temp = wezel;
	bool znaleziony = false;
	while(!znaleziony && temp)
		if(temp->klucz == klucz)
			znaleziony = true;
		else
			temp = temp->nastepny;
	return (znaleziony) ? temp : 0;
}

void Graf::Dodaj_Wezel(int klucz)
{
	if(this->empty())
	{
		Wezel * _wezel = new Wezel(klucz);
		wezel = _wezel;
	}
	else
	{
		if(!this->Szukaj_Wezel(klucz))
		{
			Wezel * _wezel = new Wezel(klucz);
			_wezel->nastepny = wezel;
			wezel = _wezel;
		}
	}
	
}

void Graf::Dodaj_Krawedz(int wezel_klucz, int cel, int waga)
{
	if(this->Szukaj_Wezel(wezel_klucz) && this->Szukaj_Wezel(cel))
		this->Znajdz_Wezel(wezel_klucz)->Dodaj_Krawedz(cel, waga);
}

void Graf::Usun_Wezel(int klucz)
{
	if(!empty())
	{
		if(wezel->klucz == klucz)
		{
			Wezel * usun = wezel;
			wezel = wezel->nastepny;
			usun->nastepny = 0;
			delete usun;
		}
		else
		{
			Wezel * temp = wezel;
			while(temp->nastepny && temp->nastepny->klucz != klucz)
				temp = temp->nastepny;
			if(temp->nastepny && temp->nastepny->klucz == klucz)
			{
				Wezel * usun = temp->nastepny;
				temp->nastepny = temp->nastepny->nastepny;
				usun->nastepny = 0;
				delete usun;
			}
		}
		this->Usun_Istniejace_Krawedzie(klucz);
	}
}

void Graf::Usun_Istniejace_Krawedzie(int klucz)
{
	if(!empty())
	{
		Wezel * temp = wezel;
		while(temp)
		{
			temp->Usun_Krawedz(klucz);
			temp = temp->nastepny;
		}
	}
}

void Graf::Usun_Krawedz(int wezel_klucz, int cel)
{
	if(this->Szukaj_Wezel(wezel_klucz))
		this->Znajdz_Wezel(wezel_klucz)->Usun_Krawedz(cel);
}

Graf::Wezel::Wezel(int klucz)
{
	this->klucz = klucz;
	nastepny = 0;
	krawedz = 0;
}

Graf::Wezel::~Wezel()
{
	if(this->krawedz)
		delete this->krawedz;
	if(this->nastepny)
		delete this->nastepny;
}

ostream& operator << (ostream & wyjscie, const Graf::Wezel& wezel)
{
	wyjscie << wezel.klucz;
	if(wezel.krawedz)
		wyjscie << *(wezel.krawedz);
	if(wezel.nastepny)
	{
		wyjscie << endl << *(wezel.nastepny);
	}
	return wyjscie;
}

bool Graf::Wezel::Szukaj_Krawedz(int cel)
{
	Krawedz * temp = krawedz;
	while(temp)
		if(temp->cel == cel)
			return true;
		else
			temp = temp->nastepny;
	return false;
}

bool Graf::Wezel::empty()
{
	return !krawedz;
}

void Graf::Wezel::Dodaj_Krawedz(int cel, int waga)
{
	if(this->empty())
	{
		Krawedz * _krawedz = new Krawedz(cel, waga);
		krawedz = _krawedz;
	}
	else
	{
		if(!this->Szukaj_Krawedz(cel))
		{
			Krawedz * _krawedz = new Krawedz(cel, waga);
			_krawedz->nastepny = this->krawedz;
			this->krawedz = _krawedz;
		}
	}
}

void Graf::Wezel::Usun_Krawedz(int cel)
{
	if(!empty())
	{
		if(krawedz->cel == cel)
		{
			Krawedz * usun = krawedz;
			krawedz = krawedz->nastepny;
			usun->nastepny = 0;
			delete usun;
		}
		else
		{
			Krawedz * temp = krawedz;
			while(temp->nastepny && temp->nastepny->cel != cel)
				temp = temp->nastepny;
			if(temp->nastepny && temp->nastepny->cel == cel)
			{
				Krawedz * usun = temp->nastepny;
				temp->nastepny = temp->nastepny->nastepny;
				usun->nastepny = 0;
				delete usun;
			}
		}
	}
}

Graf::Wezel::Krawedz::Krawedz(int a, int b)
{
	this->cel = a;
	this->waga = b;
	nastepny = 0;
}

Graf::Wezel::Krawedz::~Krawedz()
{
	if(this->nastepny)
		delete this->nastepny;
}

ostream& operator << (ostream& wyjscie, const Graf::Wezel::Krawedz& krawedz)
{
	wyjscie << " krawedz z wezlem - ";
	wyjscie << " " << krawedz.cel << " (waga: " << krawedz.waga << ") ";
	if(krawedz.nastepny)
	{
		wyjscie << ", ";
		wyjscie << *(krawedz.nastepny);
	}
	return wyjscie;
}