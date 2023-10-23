#include <iostream>
using namespace std;

void BubbleSort(int * v, int s){
    int size = s;
    bool notSorted = true;
    do{
        size--;
        notSorted = false;
        for(int i = 0; i < size; i++){
            if(v[i] > v[i+1]){
                notSorted = true;
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            } 
        }
    }while(notSorted);
}