#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> bst;
int N;
int index = 0;
vector<int> input;
void Inorder(int root)
{
	if (root > N) return;
	Inorder(root * 2);
	bst[root] = input[index++];
	Inorder(root * 2 + 1);
}
int main()
{

	cin >> N;
	bst.resize(N + 1);
	input.resize(N);
	for (int i = 0; i != N; ++i)
		cin >> input[i];
	sort(input.begin(), input.end());
	int root = 1;
	Inorder(root);
	cout << bst[1];
	for (int i = 2; i != N + 1; ++i)
		cout << ' ' << bst[i];

}