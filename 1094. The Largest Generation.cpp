#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
void level_traversal(int root, const vector<vector<int>> &v)
{
	queue<int> q;
	q.push(root);
	int last = root;
	int level_last = root;
	int level = 1;
	int ans_level = 1;
	int max_number = 1;
	int number = 0;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (auto val : v[temp])
		{
			q.push(val);
			++number;
			level_last = val;
		}
		if (temp == last)
		{
			last = level_last;
			++level;
			if (number > max_number)
			{
				ans_level = level;
				max_number = number;
			}
			number = 0;
		}
	}
	printf("%d %d\n", max_number, ans_level);
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> v(n + 1, vector<int>());
	for (int i = 0; i != m; ++i)
	{
		int parent, number;
		scanf("%d %d", &parent, &number);
		for (int j = 0; j != number; ++j)
		{
			int child;
			scanf("%d", &child);
			v[parent].push_back(child);
		}
	}
	level_traversal(1, v);
}