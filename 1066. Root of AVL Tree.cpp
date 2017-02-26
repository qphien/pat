#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int val;
	Node *left = 0;
	Node *right = 0;
	int height = 1;
};
int Height(Node *node)
{
	if (!node) return 0;
	return node->height;
}
Node* left_rotate(Node *T)
{
	Node *k = T->right;
	T->right = k->left;
	k->left = T;
	T->height = max(Height(T->left), Height(T->right)) + 1;
	k->height = max(Height(k->left), Height(k->right)) + 1;
	return k;
}
Node* right_rotate(Node *T)
{
	Node *k = T->left;
	T->left = k->right;
	k->right = T;
	T->height = max(Height(T->left), Height(T->right)) + 1;
	k->height = max(Height(k->left), Height(k->right)) + 1;
	return k;
}
Node* left_right_rotate(Node *T)
{
	T->left = left_rotate(T->left);
	return right_rotate(T);
}
Node* right_left_rotate(Node *T)
{
	T->right = right_rotate(T->right);
	return left_rotate(T);
}
Node* insert_node(Node *T, int val)
{
	if (!T)
	{
		T = new Node;
		T->val = val;
		return T;
	}
	if (val < T->val)
	{
		T->left = insert_node(T->left, val);
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (val < T->left->val)
				T = right_rotate(T);
			else
				T = left_right_rotate(T);
		}
	}
	else
	{
		T->right = insert_node(T->right, val);
		if (Height(T->right) - Height(T->left) == 2)
		{
			if (val > T->right->val)
				T = left_rotate(T);
			else
				T = right_left_rotate(T);
		}
	}
	T->height = max(Height(T->left), Height(T->right)) + 1;
	return T;
}
//void PreOrderTraversal(Node *T)
//{
//	if (T)
//	{
//		cout << T->val << ends;
//		PreOrderTraversal(T->left);
//		PreOrderTraversal(T->right);
//	}
//}
int main()
{
	int N;
	cin >> N;
	int temp;
	Node *root = 0;
	for (int i = 0; i != N; ++i)
	{
		cin >> temp;
		root = insert_node(root, temp);
		//PreOrderTraversal(root);
	}
	cout << root->val;
}