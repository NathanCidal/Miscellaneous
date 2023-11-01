#ifndef _SORTING_TEMPLATE_HPP
#define _SORTING_TEMPLATE_HPP

#include <iostream>
#include <string>
#include <set>

using namespace std;

template <typename T>
void BubbleSort(T * v, int tam){
    bool isSorted = false;
    int t = tam;
    do{
        --t;
        isSorted = true;
        for(int i = 0; i < t; i++){
            if(v[i] > v[i+1]){
                T aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                isSorted = false;
            }
        }
    }while(isSorted == false);
}

template <typename T>
void SelectionSort(T * v, int tam){
    for(int i = 0; i < tam; i++){
        T smallest = v[i];
        int smlIdx = i;
        for(int j = i + 1; j < tam; j++){
            if(v[j] < v[smlIdx]){
                smlIdx = j;
            }
        }

        if(i != smlIdx){
            T aux = v[i];
            v[i] = v[smlIdx];
            v[smlIdx] = aux;
        }
    }
}

template <typename T>
void InserctionSort(T * v, int tam){
    for(int i = 1; i < tam; i++){
        T base = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > base){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = base;
    }
}

template <typename T>
void quickSort(T * v, int begin, int end){
    int i = begin;
    int j = end;

    T pivot = v[(i+j)/2];

    while(i <= j){
        while(v[i] < pivot) i++;
        while(v[j] > pivot) j--;

        if(i <= j){
            T aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    if(begin < j) quickSort(v, begin, j);
    if(i < end) quickSort(v, i, end);
    
}

template <typename T>
void merge(T * v, int begin, int mid, int end){
    //Implementar
    int ini = begin;
    int j = mid + 1;
    int k = 0;
    T * aux = new T[end - begin + 1];

    for(int i = 0; i <= end; i++){
        if(ini > mid)            aux[k++] = v[j++];
        else if (j > end)        aux[k++] = v[ini++];
        else if (v[ini] < v[j])  aux[k++] = v[ini++];
        else                     aux[k++] = v[j++];
    }

    for(int i = 0; i < k; i++){
        v[begin++] = aux[i];
    }

    delete[] aux;
}

template <typename T>
void mergeSort(T * v, int begin, int end){
    //Implementar
    if(begin >= end) return;
    int mid = (begin + end) / 2;

    mergeSort(v, begin, mid);
    mergeSort(v, mid + 1, end);
    merge(v, begin, mid, end);
}

#endif