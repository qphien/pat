#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int number = 0;
struct node
{
	int val;
	int left;
	int right;
};
void inorder_traversal(int root, vector<node> &v, const vector<int> &t)
{
	if (root != -1)
	{
		inorder_traversal(v[root].left, v, t);
		v[root].val = t[number++];
		inorder_traversal(v[root].right, v, t);
	}
}

void level_traversal(int root, const vector<node> &v)
{
	queue<int> q;
	q.push(root);
	int number = 0;
	while (!q.empty())
	{
		int index = q.front();
		q.pop();
		if (number++ != 0)
			printf(" ");
		printf("%d", v[index].val);
		if (v[index].left != -1) q.push(v[index].left);
		if (v[index].right != -1) q.push(v[index].right);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	vector<node> v(n);
	for (int i = 0; i != n; ++i)
	{
		int left, right;
		scanf("%d %d", &left, &right);
		v[i].left = left;
		v[i].right = right;
	}
	vector<int> t(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &t[i]);
	sort(t.begin(), t.end());
	inorder_traversal(0, v, t);
	level_traversal(0, v);
	printf("\n");
}
