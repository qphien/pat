#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
	node *x = root;
	node *y = 0;
	bool comp;
	while (x)
	{
		y = x;
		comp = x->data > data ? true : false;
		x = comp ? x->left : x->right;
	}
	x = new node;
	x->data = data;
	x->left = x->right = 0;
	if (comp)
		y->left = x;
	else
		y->right = x;
}
void LevelTraversal(node *root, int N)
{
	queue<node*> que;
	if (root == 0)
		return;
	que.push(root);
	int number = 0;
	while (!que.empty())
	{
		node *temp = que.front();
		que.pop();
		++number;
		cout << temp->data;
		if (number < N)
			cout << ' ';
		if (temp->left)
			que.push(temp->left);
		if (temp->right)
			que.push(temp->right);

	}
}
node* compute(vector<int>::iterator first1, vector<int>::iterator last1,
	vector<int>::iterator first2, vector<int>::iterator last2)
{
	if (!(last1 > first1))
		return 0;
	node *root = new node;
	int temp = *(last1 - 1);
	root->data = temp;
	//root->left = root->right = 0;
	vector<int>::iterator iter = find(first2, last2, temp);
	root->left = compute(first1, first1 + (iter - first2), first2, iter); //left tree
	root->right = compute(first1 + (iter - first2), last1 - 1, iter + 1, last2);
	return root;
}
int main()
{
	int N;
	cin >> N;
	vector<int> PostOrder(N), InOrder(N);
	for (int i = 0; i != N; ++i)
		cin >> PostOrder[i];
	for (int i = 0; i != N; ++i)
		cin >> InOrder[i];
	node *root = compute(PostOrder.begin(), PostOrder.end(), InOrder.begin(), InOrder.end());
	LevelTraversal(root, N);
}