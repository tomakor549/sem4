#include "BazaKlienci.h"
#include <chrono>


BazaKlienci::BazaKlienci()
{
	kolejnyIndeks = 0;
}


BazaKlienci::~BazaKlienci()
{
}
void BazaKlienci::sprawdzIndeks(int id){
	string wyjatek = "indeks juz istnieje";
	for (list <KolekcjaKlienta>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getIndeks() == id) {
			throw wyjatek;
		}
	}
}

void BazaKlienci::dodajKlienta(string imie, string nazwisko) {
	KolekcjaKlienta nowy(imie, nazwisko);
	nowy.setIndeks(kolejnyIndeks);
	kolejnyIndeks++;
	lista.push_back(nowy);
}

void BazaKlienci::dodajKlienta(KolekcjaKlienta nowy, int indeks) {
	nowy.setIndeks(indeks);
	lista.push_back(nowy);
}

void BazaKlienci::pokazDaneKlienta(int indeks) {
	if (indeks > 0 && indeks < lista.size()) {
		for (list <KolekcjaKlienta>::iterator it = lista.begin(); it != lista.end(); it++) {
			if (indeks == it->getIndeks()) {
				cout << it->getKlient().getNazwisko() << " " << it->getKlient().getImie() << "\n";
				it->pokazElementy();
			}
			else
				cout << "Zly indeks\n";
		}
	}
	else
		cout << "Zly indeks\n";
	
}

void BazaKlienci::wypozycz(int indeks, TowarElement &wypozyczany) {//(indeks, wypozyczTowar(string nazwa, string tytul))

	for (list <KolekcjaKlienta>::iterator it = lista.begin(); it != lista.end(); it++) {
		
		if(indeks==it->getIndeks()) {
			it->dodajElement(wypozyczany);
			return;
		}
	}
	cout << "Zly indeks\n";
}

void BazaKlienci::zwroc(int indeksKlienta) {
	if (indeksKlienta > 0 && indeksKlienta < lista.size())
	{
		int a;
		for (list <KolekcjaKlienta>::iterator it = lista.begin(); it != lista.end(); it++) {
			if (it->getIndeks() == indeksKlienta) {
				it->pokazElementy();
				while (true) {
					cout << "Ktory element chcesz usunac?\n";
					cin >> a;
					if (a > 0 && a < it->getStan().size())
					{
						it->usunElement(a);
						return;
					}
					else
						cout << "Zly numer\n";
				}

			}
		}
	}
}