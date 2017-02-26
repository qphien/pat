#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class CountingLeaves
{
private:
	int N;
	int M;
	int root = 1;
	vector<vector<int>> pedigree;
	vector<int> child_number;
	vector<int> level_leaf_number;
	int level;
public:
	void get_data();
	void compute();
	void output();
};
void CountingLeaves::get_data()
{
	cin >> N >> M;
	pedigree.resize(N + 1, vector<int>());
	child_number.resize(N + 1, 0);
	level_leaf_number.resize(N + 1, 0);
	for (int i = 0; i != M; ++i)
	{
		int ID, number, child;
		cin >> ID >> number;
		child_number[ID] = number;
		for (int j = 0; j != number; ++j)
		{
			cin >> child;
			pedigree[ID].push_back(child);
		}
	}
}
void CountingLeaves::compute()
{
	level = 1;
	queue<int> que;
	que.push(root);
	int tail = root;
	while (true)
	{
		int index = que.front();
		que.pop();
		if (child_number[index] == 0)
			++level_leaf_number[level];
		for (int i = 0; i != child_number[index]; ++i)
		{
			que.push(pedigree[index][i]);
		}
		if (que.empty())
			break;
		if (index == tail)
		{
			++level;
			tail = que.back();
		}
	}
}
void CountingLeaves::output()
{
	for (int i = 0; i != level; ++i)
	{
		if (i == level - 1)
			cout << level_leaf_number[i + 1] << flush;
		else
			cout << level_leaf_number[i + 1] << ' ';
	}
}
int main()
{
	CountingLeaves cl;
	cl.get_data();
	cl.compute();
	cl.output();
}