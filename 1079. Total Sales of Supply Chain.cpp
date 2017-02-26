#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int N;
double price;
double percentage;
double ans;
struct node;
vector<node> v;
struct node
{
	int data;
	vector<int> child;
};

void dfs(int src, int depth)
{
	if (v[src].child.empty())
	{
		ans += price * pow(1 + percentage, depth) * v[src].data;
		return;
	}
	for (int i = 0; i != v[src].child.size(); ++i)
		dfs(v[src].child[i], depth + 1);
}
int main()
{
	cin >> N >> price >> percentage;
	percentage /= 100;
	v.resize(N);
	for (int i = 0; i != N; ++i)
	{
		int number;
		scanf("%d", &number);
		if (number == 0)
		{
			int count;
			scanf("%d", &count);
			v[i].data = count;
		}
		else
		{
			for (int j = 0; j != number; ++j)
			{
				int index;
				scanf("%d", &index);
				v[i].child.push_back(index);
			}
		}
	}
	dfs(0, 0);
	printf("%.1lf", ans);
}