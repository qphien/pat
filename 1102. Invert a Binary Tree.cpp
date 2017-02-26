#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

struct node
{
	int left;
	int right;
};
void level_traversal(int root, const vector<node> &v)
{
	queue<int> q;
	q.push(root);
	int number = 0;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (number++ != 0)
			cout << ' ';
		cout << temp;
		if (v[temp].right != -1) q.push(v[temp].right);
		if (v[temp].left != -1) q.push(v[temp].left);
	}
}
int number = 0;
void inorder_traversal(int root, const vector<node> &v)
{
	if (root != -1)
	{
		inorder_traversal(v[root].right, v);
		if (number != 0)
			cout << ' ';
		cout << root;
		++number;
		inorder_traversal(v[root].left, v);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<node> v(n);
	vector<bool> flag(n);
	for (int i = 0; i != n; ++i)
	{
		char left[2], right[2];
		scanf("%s %s", &left, &right);
		if (left[0] == '-')
			v[i].left = -1;
		else
		{
			v[i].left = left[0] - '0';
			flag[left[0] - '0'] = true;
		}
		if (right[0] == '-')
			v[i].right = -1;
		else
		{
			v[i].right = right[0] - '0';
			flag[right[0] - '0'] = true;
		}
	}
	int root;
	for (int i = 0; i != n; ++i)
	{
		if (!flag[i])
		{
			root = i;
			break;
		}
	}
	level_traversal(root, v);
	cout << endl;
	inorder_traversal(root, v);
}