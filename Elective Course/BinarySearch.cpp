#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(int tar[], int l, int r, int val){
    int mid = (l + r) / 2;
    if (l == r && tar[mid] != val) return false;
    if (tar[mid] == val) return true;
    if (tar[mid] > val) return BinarySearch(tar, l, mid, val);
    if (tar[mid] < val) return BinarySearch(tar, mid+1, r, val);
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    for (int i=0; i<20; i++){
        cout << BinarySearch(a, 0, 9, i);
    }
}