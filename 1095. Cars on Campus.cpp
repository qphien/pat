#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#pragma warning(disable:4996)
using namespace std;
struct car
{
	char plate[8];
	int time;
	char status[5];
};
bool cmp(const car &a, const car &b)
{
	int flag = strcmp(a.plate, b.plate);
	if (flag != 0) return flag < 0;
	return a.time < b.time;
}
bool cmp1(const car &a, const car &b)
{
	return a.time < b.time;
}
int convert(int hour, int min, int second)
{
	return hour * 3600 + min * 60 + second;
}
int main()
{
	int n, query_number;
	scanf("%d %d", &n, &query_number);
	vector<car> v(n);
	for (int i = 0; i != n; ++i)
	{
		scanf("%s", v[i].plate);
		int hour, min, sec;
		scanf("%d:%d:%d", &hour, &min, &sec);
		v[i].time = convert(hour, min, sec);
		scanf("%s", v[i].status);
	}
	sort(v.begin(), v.end(), cmp);
	map<string, int> m;
	vector<car> valid;
	for (int i = 0; i != n - 1; ++i)
	{
		if (strcmp(v[i].plate, v[i + 1].plate) == 0 &&
			strcmp(v[i].status, "in") == 0 &&
			strcmp(v[i + 1].status, "out") == 0)
		{
			m[v[i].plate] += v[i + 1].time - v[i].time;
			valid.push_back(v[i]);
			valid.push_back(v[i + 1]);
		}
	}
	sort(valid.begin(), valid.end(), cmp1);
	int number = 0;
	int index = 0;
	for (int i = 0; i != query_number; ++i)
	{
		int hour, min, sec;
		scanf("%d:%d:%d", &hour, &min, &sec);
		int time = convert(hour, min, sec);
		for (int j = index; j != valid.size(); ++j)
		{
			if (valid[j].time <= time)
			{
				if (strcmp(valid[j].status, "in") == 0)
					++number;
				else
					--number;
			}
			else
			{
				index = j;
				break;
			}
		}
		printf("%d\n", number);
	}
	vector<string> ans;
	int max_time = -1;
	for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		if ((*iter).second > max_time)
		{
			max_time = (*iter).second;
			ans.clear();
			ans.push_back((*iter).first);
		}
		else if ((*iter).second == max_time)
			ans.push_back((*iter).first);
	}
	int hour = max_time / 3600;
	int min = max_time % 3600 / 60;
	int sec = max_time % 60;
	for (auto val : ans)
		cout << val << ' ';
	printf("%02d:%02d:%02d\n", hour, min, sec);
}