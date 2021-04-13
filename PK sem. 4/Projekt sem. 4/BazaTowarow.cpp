#include "BazaTowarow.h"



BazaTowarow::BazaTowarow()
{
	kolejnyIndeks = 0;
}


BazaTowarow::~BazaTowarow()
{
}

void BazaTowarow::dodajTowar(TowarElement nowy, int indeks) {
	nowy.setIndeks(indeks);
	lista.push_back(nowy);
}

void BazaTowarow::dodajTowar(string autor, string nazwa, string wydawca, string gatunek, int dataPublikacji) {
	TowarElement nowy(autor, nazwa, wydawca, gatunek, dataPublikacji);
	nowy.setIndeks(kolejnyIndeks);
	kolejnyIndeks++;
	lista.push_back(nowy);
}

TowarElement& BazaTowarow::wypozyczTowar(string autor, string nazwa) {
	lista.sort([](TowarElement a, TowarElement b) {return a.getTowar().getAutor() < b.getTowar().getAutor(); });
	std::string wyjatek1 = "Autor nie posiada szukanego tytulu\n";
	std::string wyjatek2 = "Nie znaleziono autora\n";
	std::string wyjatek3 = "Nie ma wolnych towarow\n";

	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getTowar().getAutor() == autor) {
			if (it->getTowar().getNazwa() == nazwa && it->getStan() == 0)
				return (*it);
			it++;
			while (true) {
				if (it != lista.end()) {
					if (it->getTowar().getNazwa() == nazwa)
						if (it->getStan() == 0) {
							return (*it);
							it++;
						}
				}
				throw wyjatek3;					
			}
			throw wyjatek1;
		}
	}
	throw wyjatek2;
}

TowarElement& BazaTowarow::wypozyczTowar(int indeks) {
	lista.sort([](TowarElement a, TowarElement b) {return a.getIndeks() < b.getIndeks(); });
	std::string wyjatek = "juz wypozyczono";

	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getIndeks() == indeks) {
			if (it->getStan() == 0)
				return (*it);
			else {
				throw wyjatek;
			}
		}
	}
}
void BazaTowarow::wypiszTowaryAutora(string nazwa) {
	lista.sort([](TowarElement a, TowarElement b) {return a.getTowar().getAutor() < b.getTowar().getAutor(); });
	 
	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getTowar().getAutor() == nazwa) {
			std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
			 
			it++;
			while (it->getTowar().getAutor() == nazwa) {
				std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
				 
				it++;
			}
			return;
		}
	}
	std::cout << "Nie ma takiego towaru";
}
void BazaTowarow::wypiszTowaryTytul(string nazwa) {
	lista.sort([](TowarElement a, TowarElement b) {return a.getTowar().getNazwa() < b.getTowar().getNazwa(); });
	 
	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getTowar().getNazwa() == nazwa) {
			std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
			 
			it++;
			while (it->getTowar().getNazwa() == nazwa) {
				std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
				 
				it++;
			}
			return;
		}
	}
	std::cout << "Nie ma takiego towaru";
}
void BazaTowarow::wypiszTowaryWydawca(string nazwa) {
	lista.sort([](TowarElement a, TowarElement b) {return a.getTowar().getWydawca() < b.getTowar().getWydawca(); });
	 
	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getTowar().getWydawca() == nazwa) {
			std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
			 
			it++;
			while (it->getTowar().getWydawca() == nazwa) {
				std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
				 
				it++;
			}
			return;
		}
	}
	std::cout << "Nie ma takiego towaru";
}
void BazaTowarow::wypiszTowaryGatunek(string nazwa) {
	lista.sort([](TowarElement a, TowarElement b) {return a.getTowar().getGatunek() < b.getTowar().getGatunek(); });
	 
	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getTowar().getGatunek() == nazwa) {
			std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
			 
			it++;
			while (it->getTowar().getGatunek() == nazwa) {
				std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
				 
				it++;
			}
			return;
		}
	}
	std::cout << "Nie ma takiego towaru";
}
void BazaTowarow::wypiszTowaryData(int data) {
	lista.sort([](TowarElement a, TowarElement b) {return a.getTowar().getRokWydania() < b.getTowar().getRokWydania(); });
	 
	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getTowar().getRokWydania() == data) {
			std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
			 
			it++;
			while (it->getTowar().getRokWydania() == data) {
				std::cout <<  it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
				 
				it++;
			}
			return;
		}
	}
	std::cout << "Nie ma takiego towaru";
}
void BazaTowarow::wypiszTowary() {
	lista.sort([](TowarElement a, TowarElement b) {return a.getIndeks() < b.getIndeks(); });
	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		std::cout << it->getIndeks() << ": \"" << it->getTowar().getNazwa() << "\" " << it->getTowar().getAutor() << "\n";
	}
}

void BazaTowarow::usunTowar(int indeks) {
	if(lista.size()/2>indeks)
		lista.sort([](TowarElement a, TowarElement b) {return a.getIndeks() < b.getIndeks(); });
	else
		lista.sort([](TowarElement a, TowarElement b) {return a.getIndeks() > b.getIndeks(); });

	for (list <TowarElement>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getIndeks() == indeks) {
			if (it->getStan() == false) {
				it->setStan(true);
			}
			else {
				int wybor;
				cout << "Towar jest uznany za wypozyczony. Na pewno chcesz usunac?\n1-Tak\n2-Nie\n";
				while (true) {
					cin >> wybor;
					if (wybor > 0 && wybor < 3)
					{
						if (wybor == 1) {
							it->setStan(true);
							return;
						}
						else
							return;
					}
					else
						cout << "\nzly wybor, sproboj jeszcze raz.\n1-usuwam\n2-zostawiam\n";
				}
			}
		}
	}
	cout << "Zly indeks\n";
}