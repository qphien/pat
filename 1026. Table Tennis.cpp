#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

struct Player
{
	int arrival_time;
	int start_time;
	int train_time;
	int is_vip;
};
struct Table
{
	int end_time = 8 * 3600;
	int serve_count = 0;
	int is_vip = 0;
};
bool cmp1(Player a, Player b)
{
	return a.arrival_time < b.arrival_time;
}
bool cmp2(Player a, Player b)
{
	return a.start_time < b.start_time;
}
class TableTennis
{
private:
	int N;
	int K;
	int M;
	vector<Player> vecPlayer;
	vector<Table> vecTable;
	int convert_time(int, int, int);
	int find_next_vip_player(int);
	void allocate_table(int, int);
public:
	void get_data();
	void compute();
	void output();
};
void TableTennis::allocate_table(int table_index, int player_index)
{
	if (vecPlayer[player_index].arrival_time > vecTable[table_index].end_time)
		vecPlayer[player_index].start_time = vecPlayer[player_index].arrival_time;
	else
		vecPlayer[player_index].start_time = vecTable[table_index].end_time;
	vecTable[table_index].end_time = vecPlayer[player_index].start_time + vecPlayer[player_index].train_time;
	++vecTable[table_index].serve_count;
}
int TableTennis::find_next_vip_player(int i)
{
	++i;
	while (i < vecPlayer.size() && vecPlayer[i].is_vip != 1)
		++i;
	return i;
}
int TableTennis::convert_time(int hour, int min, int sec)
{
	return hour * 3600 + min * 60 + sec;
}
void TableTennis::get_data()
{
	cin >> N;
	for (int i = 0; i != N; ++i)
	{
		int hour, min, sec;
		int train_time, is_vip;
		scanf("%02d:%02d:%02d", &hour, &min, &sec);
		int arrival_time = convert_time(hour, min, sec);
		cin >> train_time >> is_vip;
		if (arrival_time >= 21 * 3600) continue;
		train_time = train_time > 120 ? 7200 : train_time * 60;
		vecPlayer.push_back({ arrival_time, 21 * 3600, train_time, is_vip });
	}
	cin >> K >> M;
	vecTable.resize(K + 1);
	for (int i = 0; i != M; ++i)
	{
		int temp;
		cin >> temp;
		vecTable[temp].is_vip = 1;
	}
}
void TableTennis::compute()
{
	sort(vecPlayer.begin(), vecPlayer.end(), cmp1);
	int i = 0;
	int next_vip_player = find_next_vip_player(-1);
	while (i < vecPlayer.size())
	{
		if (vecPlayer[i].is_vip == 1 && i < next_vip_player)
		{
			++i;
			continue;
		}
		int idTable = 1;
		for (int j = 2; j != K + 1; ++j)
		{
			if (vecTable[j].end_time < vecTable[idTable].end_time)
				idTable = j;
		}
		if (vecTable[idTable].end_time >= 21 * 3600)
			break;
		if (vecTable[idTable].is_vip == 1)
		{
			if (vecPlayer[i].is_vip == 1)       //vip table, vip player
			{
				allocate_table(idTable, i);
				++i;
				next_vip_player = find_next_vip_player(next_vip_player);
			}
			else                 // vip table, ordinary person
			{
				if (next_vip_player < vecPlayer.size() && vecPlayer[next_vip_player].arrival_time <= vecTable[idTable].end_time)
				{
					allocate_table(idTable, next_vip_player);
					next_vip_player = find_next_vip_player(next_vip_player);
				}
				else
				{
					allocate_table(idTable, i);
					++i;
				}
			}
		}
		else
		{
			if (vecPlayer[i].is_vip == 0)              //ordinary table, ordinary player
			{
				allocate_table(idTable, i);
				++i;
			}
			else										//ordinary table, vip player
			{
				int min_vip_table_end_time = (1 << 31) - 1;
				int min_vip_table_index = -1;
				for (int t = 1; t != K + 1; ++t)
				{
					if (vecTable[t].is_vip == 1 && vecTable[t].end_time < min_vip_table_end_time)
					{
						min_vip_table_end_time = vecTable[t].end_time;
						min_vip_table_index = t;
					}
				}
				if (min_vip_table_index != -1 && vecPlayer[i].arrival_time >= vecTable[min_vip_table_index].end_time)
				{
					allocate_table(min_vip_table_index, i);
					++i;
					next_vip_player = find_next_vip_player(next_vip_player);
				}
				else
				{
					allocate_table(idTable, i);
					++i;
					next_vip_player = find_next_vip_player(next_vip_player);
				}
			}

		}
	}
}
void TableTennis::output()
{
	sort(vecPlayer.begin(), vecPlayer.end(), cmp2);
	for (int i = 0; i != vecPlayer.size(); ++i)
	{
		if (vecPlayer[i].start_time < 21 * 3600)
		{
			int arrival_time = vecPlayer[i].arrival_time;
			int start_time = vecPlayer[i].start_time;
			printf("%02d:%02d:%02d ", arrival_time / 3600, arrival_time % 3600 / 60, arrival_time % 60);
			printf("%02d:%02d:%02d ", start_time / 3600, start_time % 3600 / 60, start_time % 60);
			cout << round((start_time - arrival_time) / 60.) << endl;
		}
	}
	cout << vecTable[1].serve_count;
	for (int i = 2; i != K + 1; ++i)
		cout << ' ' << vecTable[i].serve_count;
}
int main()
{
	TableTennis tt;
	tt.get_data();
	tt.compute();
	tt.output();
}