#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
//resize只对新增出来的部分赋值，而原来空间的值不发生改变
class GasStation
{
private:
	int N;
	int M;
	int K;
	int Ds;
	vector<vector<int>> graph;
	vector<int> dist;
	vector<bool> collected;
	int final_location = 0;
	double min_distance = -1;
	double aver_distance = 10000;

	int find_min_distance_index();
	void dijsktra();
	void get_result(double, double, int);
public:
	void get_date();
	void compute();
	void output();
};
int GasStation::find_min_distance_index()
{
	int min = 10000;
	int min_index = -1;
	int sizeee = N + M + 1;
	for (int i = 1; i != sizeee; ++i)
	{
		if (dist[i] < min && collected[i] == false)
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}
void GasStation::get_date()
{
	scanf("%d%d%d%d", &N, &M, &K, &Ds);
	graph.resize(N + M + 1, vector<int>(N + M + 1, 10000));
	dist.resize(N + M + 1);
	collected.resize(N + M + 1);
	string s1, s2;
	int temp1, temp2;
	int distance;
	for (int i = 0; i != K; ++i)
	{
		cin >> s1 >> s2;
		scanf("%d", &distance);
		temp1 = s1.front() == 'G' ? stoi(s1.substr(1)) + N : stoi(s1);
		temp2 = s2.front() == 'G' ? stoi(s2.substr(1)) + N : stoi(s2);
		graph[temp1][temp2] = graph[temp2][temp1] = distance;
	}
}
void GasStation::compute()
{
	for (int i = N + 1; i != N + M + 1; ++i)
	{
		for (int t = 1; t != N + M + 1; ++t)
		{
			dist[t] = 10000;
			collected[t] = false;
		}
		dist[i] = 0;
		dijsktra();
		double min_dist_temp = 10000;
		double aver_dist_temp = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (dist[j] > Ds)
			{
				min_dist_temp = -1;
				break;
			}
			if (dist[j] < min_dist_temp)
				min_dist_temp = dist[j];
			aver_dist_temp += dist[j];
		}
		if (min_dist_temp == -1)
			continue;
		aver_dist_temp /= N;
		get_result(min_dist_temp, aver_dist_temp, i);
	}
}
void GasStation::get_result(double min_dist_temp, double aver_dist_temp, int gas)
{
	if (min_dist_temp > min_distance)
	{
		min_distance = min_dist_temp;
		aver_distance = aver_dist_temp;
		final_location = gas;
		return;
	}
	if (min_dist_temp == min_distance && aver_dist_temp < aver_distance)
	{
		aver_distance = aver_dist_temp;
		final_location = gas;
	}
}
void GasStation::dijsktra()
{
	int sizee = N + M + 1;
	while (1)
	{
		int min_index = find_min_distance_index();
		if (min_index == -1)
			break;
		collected[min_index] = true;
		for (int i = 1; i != sizee; ++i)
		{
			if (graph[min_index][i] != 10000 && collected[i] == false)
			{
				if (dist[min_index] + graph[min_index][i] < dist[i])
					dist[i] = dist[min_index] + graph[min_index][i];
			}
		}
	}
}
void GasStation::output()
{
	if (min_distance == -1)
		printf("No Solution");
	else
	{
		printf("G%d\n", final_location - N);
		printf("%.1lf %.1lf", min_distance, aver_distance);
	}
}
int main()
{
	GasStation gs;
	gs.get_date();
	gs.compute();
	gs.output();
}