class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
	heights.push_back(0);
	int n = heights.size();
	stack<int>st;
	st.push(0);
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		while (!st.empty()&&  heights[st.top()] > heights[i])
		{
			int h = st.top();
			st.pop();
			int width = st.empty() ? i : i - st.top() - 1;
			mx = max(mx, heights[h] * width);
		}
			st.push(i);
	}
	return mx;
}
};
