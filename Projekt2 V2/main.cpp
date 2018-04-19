#include <iostream>
#include <limits>
#include <list>
using namespace std;

#include "Complex.h"
#include "Setcomplex.h"

int main() {
	/*cout << "Podaj re oraz im" << endl;
	double re, im;
	cin >> re >> im;
	Complex zesp1(re, im);
	cout << zesp1;
	cin >> re >> im;
	Complex zesp2(re, im);
	cout << zesp2;
	Complex w = zesp1 + zesp2;*/
	int opcja, wczytNumZbi, wczytNumZbi2;
	float re, im;
	list <Setcomplex<float, float>> zbiory;

	while (1) {
		cout << "MENU" << endl;
		cout << "1 Dodaj nowy pusty zbior" << endl;
		cout << "2 Dodaj liczbe do zbioru" << endl;
		cout << "3 Iloczyn zbiorow" << endl;
		cout << "4 Suma zbiorow" << endl;
		cout << "5 Wypisz zbiory" << endl;
		cout << "0 Wyjscie z programu" << endl;
		cout << "Liczby wprowadzamy w postaci: czesc_rzeczywista czesc_urojona" << endl;
		//cin >> opcja;
		while (!(cin >> opcja)) {
			cout << endl << "Blad! Podaj odpowiedni numer ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (opcja == 1) {
			Setcomplex <float, float> s;
			zbiory.push_back(s);
			cout << "Dodano zbior o numerze: " << zbiory.size()-1 << endl;
		}
		else if (opcja == 2) { //dodaj element
			cout << "Podaj liczbe z ";
			while (!(cin >> re >> im)) {
				cout << endl << "Blad! Podaj liczbe z ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			Complex<float, float> z(re, im);
			cout << "Podaj do ktorego zbioru chcesz dodac liczbe: ";
			while (true) {
				while (!(cin >> wczytNumZbi)) {
					cout << endl << "Blad! Podaj numer zbioru ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (wczytNumZbi<0 || wczytNumZbi>=zbiory.size()) {
					cout << "Nie ma takiego zbioru, podaj jeszcze raz: ";
					continue;
				}
				break;
			}
			auto iterator = zbiory.begin();
			for (int i = 0; i < wczytNumZbi; i++) { iterator++; }
			iterator->dodajElement(z);
			cout << "Dodano element " <<z<<" do zbioru numer "<<wczytNumZbi<< endl;
		}
		else if (opcja == 3) { //iloczyn
			cout << "Podaj numery dwoch zbiorow ktorych czesci wspolnej szukasz(iloczyn): " << endl;
			while (true) {
				while (!(cin >> wczytNumZbi >> wczytNumZbi2)) {
					cout << endl << "Blad! Podaj numery zbiorow ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (wczytNumZbi<0 || wczytNumZbi >= zbiory.size() || wczytNumZbi2<0 || wczytNumZbi2 >= zbiory.size()) {
					cout << "Nie ma takiego zbioru, podaj jeszcze raz: ";
					continue;
				}
				break;
			}
			Setcomplex<float, float> iloczyn;
			auto zb1 = zbiory.begin();
			auto zb2 = zbiory.begin();
			for (int i = 0; i < wczytNumZbi; i++) { zb1++; }
			for (int i = 0; i < wczytNumZbi2; i++) { zb2++; }
			////Iloczynowanie
			for (int i = 0; i < zb1->listaSize(); i++) {
				for (int j = 0; j < zb2->listaSize(); j++) {
					if (zb1->getElement(i) == zb2->getElement(j)) {
						iloczyn.dodajElement(zb1->getElement(i));
					}
				}
			}
			/*for (int i = 0; i < zb2->listaSize(); i++) {
				for (int j = 0; j < zb1->listaSize(); j++) {
					if (zb2->getElement(i) == zb1->getElement(j)) {
						iloczyn.dodajElement(zb2->getElement(i));
					}
				}
			}*/
			cout << "Iloczyn zbiorow: ";
			iloczyn.wypiszZbior();
			cout << endl;
		}
		else if (opcja == 4) { //suma
			cout << "Podaj numery dwoch zbiorow ktorych sumy szukasz: " << endl;
			while (true) {
				while (!(cin >> wczytNumZbi >> wczytNumZbi2)) {
					cout << endl << "Blad! Podaj numery zbiorow ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (wczytNumZbi<0 || wczytNumZbi >= zbiory.size() || wczytNumZbi2<0 || wczytNumZbi2 >= zbiory.size()) {
					cout << "Nie ma takiego zbioru, podaj jeszcze raz: ";
					continue;
				}
				break;
			}
			Setcomplex<float, float> suma;
			auto zb1 = zbiory.begin();
			auto zb2 = zbiory.begin();
			for (int i = 0; i < wczytNumZbi; i++) { zb1++; }
			for (int i = 0; i < wczytNumZbi2; i++) { zb2++; }
			////Sumowanie
			for (int i = 0; i < zb1->listaSize(); i++) {
				suma.dodajElement(zb1->getElement(i));
			}
			for (int i = 0; i < zb2->listaSize(); i++) {
				suma.dodajElement(zb2->getElement(i));
			}
			cout << "Suma zbiorow: ";
			suma.wypiszZbior();
			cout << endl;
		}
		else if (opcja == 5) { //wypisanie zbiorow
			int i = 0;
			if (zbiory.empty()) {
				cout << "Brak zbiorow" << endl;
			}
			for (auto it = zbiory.begin(); it != zbiory.end(); it++, i++) {
				cout << "Zbior numer: " << i << endl;
				it->wypiszZbior();
				cout << endl;
			}
		}
		else if (opcja == 0) {
			break;
		}
		else {
			cout << "Bladna opcja!" << endl;
		}
	}
	return 0;
}