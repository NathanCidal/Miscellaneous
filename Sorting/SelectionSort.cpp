#include <iostream>
using namespace std;
void SelectionSort(int * v, int s){
    int size = s;
    for(int i = 0; i < size-1; i++){
        int smallest = i;
        for(int j = i+1; j < size; i++){
            if(v[smallest] > v[j]){
                smallest = j;
            }
        }

        if(smallest != i){
            int aux = v[i];
            v[i] = v[smallest];
            v[smallest] = aux;
        }
    }
}