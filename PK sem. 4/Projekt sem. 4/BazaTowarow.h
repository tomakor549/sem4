#pragma once
#include "TowarElement.h"
#include <list>
using namespace std;

class BazaTowarow
{
	int kolejnyIndeks;
	list <TowarElement> lista;
public:
	void dodajTowar(string autor, string nazwa, string wydawca, string gatunek, int dataPublikacji);
	void dodajTowar(TowarElement nowy, int indeks);
	TowarElement& wypozyczTowar(string autor, string nazwa);
	TowarElement& wypozyczTowar(int indeks);
	void usunTowar(int indeks);
	void wypiszTowaryAutora(string nazwa);
	void wypiszTowaryTytul(string nazwa);
	void wypiszTowaryWydawca(string nazwa);
	void wypiszTowaryGatunek(string nazwa);
	void wypiszTowaryData(int data);
	void wypiszTowary();
	int wypiszRozmiarListy() { return lista.size(); }
	list <TowarElement>* getLista() { return &lista; }
	BazaTowarow();
	~BazaTowarow();
};

