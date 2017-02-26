#include <iostream>
#include <vector>
using namespace std;

class PublicBikeManagement
{
public:
	int Cmax;
	int N;
	int Sp;
	int M;
	int inf = (1 << 31) - 1;
	vector<int> collected;
	vector<int> station_bike_weight;
	vector<int> path;
	vector<int> temp_path;
	vector<vector<int>> pre;
	vector<vector<int>> graph;
	int MinSend = inf;
	int MinTakeBack = inf;
public:
	void get_data();
	void compute();
	int find_min_dist();
	void dfs(int);
	void output();
};

int PublicBikeManagement::find_min_dist()
{
	int index = 0;
	for (int i = 1; i != N + 1; ++i)
	{
		if (graph[0][i] < graph[0][index] && collected[i] == false)
			index = i;
	}
	return index;
}
void PublicBikeManagement::dfs(int v)
{
	temp_path.push_back(v);
	if (v == 0)
	{
		int send = 0, take_back = 0;
		for (int i = temp_path.size() - 1; i >= 0; --i)
		{
			int id = temp_path[i];
			if (station_bike_weight[id] >= 0)
				take_back += station_bike_weight[id];
			else
			{
				if (take_back > abs(station_bike_weight[id]))
					take_back -= abs(station_bike_weight[id]);
				else
				{
					send += abs(station_bike_weight[id]) - take_back;
					take_back = 0;
				}
			}
		}
		if (send < MinSend)
		{
			MinSend = send;
			MinTakeBack = take_back;
			path = temp_path;
		}
		else if (send == MinSend && take_back < MinTakeBack)
		{
			MinTakeBack = take_back;
			path = temp_path;
		}
		temp_path.pop_back();
		return;
	}
	for (int i = 0; i != pre[v].size(); ++i)
		dfs(pre[v][i]);
	temp_path.pop_back();
}
void PublicBikeManagement::output()
{
	cout << MinSend << ' ';
	cout << path[path.size() - 1];
	for (int i = path.size() - 2; i >= 0; --i)
		cout << "->" << path[i];
	cout << ' ' << MinTakeBack;
}
void PublicBikeManagement::get_data()
{
	cin >> Cmax >> N >> Sp >> M;
	graph.resize(N + 1, vector<int>(N + 1, inf));
	collected.resize(N + 1, false);
	collected[0] = true;
	station_bike_weight.push_back(0);
	pre.resize(N + 1, vector<int>());
	for (int i = 1; i != N + 1; ++i)
	{
		int temp;
		cin >> temp;
		station_bike_weight.push_back(temp - Cmax / 2);
	}
	for (int i = 0; i != M; ++i)
	{
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;
		graph[temp1][temp2] = graph[temp2][temp1] = temp3;
		if (temp1 == 0)
			pre[temp2].push_back(0);
		if (temp2 == 0)
			pre[temp1].push_back(0);
	}
}
void PublicBikeManagement::compute()
{
	while (true)
	{
		int index = find_min_dist();
		if (index == 0)
			break;
		collected[index] = true;
		for (int i = 0; i != N + 1; ++i)
		{
			if (graph[index][i] < inf && collected[i] == false)
			{
				if (graph[0][index] + graph[index][i] < graph[0][i])
				{
					graph[0][i] = graph[0][index] + graph[index][i];
					pre[i].clear();
					pre[i].push_back(index);
				}
				else if (graph[0][i] == graph[0][index] + graph[index][i])
					pre[i].push_back(index);
			}
		}
	}
	dfs(Sp);
}
int main()
{
	PublicBikeManagement pbm;
	pbm.get_data();
	pbm.compute();
	pbm.output();
}