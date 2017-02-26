#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//将两个数的和的问题转化成和的两个分部是否存在
int main()
{
	int N, M;
	cin >> N >> M;
	int a[1000] = {};
	for (int i = 0; i != N; ++i)
	{
		int temp;
		cin >> temp;
		++a[temp];
	}
	for (int i = 1; i != M; ++i)
	{
		if (a[i] && a[M - i])
		{
			if (i == M - i && a[i] < 2)
				continue;
			cout << i << ' ' << M - i;
			return 0;
		}
	}
	cout << "No Solution";
}

