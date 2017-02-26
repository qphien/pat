#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node
{
	int data;
	node *left, *right;
};

void insert_node(node *&root, int data)
{
	if (!root)
	{
		root = new node;
		root->data = data;
		root->left = root->right = 0;
		return;
	}
	bool flag;
	node *x = root;
	node *y = 0;
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = 0;
	while (x)
	{
		y = x;
		flag = data < x->data ? true : false;
		x = flag ? x->left : x->right;
	}
	if (flag)
		y->left = temp;
	else
		y->right = temp;
}
bool is_bst(node *root, const vector<int> &v)
{
	stack<node*> que;
	node *t = root;
	int i = 0;
	while (!que.empty() || t)
	{
		while (t)
		{
			que.push(t);
			//t = que.front();
			if (t->data != v[i])
				return false;
			t = t->left;
			++i;
		}
		if (!que.empty())
		{
			t = que.top();
			que.pop();
			t = t->right;
		}
	}
	return true;
}
bool is_mirror(node *root, vector<int> &v)
{
	stack<node*> que;
	node *t = root;
	int i = v.size();
	node *temp = 0;
	while (!que.empty() || t)
	{
		while (t)
		{
			que.push(t);
			t = t->left;
		}
		if (!que.empty())
		{
			t = que.top();
			que.pop();
			if (t->right == 0 || temp == t->right)
			{
				temp = t;
				if (v[i - 1] != t->data)
					return false;
				t = 0;
				--i;
			}
			else
			{
				que.push(t);
				t = t->right;
			}
		}
	}
	return true;
}
void BST_PostOrderTraversal(node *root, vector<int> &v)
{
	if (root)
	{
		BST_PostOrderTraversal(root->left, v);
		BST_PostOrderTraversal(root->right, v);
		v.push_back(root->data);
	}
}
void BSTOutput(node *root)
{
	vector<int> v;
	BST_PostOrderTraversal(root, v);
	cout << v[0];
	for (int i = 1; i != v.size(); ++i)
		cout << ' ' << v[i];
}
void  Mirror_PostOrderTraversal(node *root, vector<int> &v)
{
	if (root)
	{
		v.push_back(root->data);
		Mirror_PostOrderTraversal(root->left, v);
		Mirror_PostOrderTraversal(root->right, v);
	}
}
void MirrorOutput(node *root)
{
	vector<int> v;
	Mirror_PostOrderTraversal(root, v);
	cout << v[v.size() - 1];
	for (int i = v.size() - 2; i >= 0; --i)
		cout << ' ' << v[i];
}
int main()
{
	int N;
	cin >> N;
	vector<int> v(N);
	node *root = 0;
	for (int i = 0; i != N; ++i)
	{
		cin >> v[i];
		insert_node(root, v[i]);
	}
	if (is_bst(root, v))
	{
		cout << "YES" << endl;
		BSTOutput(root);
		return 0;
	}
	if (is_mirror(root, v))
	{
		cout << "YES" << endl;
		MirrorOutput(root);
		return 0;
	}
	cout << "NO";
}