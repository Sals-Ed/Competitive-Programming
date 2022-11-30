#include <iostream>
#include <deque> //以deque基底實作monotonic_queue
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

//以嚴格遞增單調隊列為例

struct monotonic_queue{
	
	deque <int> mq;
	vector <int> tmp; //暫存deque內容
	
	void push(int x){
		while (!mq.empty() && mq.back() <= x){
			mq.pop_back();
		}
		mq.push_back(x);
	}
	
	void pop(){
		mq.pop_front();
	}
	
	void show(){
		while (!mq.empty()){
			cout << mq.front() << " ";
			tmp.push_back(mq.front());
			mq.pop_front();
		}
		for (int i: tmp){
			mq.push_back(i);
		}
		tmp.clear();
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