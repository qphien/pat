#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
	int val;
	node *left;
	node *right;
};
vector<int> pre_order, post_order;
bool flag = true;
node *create(int preL, int preR, int postL, int postR)
{
	if (preL > preR) return 0;
	node *root = new node;
	root->val = pre_order[preL];
	root->left = root->right = 0;
	if (preL == preR)
	{
		return root;
	}
	int i;
	for (i = preL + 1; i <= preR; ++i)
		if (pre_order[i] == post_order[postR - 1])
			break;
	if (i - preL > 1)
	{
		root->left = create(preL + 1, i - 1, postL, postL + i - preL - 2);
		root->right = create(i, preR, postR + i - preR - 1, postR - 1);
	}
	else
	{
		flag = false;
		root->right = create(i, preR, postR + i - preR - 1, postR - 1);
	}
	return root;
}
int number = 0;
int n;
void inorder(node *root)
{
	if (root)
	{
		inorder(root->left);
		if (++number > 1)
			cout << ' ';
		cout << root->val;
		inorder(root->right);
	}
}
int main()
{
	cin >> n;
	pre_order.resize(n);
	post_order.resize(n);
	for (int i = 0; i != n; ++i)
		cin >> pre_order[i];
	for (int i = 0; i != n; ++i)
		cin >> post_order[i];
	node *root = create(0, n - 1, 0, n - 1);
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	inorder(root);
	cout << endl; //一定要加换行符，不明白为什么，题目没要求要换行
}