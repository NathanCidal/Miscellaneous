#include <iostream>
using namespace std;
void InserctionSort(int * v, int t){
    for(int i = 1; i < t; i++){
        int base = i;
        int j = i - 1;
        while(j >= 0 && v[j] > v[base]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = v[base];
    }
}