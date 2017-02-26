#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class PathOfEqualWeight
{
private:
	int N;
	int M;
	int S;
	vector<vector<int>> graph;
	//vector<int> path;
	vector<int> weight;
	vector<bool> collected;
	vector<bool> is_leaf;
	vector<vector<int>> result;
	void dfs(int, int&, vector<int>&);
public:
	void get_data();
	void compute();
	void output();
};
void PathOfEqualWeight::get_data()
{
	cin >> N >> M >> S;
	//path.resize(N, -1);
	weight.resize(N);
	graph.resize(N, vector<int>(N, 0));
	collected.resize(N);
	is_leaf.resize(N, true);
	for (int i = 0; i != N; ++i)
		cin >> weight[i];
	for (int i = 0; i != M; ++i)
	{
		int parent, number;
		cin >> parent >> number;
		is_leaf[parent] = false;
		for (int j = 0; j != number; ++j)
		{
			int child;
			cin >> child;
			graph[parent][child] = graph[child][parent] = 1;
		}
	}
}
void PathOfEqualWeight::compute()
{
	int sum = 0;
	vector<int> temp_weight;
	int root = 0;
	dfs(root, sum, temp_weight);
	sort(result.begin(), result.end(), greater<vector<int>>());
}
void PathOfEqualWeight::output()
{
	int size1 = result.size();
	for (int i = 0; i != size1; ++i)
	{
		if (i == 0)
		{
			cout << result[i][0];
			for (int j = 1; j != result[i].size(); ++j)
				cout << ' ' << result[i][j];
		}
		else
		{
			cout << endl;
			cout << result[i][0];
			for (int j = 1; j != result[i].size(); ++j)
				cout << ' ' << result[i][j];
		}
	}
}
void PathOfEqualWeight::dfs(int root, int &sum, vector<int> &temp_weight)
{
	collected[root] = true;
	temp_weight.push_back(weight[root]);
	if ((sum += weight[root]) == S)
	{
		if (is_leaf[root])
			result.push_back(temp_weight);
	}
	for (int i = 0; i != N; ++i)
	{
		if (graph[root][i] && collected[i] == false)
		{
			dfs(i, sum, temp_weight);
		}
	}
	sum -= weight[root];
	temp_weight.pop_back();
}
int main()
{
	PathOfEqualWeight poew;
	poew.get_data();
	poew.compute();
	poew.output();
}