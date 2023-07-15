#include <bits/stdc++.h>
using namespace std;

int factorial(long long n, int mod = 1e9+7){
    if (n == 0) return 1;
    return (factorial(n-1) * n) % mod;
}

int main(){
    cout << factorial(7)     << "\n"; // 7! = 5040
    cout << factorial(7, 11) << "\n"; // 7!(mod11) = 5040(mod11) = 2
}