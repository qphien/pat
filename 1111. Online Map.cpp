#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
const int inf = 10000;

struct node
{
	node() : time(inf), length(inf) {}
	node(int i, int j) : time(i), length(j) {}
	int time = inf;
	int length = inf;
};
vector<vector<node>> graph;
vector<bool> collected;
vector<int> shortest_path;
vector<vector<int>> fastest_path;
vector<int> dist;
vector<int> cost_time;
int n, m;
int find_min_dist_index()
{
	int min_dist = inf;
	int min_index = -1;
	for (int i = 0; i != n; ++i)
	{
		if (dist[i] < min_dist && !collected[i])
		{
			min_dist = dist[i];
			min_index = i;
		}
	}
	return min_index;
}
int find_min_time_index()
{
	int min_time = inf;
	int min_index = -1;
	for (int i = 0; i != n; ++i)
	{
		if (cost_time[i] < min_time && !collected[i])
		{
			min_time = cost_time[i];
			min_index = i;
		}
	}
	return min_index;
}
void dijsktra_dist(int src)
{
	dist[src] = 0;
	cost_time[src] = 0;
	while (1)
	{
		int i = find_min_dist_index();
		if (i == -1)
			break;
		collected[i] = true;
		for (int j = 0; j != n; ++j)
		{
			if (graph[i][j].length != inf && !collected[j])
			{
				if (dist[i] + graph[i][j].length < dist[j])
				{
					dist[j] = dist[i] + graph[i][j].length;
					cost_time[j] = cost_time[i] + graph[i][j].time;
					shortest_path[j] = i;
				}
				else if (dist[i] + graph[i][j].length == dist[j])
				{
					if (cost_time[i] + graph[i][j].time < cost_time[j])
					{
						shortest_path[j] = i;
						cost_time[j] = cost_time[i] + graph[i][j].time;
					}
				}
			}
		}
	}
}
void dijsktra_time(int src)
{
	cost_time[src] = 0;
	while (1)
	{
		int i = find_min_time_index();
		if (i == -1)
			break;
		collected[i] = true;
		for (int j = 0; j != n; ++j)
		{
			if (graph[i][j].time != inf && !collected[j])
			{
				if (cost_time[i] + graph[i][j].time < cost_time[j])
				{
					cost_time[j] = cost_time[i] + graph[i][j].time;
					fastest_path[j].clear();   //±ðÍü¼ÇÇåÁã
					fastest_path[j].push_back(i);
				}
				else if (cost_time[i] + graph[i][j].time == cost_time[j])
					fastest_path[j].push_back(i);
			}
		}
	}
}
vector<int> fastest_ans(600);
vector<int> fastest_temp;
void dfs(int src, int dst)
{
	if (dst == src)
	{
		fastest_temp.push_back(dst);
		if (fastest_temp.size() < fastest_ans.size())
			fastest_ans = fastest_temp;
		fastest_temp.pop_back();
		return;
	}
	fastest_temp.push_back(dst);
	for (int i = 0; i != fastest_path[dst].size(); ++i)
		dfs(src, fastest_path[dst][i]);
	fastest_temp.pop_back();
}
vector<int> shortest_ans;
void get_shortest_path(int src, int dst)
{
	shortest_ans.push_back(dst);
	if (dst == src)
		return;
	get_shortest_path(src, shortest_path[dst]);
}
int main()
{
	scanf("%d %d", &n, &m);

	graph.resize(n, vector<node>(n));
	dist.resize(n, inf);
	collected.resize(n);
	shortest_path.resize(n);
	fastest_path.resize(n);
	cost_time.resize(n, inf);
	for (int i = 0; i != m; ++i)
	{
		int v1, v2, one_way, length, time;
		scanf("%d %d %d %d %d", &v1, &v2, &one_way, &length, &time);
		node n(time, length);
		if (one_way)
			graph[v1][v2] = n;
		else
			graph[v1][v2] = graph[v2][v1] = n;
	}
	int src, dst;
	scanf("%d %d", &src, &dst);
	dijsktra_dist(src);
	get_shortest_path(src, dst);
	for (int i = 0; i != n; ++i)
	{
		collected[i] = false;
		cost_time[i] = inf;
	}
	dijsktra_time(src);
	dfs(src, dst);
	if (shortest_ans != fastest_ans)
	{
		int distance = dist[dst];
		printf("Distance = %d: ", distance);
		for (int i = shortest_ans.size() - 1; i >= 0; --i)
		{
			if (i != shortest_ans.size() - 1)
				printf(" -> ");
			printf("%d", shortest_ans[i]);
		}
		printf("\n");
		int time = cost_time[dst];
		printf("Time = %d: ", time);
		for (int i = fastest_ans.size() - 1; i >= 0; --i)
		{
			if (i != fastest_ans.size() - 1)
				printf(" -> ");
			printf("%d", fastest_ans[i]);
		}
		printf("\n");
	}
	else
	{
		int distance = dist[dst];
		printf("Distance = %d; ", distance);
		int time = cost_time[dst];
		printf("Time = %d: ", time);
		for (int i = fastest_ans.size() - 1; i >= 0; --i)
		{
			if (i != fastest_ans.size() - 1)
				printf(" -> ");
			printf("%d", fastest_ans[i]);
		}
		printf("\n");
	}
}