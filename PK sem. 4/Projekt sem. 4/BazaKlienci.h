#pragma once
#include "KolekcjaKlienta.h"
#include "TowarElement.h"
#include <list>

using namespace std;

class BazaKlienci{
	int kolejnyIndeks;
	list <KolekcjaKlienta> lista;
public:
	void dodajKlienta(string imie, string nazwisko);
	void dodajKlienta(KolekcjaKlienta nowy, int indeks);
	void pokazDaneKlienta(int indeks);
	void wypozycz(int indeks, TowarElement& wypozyczany);
	void zwroc(int indeksKlienta);
	void sprawdzIndeks(int id);
	list <KolekcjaKlienta> *getLista() { return &lista; }
	BazaKlienci();
	~BazaKlienci();
};

