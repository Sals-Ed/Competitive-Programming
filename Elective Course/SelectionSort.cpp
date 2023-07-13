#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int tar[], int n){
    int minIdx;
    for (int i=0; i<n; i++){
        minIdx = i; 
        for (int j=i+1; j<n; j++){
            if (tar[j] < tar[minIdx]){
                minIdx = j;
            }
        }
        swap(tar[minIdx], tar[i]);
    }
    return;
}

int main(){
    int a[] = {5, 3, 2, 1, 4};
    
    SelectionSort(a, 5);
    
    for (int i=0; i<5; i++){
        cout << a[i];
    }
}