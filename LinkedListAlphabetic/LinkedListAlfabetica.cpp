#include <iostream>
#include <string>
#include <sstream>
#include "LinkedListAlfabetica.hpp"

using namespace std;

Nodo::Nodo(string n){
    this->next = nullptr;
    this->nome = n;
    this->prev = nullptr;
}

bool LinkedListAlfabetica::secondBigger(Nodo * aux, Nodo * e) const{
            string strB = e->nome;
            string strA = aux->nome;

            int tam1 = strA.length();
            int tam2 = strB.length();
            int realTam = tam1;
            if(tam1 < tam2) realTam = tam2;

            for(int i = 0; i < realTam; i++){
                if(i > tam1 && i <= tam2) return true;
                if(i < tam1 && i >= tam2) return false;

                if(strA[i] == strB[i]) continue;
                if(strA[i] < strB[i]) return true;
                if(strA[i] > strB[i]) return false;
            }
            return false;
}

LinkedListAlfabetica::LinkedListAlfabetica(){
    this->numElements = 0;
    head = nullptr;
    tail = nullptr;
}

LinkedListAlfabetica::~LinkedListAlfabetica(){
    while(head != nullptr){
        Nodo * aux = head;
        head = head->next;
        delete aux;
    }
    this->numElements = 0;
}

int LinkedListAlfabetica::getNumElements()const{
    return this->numElements;
}

bool LinkedListAlfabetica::isEmpty()const{
    if(numElements == 0) return true;
    return false;
}

void LinkedListAlfabetica::insere(Nodo * e){
            numElements++;
            if(head == nullptr){ head = tail = e; return;}

            string str = e->nome;

            Nodo * aux = head;
            while(aux != nullptr){
                if(secondBigger(aux, e) == false){
                    if(aux == head){
                        aux->prev = e;
                        e->next = aux;
                        head = e;
                        return;
                    }

                    aux->prev->next = e;
                    e->prev = aux->prev;
                    e->next = aux;
                    aux->prev = e;
                    return;
                }

                aux = aux->next;
            }

            tail->next = e;
            e->prev = tail;
            tail = e;
            return;
}

string LinkedListAlfabetica::str()const{
            stringstream ss;
            ss << "Head";
            Nodo * aux = head;
            while(aux != nullptr){
                ss << " -> " << aux->nome;
                aux = aux->next;
            }
            ss << endl;
            return ss.str();
}
