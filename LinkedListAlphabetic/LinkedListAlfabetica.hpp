#ifndef _LINKEDLISTALFABETICA_HPP
#define _LINKEDLISTALFABETICA_HPP

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Nodo{
    string nome;
    Nodo * next;
    Nodo * prev;
    Nodo(string n);
};

class LinkedListAlfabetica{
    private:
        Nodo * head;
        Nodo * tail;
        int numElements;

    public:
        LinkedListAlfabetica();

        ~LinkedListAlfabetica();

        int getNumElements()const;

         bool secondBigger(Nodo * aux, Nodo * e) const;
        
        bool isEmpty()const;
        
        void insere(Nodo * e);

        string str()const;
}; 

#endif