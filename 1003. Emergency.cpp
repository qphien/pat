#include <iostream>
#include <vector>
using namespace std;
class Emergency
{
private:
	int N;
	int M;
	int C1;
	int C2;
	vector<int> CityTeamNumber;
	vector<vector<int>> Road;
	vector<bool> collected;
	//vector<int> dist;
	vector<int> path_number;
	vector<int> GatherTeamNumber;
	//int count = 1;
public:
	void get_data();
	void compute();
	int FindNearest();
	void output();
};
void Emergency::output()
{
	cout << path_number[C2] << ' ' << GatherTeamNumber[C2] << flush;
}
void Emergency::get_data()
{
	cin >> N >> M >> C1 >> C2;
	CityTeamNumber.resize(N);
	path_number.resize(N, 0);
	path_number[C1] = 1;
	Road.resize(N, vector<int>(N, 100000));
	collected.resize(N, false);
	collected[C1] = true;
	//dist.resize(N, 10000);
	//dist[C1] = 0;
	GatherTeamNumber.resize(N, 0);
	for (int i = 0; i != N; ++i)
		cin >> CityTeamNumber[i];
	GatherTeamNumber[C1] = CityTeamNumber[C1];
	for (int i = 0; i != M; ++i)
	{
		int city1, city2, length;
		cin >> city1 >> city2 >> length;
		Road[city1][city2] = Road[city2][city1] = length;
	/*	if (city1 == C1)
		{
			GatherTeamNumber[city2] = CityTeamNumber[city1] + CityTeamNumber[city2];
			path_number[city2] = 1;
		}
		if (city2 == C1)
		{
			GatherTeamNumber[city1] = CityTeamNumber[city1] + CityTeamNumber[city2];
			path_number[city1] = 1;
		}*/
	}

}
int Emergency::FindNearest()
{
	int index = C1;
	for (int i = 0; i != N; ++i)
	{
		if (Road[C1][i] < Road[C1][index] && !collected[i])
			index = i;
	}
	return index;
}
void Emergency::compute()
{
	while (1)
	{
		int nearest_index = FindNearest();
		if (nearest_index == C1)
			break;
		collected[nearest_index] = true;
		for (int i = 0; i != N; ++i)
		{
			if (Road[nearest_index][i] != 100000 && !collected[i])
			{
				if (Road[C1][nearest_index] + Road[nearest_index][i] < Road[C1][i])
				{
					Road[C1][i] = Road[i][C1] = Road[C1][nearest_index] + Road[nearest_index][i];
					GatherTeamNumber[i] = GatherTeamNumber[nearest_index] + CityTeamNumber[i];
					path_number[i] = path_number[nearest_index];
				}
				else if (Road[C1][nearest_index] + Road[nearest_index][i] == Road[C1][i])
				{
					path_number[i] += path_number[nearest_index];
					if (GatherTeamNumber[i] < GatherTeamNumber[nearest_index] + CityTeamNumber[i])
						GatherTeamNumber[i] = GatherTeamNumber[nearest_index] + CityTeamNumber[i];
					//if (i == C2)
					//++count;     //为什么不能用count这么做？
				}
			}
		}
	}
}
int main()
{
	Emergency eg;
	eg.get_data();
	eg.compute();
	eg.output();
}



