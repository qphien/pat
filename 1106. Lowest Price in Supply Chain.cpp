#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int min_depth = 1 << 31 - 1;   //min_depthÐè´óÓÚ10^5
int temp_depth = -1;
int cnt = 1;
void dfs(const vector<vector<int>> &v, int root)
{
	++temp_depth;
	if (v[root].size() == 0)
	{
		if (temp_depth < min_depth)
		{
			min_depth = temp_depth;
			cnt = 1;
		}
		else if (temp_depth == min_depth)
			++cnt;
		--temp_depth;
		return;
	}
	for (int i = 0; i != v[root].size(); ++i)
		dfs(v, v[root][i]);
	--temp_depth;
}
int main()
{
	int n;
	double price, percentage;
	scanf("%d %lf %lf", &n, &price, &percentage);
	percentage /= 100;
	vector<vector<int>> v(n, vector<int>());
	for (int i = 0; i != n; ++i)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j != k; ++j)
		{
			int temp;
			scanf("%d", &temp);
			v[i].push_back(temp);
		}
	}
	dfs(v, 0);
	double ans = price * pow(1 + percentage, min_depth);
	printf("%.4lf %d\n", ans, cnt);
}
