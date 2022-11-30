#include <iostream>
#include <vector> //以vector基底實作monotonic_stack
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

//以嚴格遞增單調堆疊為例

struct monotonic_stack{
	
	vector <int> ms;
	
	void push(int x){ //推入元素
		while (!ms.empty() && ms.back() >= x){
			ms.pop_back();
		}
		ms.push_back(x);
	}
	
	void pop(){ //彈出頂端元素
		ms.pop_back();
	}
	
	void show(){ //顯示堆疊內容
		for (int i: ms){
			cout << i << " ";
		}
		cout << "\n";
	}
}sample;

signed main(){
	fastio;
	
	sample.push(1); // {1}
	sample.push(4); // {1, 4}
	sample.push(7); // {1, 4, 7}
	sample.show();
	
	sample.pop();   // {1, 4}
	sample.show();
	
	sample.push(3); // {1, 4} -> {1, 3}
	sample.show();
}
