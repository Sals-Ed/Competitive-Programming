#include <iostream>
#include <deque> //以array基底實作monotonic_queue
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

//以嚴格遞增單調隊列為例

struct monotonic_queue{
	
	static const int N = 1e6 + 5;
	
	int front = 0, back = -1, mq[N];
	
	void push(int x){
		while (front <= back && mq[back] <= x){
			--back;
		}
		mq[++back] = x;
	}
	
	void pop(){
		++front;
	}
	
	void show(){
		for (int i=front; i<=back; i++){
			cout << mq[i] << " ";
		}
		cout << "\n";
	}
	
}sample;

signed main(){
	fastio;
	
	sample.push(9); // {9}
	sample.push(5); // {9, 5}
	sample.push(3); // {9, 5, 3}
	sample.push(1); // {9, 5, 3, 1}
	sample.show();
	
	sample.pop();
	sample.show(); // {5, 3, 1}
	
	sample.push(4); // {5, 3, 1} -> {5, 4}
	sample.show();
}