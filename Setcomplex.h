//
// Created by Ewa Turska on 24.04.2018.
//

#ifndef V2_SETCOMPLEX_H
#define V2_SETCOMPLEX_H

#include <iostream>
#include <cmath>
#include "Complex.h"

template <typename Tre, typename Tim>
class Setcomplex {
    ///std::set<Complex<float, float>> lista;
    Complex<Tre, Tim>* lista;
    int bierzacyRozmiar, maxRozmiar;
public:
    Setcomplex(): bierzacyRozmiar(0), maxRozmiar(10){
        lista = new Complex<Tre, Tim> [10];
    };
    ~Setcomplex(){
        delete [] lista;
    }
    int dodajElement(Complex<Tre, Tim>& z) {
        //0-nie udalo sie zaalokowac pamieci, 1-elemnt juz wystaoil w zbiorze, 2-udalo sie dodac
        for(int i=0; i<bierzacyRozmiar; i++){
            if(*lista[i] == z)
                return;
        }

        if(bierzacyRozmiar == maxRozmiar-1) { // zwiekszamy tablice 2 krotnie
            Complex<Tre, Tim> * tmp = new Complex<Tre, Tim> [bierzacyRozmiar];
            for(int i=0; i<bierzacyRozmiar; i++)
                *tmp[i]= *lista[i];

            delete []lista;
            Complex<Tre, Tim> *lista = new Complex<Tre, Tim> [2*maxRozmiar];
            for(int i=0; i<bierzacyRozmiar; i++)
                *lista[i] = *tmp[i];

            *lista[bierzacyRozmiar] = z;
            bierzacyRozmiar++;
        }else{ //dodajemy na koniec tablicy obiekt complex
            *lista[bierzacyRozmiar] = z;
            bierzacyRozmiar++;
        }
    }
    void wypiszZbior() const{
        if(bierzacyRozmiar == 0)
            std::cout<<"Pusty zbior."<<std::endl;
        else{
            for(int i=0; i<bierzacyRozmiar-1; i++){
                std::cout<<lista[i]<<" ";
            }
        }
    }
    Complex<Tre, Tim> getElement(int numer) const{
        return lista[numer];
    }
    int listaSize() const{
        return bierzacyRozmiar;
    }
};
#endif //V2_SETCOMPLEX_H
