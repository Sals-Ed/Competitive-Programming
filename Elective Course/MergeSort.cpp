#include <bits/stdc++.h>
using namespace std;

vector<int> MergeSort(int tar[], int n, int l, int r){
    vector <int> Merge;
    if (l == r){
        Merge.push_back(tar[l]);
        return Merge;
    }
    int mid = (l + r) / 2;
    vector <int> lv = MergeSort(tar, 5, l, mid);
    vector <int> rv = MergeSort(tar, 5, mid+1, r);
    
    Merge.resize(r-l+1);
    int lptr = 0, rptr = 0;
    merge(lv.begin(), lv.end(), rv.begin(), rv.end(), Merge.begin());
    return Merge;
}

int main(){
    int a[] = {5, 3, 2, 1, 4};
    
    vector <int> sample = MergeSort(a, 5, 0, 4);
    
    for (int i=0; i<5; i++){
        cout << sample[i];
    }
}