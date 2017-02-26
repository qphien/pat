#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
vector<int> ans;
struct node
{
	int val;
	node *right;
	node *left;
};

node* insert_node(node *root, int val)
{
	if (!root)
	{
		root = new node;
		root->left = root->right = 0;
		root->val = val;
		return root;
	}
	if (val <= root->val)
		root->left = insert_node(root->left, val);
	else
		root->right = insert_node(root->right, val);
	return root;
}
void level_traversal(node *root)
{
	queue<node*> q;
	q.push(root);
	int sum = 1;
	ans.push_back(sum);
	node *last = root;
	node *level_last = root;
	while (!q.empty())
	{
		node *temp = q.front();
		q.pop();
		if (temp->left)
		{
			q.push(temp->left);
			level_last = temp->left;
			++sum;
		}
		if (temp->right)
		{
			q.push(temp->right);
			level_last = temp->right;
			++sum;
		}
		if (temp == last)
		{
			last = level_last;
			ans.push_back(sum);
		}
	}
	ans.pop_back();
	int n1 = ans.back() - *(ans.end() - 2);
	int n2 = *(ans.end() - 2) - *(ans.end() - 3);
	sum = n1 + n2;
	printf("%d + %d = %d\n", n1, n2, sum);
}
int main()
{
	int n;
	scanf("%d", &n);
	node *root = 0;
	for (int i = 0; i != n; ++i)
	{
		int val;
		scanf("%d", &val);
		root = insert_node(root, val);
	}
	if (n == 1)       //special condition
		printf("1 + 0 = 1\n");
	else
		level_traversal(root);
}