class Solution {
public:
int fun(vector<int>& h)
{
	if (h.size() == 0)
	{
		return 0;
	}
	h.push_back(0);
	stack<int>s;
	int mx = 0;
	int n = h.size();
	s.emplace(0);
	for (int i = 0; i <n; i++)
	{
		while (!s.empty()&&h[i] <h[ s.top()])
		{
			int t = s.top();
			s.pop();
			int w = s.empty() ? i : i - s.top() - 1;
			mx = max(mx, w * h[t]);
		}
		s.emplace(i);
	}
	return mx;
}
int maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int mx;
	vector<int>h(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '1')
			{
				h[j] = h[j] == 0 ? 1 : h[j] + 1;
			}
			else
			{
				h[j] = 0;
			}
		}
		mx = max(mx, fun(h));
	}
	return mx;
}
};
