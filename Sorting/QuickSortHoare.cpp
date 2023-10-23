#include <iostream>
using namespace std;
void QuickSort(int * v, int start, int end){
    int i = start;
    int j = end;
    int pivot = v[(i+j)/2];
    while(i <= j){
        if(v[i] < pivot){ 
            i++; }
        if(v[j] > pivot){ 
            j--; }
        if(i <= j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    if(start < j) QuickSort(v, start, j);
    if(i < end) QuickSort(v, i, end);
}