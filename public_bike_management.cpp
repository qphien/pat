#include <iostream>
#include <vector>


using namespace std;
struct node_move_bike_count
{
	int take_to_station = 0;
	int take_back_to_pbmc = 0;
};
int shortest_dist(vector<vector<int>> graph, int N, const vector<bool> collected)
{
	int min_dist = 100000;
	int min_dist_index = 0;
	for (int i = 0; i != N; ++i)
	{
		if (!collected[i] && graph[0][i] < min_dist)
		{
			min_dist = graph[0][i];
			min_dist_index = i;
		}
	}
	return min_dist_index;
}
vector<int> find_shortest_path(vector<vector<int>> graph, const int Cmax, const int N, const int Sp, vector<int> all_station_bike_count, vector<int> &path)
{
	vector<bool> collected(N);
	vector<node_move_bike_count> move_count(N);
	collected[0] = true;
	int v;
	int take_to_station, take_back_to_pbmc;
	int half_number = Cmax / 2;
	int move_bike_count;
	int flag;
	while (1)
	{
		take_to_station = take_back_to_pbmc = 1000000;
		v = shortest_dist(graph, N, collected);
		if (!v || v == Sp)
			break;
		collected[v] = true;
		if (path[v] == -1)
		{
			if (all_station_bike_count[v] > half_number)
				move_count[v].take_back_to_pbmc = all_station_bike_count[v] - half_number;
			else
				move_count[v].take_to_station = half_number - all_station_bike_count[v];
		}
		for (int i = 0; i != N; ++i)
		{
			if (graph[v][i] != 100000 && graph[v][i] != 0)
			{
				if (!collected[i])
				{
					if (graph[0][i] >= graph[0][v] + graph[v][i])
					{
						if (graph[0][i] == graph[0][v] + graph[v][i])
						{
							if (all_station_bike_count[i] < half_number)
							{
								move_bike_count = half_number - all_station_bike_count[i];
								if (move_bike_count > move_count[v].take_back_to_pbmc)
								{
									take_to_station = move_bike_count - move_count[v].take_back_to_pbmc;
									flag = 0;
								}
								else
								{
									flag = 1;
								}
							}
							else
							{
								take_back_to_pbmc = all_station_bike_count[i] - half_number + move_count[v].take_back_to_pbmc;
							}
							if (take_to_station < move_count[i].take_to_station)
							{
								move_count[i].take_to_station = take_to_station;
								switch (flag)
								{
								case 0:
									move_count[v].take_back_to_pbmc = 0;
									break;
								case 1:
									move_count[v].take_back_to_pbmc -= move_bike_count;
									break;
								}
								path[i] = v;
							}
							else if (take_to_station == move_count[i].take_to_station)
							{
								if (take_back_to_pbmc < move_count[i].take_back_to_pbmc)
								{
									move_count[i].take_back_to_pbmc = take_back_to_pbmc;
									switch (flag)
									{
									case 0:
										move_count[v].take_back_to_pbmc = 0;
										break;
									case 1:
										move_count[v].take_back_to_pbmc -= move_bike_count;
										break;
									}
									path[i] = v;
								}
							}
						}
						else
						{
							if (all_station_bike_count[i] < half_number)
							{
								move_bike_count = half_number - all_station_bike_count[i];
								if (move_bike_count > move_count[v].take_back_to_pbmc)
								{
									move_count[i].take_to_station = move_bike_count - move_count[v].take_back_to_pbmc;
									move_count[v].take_back_to_pbmc = 0;
								}
								else
								{
									move_count[v].take_back_to_pbmc -= move_bike_count;
								}
							}
							else
							{
								move_count[i].take_back_to_pbmc = all_station_bike_count[i] - half_number + move_count[v].take_back_to_pbmc;
							}
							graph[0][i] = graph[i][0] = graph[0][v] + graph[v][i];
							path[i] = v;
						}
						
					}		
				}
			}

		}
	}
	return{ move_count[Sp].take_to_station, move_count[Sp].take_back_to_pbmc };
}
void output_path(const vector<int> path, int temp)
{
	if (path[temp] != -1)
	{
		output_path(path, path[temp]);
		cout << "->" << path[temp];
	}
}
int main()
{
	int Cmax, N, Sp, M;
	int i = 1;
	int temp, Xindex, Yindex;
	cin >> Cmax >> N >> Sp >> M;
	vector<int> all_station_bike_count;
	all_station_bike_count.push_back(0);
	for (; i != N + 1; ++i)
	{
		cin >> temp;
		all_station_bike_count.push_back(temp);
	}
	//const int N_const = N + 1;
	vector<vector<int>> graph(N + 1);
	vector<int> path(N + 1, -1);
	for (i = 0; i != N + 1; ++i)
	{
		graph[i] = vector<int>(N + 1);
		for (int j = 0; j != N + 1; ++j)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = 100000;
		}
	}
	for (i = 0; i != M; ++i)
	{
		cin >> Xindex >> Yindex >> temp;
		graph[Xindex][Yindex] = graph[Yindex][Xindex] = temp;
	}
	vector<int> move_count = find_shortest_path(graph, Cmax, N + 1, Sp, all_station_bike_count, path);
	cout << move_count.front() << ' ' << 0;
	output_path(path, Sp);
	cout << "->" << Sp << ' ' << move_count.back();
	system("pause");
	


}
