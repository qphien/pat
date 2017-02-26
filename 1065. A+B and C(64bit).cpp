#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node *left = NULL;
	Node *right = NULL;
	int height;
};
int height(Node *node)
{
	if (node == NULL)
		return -1;
	return node->height;
}
Node* right_rotate(Node *root)
{
	Node *ans = root->left;
	root->left = ans->right;
	ans->right = root;
	ans->left->height = max(height(ans->left->left), height(ans->left->right)) + 1;
	ans->right->height = max(height(ans->right->left), height(ans->right->right)) + 1;
	return ans;
}
Node* left_rotate(Node *root)
{
	Node *ans = root->right;
	root->right = ans->left;
	ans->left = root;
	ans->left->height = max(height(ans->left->left), height(ans->left->right)) + 1;
	ans->right->height = max(height(ans->right->left), height(ans->right->right)) + 1;
	return ans;
}
Node *left_right_rotate(Node *root)
{
	root->left = left_rotate(root->left);
	return right_rotate(root);
}
Node* right_left_rotate(Node *root)
{
	root->right = right_rotate(root->right);
	return left_rotate(root);
}
Node* insert_node(Node *root, int val)
{
	if (!root)
	{
		root = new Node;
		root->val = val;
	}
	else
	{
		if (val < root->val)
		{
			root->left = insert_node(root->left, val);
			if (height(root->left) - height(root->right) == 2)
			{
				if (val < root->left->val)
					root = right_rotate(root);
				else
					root = left_right_rotate(root);
			}
		}
		else if (val > root->right)
		{
			root->right = insert_node(root->right, val);
			if (height(root->right) - height(root->left) == 2)
			{
				if (val > root->right->val)
					root = left_rotate(root);
				else
					root = right_left_rotate(root);
			}
		}
	}
	root->height = max(root->left, root->right) + 1;
	return root;
}

int main()
{
	int N;
	cin >> N;
	Node *root = NULL;
	for (int i = 0; i != N; ++i)
	{
		int temp;
		cin >> temp;
		root = insert_node(root, temp);
	}
	cout << root->val;
}