#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int tar[], int n){
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<i; j++){
            if (tar[j] > tar[j+1]){
                swap(tar[j], tar[j+1]);
            }
        }
    }
    return;
}

int main(){
    int a[] = {5, 3, 2, 1, 4};
    
    BubbleSort(a, 5);
    
    for (int i=0; i<5; i++){
        cout << a[i];
    }
}