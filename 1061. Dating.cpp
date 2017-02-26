#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> v(4);
	vector<string> map = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int date, hour, minu;
	for (int i = 0; i != 4; ++i)
		cin >> v[i];
	int i = 0;
	int size = min(v[0].size(), v[1].size());
	for (; i != size; ++i)
	{
		if (v[0][i] == v[1][i] && (v[0][i] >= 'A' && v[0][i] <= 'G'))   //只能到G
		{
			date = v[0][i] - 'A';
			break;
		}
	}
	++i;
	for (; i != size; ++i)
	{
		if (v[0][i] == v[1][i])
		{
			if (v[0][i] >= '0' && v[0][i] <= '9')
			{
				hour = v[0][i] - '0';
				break;
			}
			else if (v[0][i] >= 'A' &&  v[0][i] <= 'N')  //只能到N
			{
				hour = v[0][i] - 'A' + 10;
				break;
			}

		}
	}
	int size1 = min(v[2].size(), v[3].size());
	for (int j = 0; j != size1; ++j)
	{
		if (v[2][j] == v[3][j])
		{
			if (v[2][j] >= 'a' && v[2][j] <= 'z' || v[2][j] > 'A' && v[2][j] <= 'Z')
			{
				minu = j;
				break;
			}
		}
	}
	cout << map[date] << ' ';
	printf("%02d", hour);
	printf(":%02d", minu);
}