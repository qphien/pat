#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	vector<char> v = { 'W', 'T', 'L' };
	double max;
	double temp;
	int index;
	double ans = 1;
	for (int i = 0; i != 3; ++i)
	{
		max = 0;
		index = 0;
		for (int j = 0; j != 3; ++j)
		{
			cin >> temp;
			if (max < temp)
			{
				max = temp;
				index = j;
			}
		}
		ans *= max;
		cout << v[index] << ' ';
	}
	cout << fixed << setprecision(2) << (ans * 0.65 - 1) * 2 << flush;
}