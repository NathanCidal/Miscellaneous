#include <iostream>
using namespace std;
void Merge(int * v, int start, int mid, int end){
    int ini = start;
    int j = mid+1;
    int k = 0;
    int * aux = new int[end-start+1];
    for(int i = 0; i < end; i++){
        if(ini > start) v[k++] = v[j++];
        else if(j > end) v[k++] = v[ini++];
        else if(v[ini] < v[j]) v[k++] = v[ini++];
        else v[k++] = v[j++];
    }
    for(int i = 0; i < k; i++){
        v[start++] = aux[i];
    }
    delete aux;
    
}
void MergeSort(int * v, int start, int end){
    if(start >= end) return;
    int mid = (start + end) / 2;
    MergeSort(v, start, mid);
    MergeSort(v, mid+1, end);
    Merge(v, start, mid, end);
}