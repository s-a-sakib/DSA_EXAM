#include <bits/stdc++.h>
#define M 1000

using namespace std;

int maxHeapArray[M] , maxHeapSize = 0;

void insert(int data){
    int index = maxHeapSize;
    maxHeapArray[index] = data;

    if(maxHeapSize == 0){
        maxHeapSize++;
        return;
    }

    while(index != 0){
        if(data > maxHeapArray[index / 2]){
            swap(maxHeapArray[index] , maxHeapArray[index / 2]) ;
            index = index / 2 ;
        }else break;
    }
    maxHeapSize++;
}

