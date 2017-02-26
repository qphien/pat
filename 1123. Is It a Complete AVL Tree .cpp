#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
	int val;
	int height;
	node *left;
	node *right;
};
int Height(node *root)
{
	if (root == NULL)
		return -1;
	return root->height;
}
node* right_rotate(node *root)
{
	node *ans = root->left;
	root->left = ans->right;
	ans->right = root;
	root->height = max(Height(root->left), Height(root->right)) + 1;
	ans->height = max(Height(ans->left), Height(ans->right)) + 1;
	return ans;
}
node* left_rotate(node *root)
{
	node *ans = root->right;
	root->right = ans->left;
	ans->left = root;
	root->height = max(Height(root->left), Height(root->right)) + 1;
	ans->height = max(Height(ans->left), Height(ans->right)) + 1;
	return ans;
}
node* left_right_rotate(node *root)
{
	root->left = left_rotate(root->left);
	return right_rotate(root);
}
node* right_left_rotate(node *root)
{
	root->right = right_rotate(root->right);
	return left_rotate(root);
}
node* insert_node(int val, node *root)
{
	if (root == NULL)
	{
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->val = val;
	}
	else
	{
		if (val < root->val)
		{
			root->left = insert_node(val, root->left);
			if (Height(root->left) - Height(root->right) == 2)
			{
				if (val < root->left->val)
					root = right_rotate(root);
				else
					root = left_right_rotate(root);
			}
		}
		else
		{
			root->right = insert_node(val, root->right);
			if (Height(root->right) - Height(root->left) == 2)
			{
				if (val > root->right->val)
					root = left_rotate(root);
				else
					root = right_left_rotate(root);
			}
		}
	}
	root->height = max(Height(root->left), Height(root->right)) + 1;
	return root;
}
void level_traversal(node *root)
{
	queue<node*> q;
	q.push(root);
	int number = 0;
	while (!q.empty())
	{
		if (++number > 1)
			cout << ' ';
		root = q.front();
		q.pop();
		cout << root->val;
		if (root->left) q.push(root->left);
		if (root->right) q.push(root->right);
	}
}
int max_number = -1;
void dfs(node *root, int number)
{
	if (root)
	{
		max_number = max(max_number, number);
		dfs(root->left, number * 2);
		dfs(root->right, number * 2 + 1);
	}
}
int main()
{
	int n;
	cin >> n;
	node *root = 0;
	for (int i = 0; i != n; ++i)
	{
		int val;
		cin >> val;
		root = insert_node(val, root);
	}
	level_traversal(root);
	cout << endl;
	dfs(root, 1);
	if (max_number != n)
		cout << "NO";
	else
		cout << "YES";
}