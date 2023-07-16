#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define f first
#define s second
using namespace std;
typedef pair <int, int> pii;
 
int n, x, ptr1, ptr2;
pii arr[200005];
 
signed main(){
	SalAC;
	
	cin >> n >> x;
	ptr1 = 1, ptr2 = n;
	for (int i=1; i<=n; i++) cin >> arr[i].f, arr[i].s = i;
	sort(arr+1, arr+n+1);
	while (ptr1 != ptr2){
		if (arr[ptr1].f + arr[ptr2].f == x) break;
		else if (arr[ptr1].f + arr[ptr2].f > x) ptr2--;
		else if (arr[ptr1].f + arr[ptr2].f < x) ptr1++;
	}
	if (ptr1 == ptr2){
		cout << "IMPOSSIBLE";
	}
	else{
		cout << arr[ptr1].s << " " << arr[ptr2].s;
	}
}