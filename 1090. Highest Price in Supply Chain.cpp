#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
int depth;
int temp;
int number;
void dfs(int root, const vector<vector<int>> &v)
{
	++temp;
	if (temp > depth)
	{
		depth = temp;
		number = 1;
	}
	else if (temp == depth)
		++number;
	for (int i = 0; i != v[root].size(); ++i)
		dfs(v[root][i], v);
	--temp;
}
int main()
{
	int n;
	double price;
	double percentage;
	scanf("%d %lf %lf", &n, &price, &percentage);
	percentage /= 100;
	vector<vector<int>> v(n);
	int root;
	for (int i = 0; i != n; ++i)
	{
		int parent;
		scanf("%d", &parent);
		if (parent == -1)
			root = i;
		else
			v[parent].push_back(i);
	}
	dfs(root, v);
	double ans = price * pow(1 + percentage, depth - 1);
	printf("%.2lf %d\n", ans, number);
}