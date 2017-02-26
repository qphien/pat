#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct node
{
	node() : parent(-1), left(-1), right(-1) {}
	int parent;
	int left;
	int right;
};
int find_root(const vector<node> &v)
{
	int i = 0;
	while (v[i].parent != -1)
		i = v[i].parent;
	return i;
}
int count_tree = -1;
int last_node;
void find_index(const vector<node> &v, int root, int number)
{
	if (root != -1)
	{
		count_tree = max(count_tree, number);
		find_index(v, v[root].left, number * 2);
		find_index(v, v[root].right, number * 2 + 1);
	}
}
void find_last_node(const vector<node> &v, int root)
{
	queue<int> q;
	q.push(root);
	int last = root;
	int level_last = root;
	int temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (v[temp].left != -1)
		{
			q.push(v[temp].left);
			level_last = v[temp].left;
		}
		if (v[temp].right != -1)
		{
			q.push(v[temp].right);
			level_last = v[temp].right;
		}
		if (temp == last)
		{
			last_node = last;
			last = level_last;
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	vector<node> v(n);
	for (int i = 0; i != n; ++i)
	{
		char left[3], right[3];
		//char temp;
		//scanf("%c", &temp);
		scanf("%s %s", &left, &right);
		if (left[0] != '-')
		{
			int temp = left[0] - '0';
			if (strlen(left) == 2)
				temp = temp * 10 + left[1] - '0';
			v[i].left = temp;
			v[temp].parent = i;
		}
		if (right[0] != '-')
		{
			int temp = right[0] - '0';
			if (strlen(right) == 2)
				temp = temp * 10 + right[1] - '0';
			v[i].right = temp;
			v[temp].parent = i;
		}
	}
	int root = find_root(v);
	find_index(v, root, 1);
	if (count_tree > n)
	{
		printf("NO ");
		printf("%d", root);
	}
	else
	{
		printf("YES ");
		find_last_node(v, root);
		printf("%d", last_node);
	}
}