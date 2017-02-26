#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<bool> collected;
vector<vector<int>> path;
vector<int> happiness;
vector<int> cost;
vector<vector<int>> graph;
int n, k;
const int inf = 100000;
int find_min_cost_index()
{
	int index = -1;
	int min_cost = inf;
	for (int i = 0; i != n; ++i)
	{
		if (cost[i] < min_cost && !collected[i])
		{
			min_cost = cost[i];
			index = i;
		}
	}
	return index;
}
void dijsktra(int src)
{
	cost[src] = 0;
	for (;;)
	{
		int min_cost_index = find_min_cost_index();
		if (min_cost_index == -1)
			break;
		collected[min_cost_index] = true;
		for (int i = 0; i != n; ++i)
		{
			if (graph[min_cost_index][i] != inf && !collected[i])
			{
				if (cost[min_cost_index] + graph[min_cost_index][i] < cost[i])
				{
					cost[i] = cost[min_cost_index] + graph[min_cost_index][i];
					path[i].clear();
					path[i].push_back(min_cost_index);
				}
				else if (cost[min_cost_index] + graph[min_cost_index][i] == cost[i])
					path[i].push_back(min_cost_index);
			}
		}
	}

}
vector<int> ans_path;
vector<int> temp_path;
int ans_happiness;
double aver_happiness;
int ans_number = 0;
void dfs(int dst, int src, int fun)
{
	temp_path.push_back(dst);
	if (dst == src)
	{
		++ans_number;
		if (fun > ans_happiness)
		{
			ans_happiness = fun;
			ans_path = temp_path;
			aver_happiness = (double)ans_happiness / (ans_path.size() - 1);
		}
		else if (fun == ans_happiness && (double)fun / (temp_path.size() - 1) > aver_happiness)
		{
			ans_path = temp_path;
			aver_happiness = (double)fun / (temp_path.size() - 1);
		}
		temp_path.pop_back();
		return;
	}
	for (int i = 0; i != path[dst].size(); ++i)
		dfs(path[dst][i], src, fun + happiness[path[dst][i]]);
	temp_path.pop_back();
}
int main()
{
	scanf("%d %d", &n, &k);
	string src;
	cin >> src;
	string dst = "ROM";
	map<string, int> m;
	vector<string> m2(n);
	m[src] = 0;
	m2[0] = src;
	int number = 0;
	collected.resize(n);
	path.resize(n);
	happiness.resize(n);
	cost.resize(n, inf);
	graph.resize(n, vector<int>(n, inf));
	string city, city2;
	int val;
	happiness[0] = 0;
	for (int i = 0; i != n - 1; ++i)
	{
		cin >> city >> val;
		m[city] = ++number;
		m2[number] = city;
		happiness[number] = val;
	}
	for (int i = 0; i != k; ++i)
	{
		cin >> city >> city2 >> val;
		graph[m[city]][m[city2]] = graph[m[city2]][m[city]] = val;
	}
	dijsktra(m[src]);
	dfs(m[dst], m[src], happiness[m[dst]]);
	cout << ans_number << ' ' << cost[m[dst]] << ' ' << ans_happiness <<
		' ' << floor(aver_happiness) << endl;
	for (int i = ans_path.size() - 1; i >= 0; --i)
	{
		if (i != ans_path.size() - 1)
			cout << "->";
		cout << m2[ans_path[i]];
	}
	cout << endl;
}