#pragma once

#include <iostream>
#include <set>
#include <cmath>

template <typename Tre, typename Tim>
class Setcomplex {
	std::set<Complex<float, float>> lista;
public:
	void dodajElement(Complex<Tre, Tim>& z) {
		lista.insert(z);
	}
	void wypiszZbior() const{
		if (lista.empty()) {
			cout << "Zbior pusty";
		}
		else {
			for (auto it = lista.begin(); it != lista.end(); it++)
				cout << *it << " ";
		}
	}
	Complex<Tre, Tim> getElement(int numer) const{
		auto it = lista.begin();
		for (int i = 0; i < numer; i++) { it++; }
		return *it;
	}
	int listaSize() const{
		return lista.size();
	}
};