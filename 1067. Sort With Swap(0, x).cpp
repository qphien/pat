#include <vector>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> pos(N);
	int temp;
	int number = N - 1;
	for (int i = 0; i != N; ++i)
	{
		scanf("%d", &temp);
		pos[temp] = i;
		if (temp == i  && temp != 0)
			--number;
	}
	int k = 1;
	int step = 0;
	while (number > 0)
	{
		if (pos[0] == 0)
		{
			for (int i = k; i != N; ++i)
			{
				if (pos[i] != i)
				{
					swap(pos[0], pos[i]);
					k = i;
					++step;
					break;
				}
			}
		}
		while (pos[0] != 0)
		{
			swap(pos[0], pos[pos[0]]);
			--number;
			++step;
		}
	}
	printf("%d", step);


}