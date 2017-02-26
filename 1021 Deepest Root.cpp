#include <iostream>
#include <vector>
using namespace std;

class DeepestRoot
{
private:
	int N;
	vector<vector<int>> graph;             //使用邻接矩阵会内存溢出，故使用邻接表
	int K = 0;
	vector<bool> collected;
	vector<int> result;
	int LargestDepth;
	int LargestDepth_temp;
	int result_depth = 0;
public:
	void get_data();
	void compute();
	void output();
	void dfs(int);
	void dfs2(int);
};
void DeepestRoot::get_data()
{
	cin >> N;
	collected.resize(N + 1, false);
	graph.resize(N + 1);
	for (int i = 0; i != N - 1; ++i)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}
}
void DeepestRoot::compute()
{
	for (int i = 1; i != N + 1; ++i)
	{
		if (collected[i] == false)
		{
			++K;
			dfs(i);
		}
	}
	if (K == 1)
	{
		for (int i = 1; i != N + 1; ++i)
		{
			LargestDepth = 0;
			LargestDepth_temp = 0;
			collected.assign(N + 1, false);
			dfs2(i);
			if (LargestDepth > result_depth)
			{
				result_depth = LargestDepth;
				result.clear();
				result.push_back(i);
			}
			else if (LargestDepth == result_depth)
				result.push_back(i);
		}
	}
}
void DeepestRoot::dfs2(int i)
{
	collected[i] = true;
	++LargestDepth_temp;
	if (LargestDepth_temp > LargestDepth)
		LargestDepth = LargestDepth_temp;
	for (int j = 0; j != graph[i].size(); ++j)
	{
		if (collected[graph[i][j]] == false)
			dfs2(graph[i][j]);
	}
	--LargestDepth_temp;
}
void DeepestRoot::dfs(int i)
{
	collected[i] = true;
	for (int j = 0; j != graph[i].size(); ++j)
	{
		if (collected[graph[i][j]] == false)
			dfs(graph[i][j]);
	}
}
void DeepestRoot::output()
{
	if (K == 1)
	{
		for (int i = 0; i != result.size(); ++i)
			cout << result[i] << endl;
	}
	else
		cout << "Error: " << K << " components";
}
int main()
{
	DeepestRoot dr;
	dr.get_data();
	dr.compute();
	dr.output();
}