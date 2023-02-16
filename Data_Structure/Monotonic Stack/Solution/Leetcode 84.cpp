class Solution {
public:
    
    // 對於每一根長條，找其左/右第一個較矮的長條位置
    // 再遍歷每一根長條取最大值
    
	struct bar{
		int l, r;
	};
	 
	int largestRectangleArea(vector<int>& heights) {
	 
		int ans = 0, n = (int)heights.size();
		
		heights.insert(heights.begin(), -1);
		heights.push_back(-1);
		
        	bar arr[n+5];
        
		vector <int> tmp;
	 
		tmp.push_back(0);
	 
		for (int i=1; i<=n; i++){ // 找左邊
			
			while (!tmp.empty() && heights[tmp.back()] >= heights[i]) tmp.pop_back();
			
			arr[i].l = tmp.back();
			
			tmp.push_back(i);
		}
	 
		while (!tmp.empty()) tmp.pop_back(); tmp.push_back(n+1); //  清空堆疊
	 
		for (int i=n; i>0; i--){ // 找右邊
			
			while (!tmp.empty() && heights[tmp.back()] >= heights[i]) tmp.pop_back();
			
			arr[i].r = tmp.back();
			
			tmp.push_back(i);
		}
		
		// 遍歷取最大面積
		for (int i=1; i<=n; i++) ans = max(ans, (arr[i].r - arr[i].l - 1) * heights[i]);
		
		return ans;
	}
};
