#include <iostream>
#include <vector>
using namespace std;
int inf = (1 << 31) - 1;
struct Line
{
	int distance;
	int cost;
};
class TravelPlan
{
private:
	int N;
	int M;
	int S;
	int D;
	vector<vector<Line>> graph;
	vector<int> dist;
	vector<int> path;
	vector<int> total_cost;
	vector<bool> collected;
	int find_min_index();
	void output_shortest_path(int);
public:
	void get_data();
	void compute();
	void output();
};
int TravelPlan::find_min_index()
{
	int index = -1, min_dist = inf;
	for (int i = 0; i != N; ++i)
	{
		if (dist[i] < min_dist && collected[i] == false)
		{
			index = i;
			min_dist = dist[i];
		}
	}
	return index;
}
void TravelPlan::get_data()
{
	cin >> N >> M >> S >> D;
	graph.resize(N, vector<Line>(N, { inf, inf }));
	dist.resize(N, inf);
	dist[S] = 0;
	path.resize(N, -1);
	total_cost.resize(N, inf);
	total_cost[S] = 0;
	collected.resize(N, false);
	for (int i = 0; i != M; ++i)
	{
		int temp1, temp2, distance, cost;
		cin >> temp1 >> temp2 >> distance >> cost;
		graph[temp1][temp2] = graph[temp2][temp1] = { distance, cost };
	}
}
void TravelPlan::compute()
{
	while (true)
	{
		int min_dist_index = find_min_index();
		if (min_dist_index == -1)
			break;
		collected[min_dist_index] = true;
		for (int i = 0; i != N; ++i)
		{
			if (graph[min_dist_index][i].distance != inf && collected[i] == false)
			{
				if (dist[min_dist_index] + graph[min_dist_index][i].distance <= dist[i])
				{
					if (dist[min_dist_index] + graph[min_dist_index][i].distance == dist[i])
					{
						if (total_cost[min_dist_index] + graph[min_dist_index][i].cost < total_cost[i])
						{
							total_cost[i] = total_cost[min_dist_index] + graph[min_dist_index][i].cost;
							path[i] = min_dist_index;
						}
					}
					else
					{
						dist[i] = dist[min_dist_index] + graph[min_dist_index][i].distance;
						total_cost[i] = total_cost[min_dist_index] + graph[min_dist_index][i].cost;
						path[i] = min_dist_index;
					}
				}
			}
		}
	}
}
void TravelPlan::output_shortest_path(int i)
{
	if (i == S)
	{
		cout << i << ' ';
		return;
	}
	output_shortest_path(path[i]);
	cout << i << ' ';
}
void TravelPlan::output()
{
	output_shortest_path(D);
	cout << dist[D] << ' ' << total_cost[D] << flush;
}
int main()
{
	TravelPlan tp;
	tp.get_data();
	tp.compute();
	tp.output();
}