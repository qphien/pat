#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int m = ceil(sqrt(N));
	while (N % m != 0)
		++m;
	int n = N / m;
	vector<vector<int>> v(m, vector<int>(n));
	vector<int> arr(N);
	for (int i = 0; i != N; ++i)
		scanf("%d", &arr[i]);
	sort(arr.rbegin(), arr.rend());
	if (N == 1)
	{
		printf("%d\n", arr[0]);
		return 0;
	}
	int U = 0, D = m - 1, R = n - 1, L = 0;
	int t = 0, i = 0, j = 0;
	while (t < N)
	{
		while (j < R && t < N)
		{
			v[i][j] = arr[t++];
			++j;
		}
		while (i < D && t < N)
		{
			v[i][j] = arr[t++];
			++i;
		}
		while (j > L && t < N)
		{
			v[i][j] = arr[t++];
			--j;
		}
		while (i > U && t < N)
		{
			v[i][j] = arr[t++];
			--i;
		}
		++j, ++i;
		U += 1;
		D -= 1;
		L += 1;
		R -= 1;
		if (t == N - 1)
			v[i][j] = arr[t++];
	}
	for (int i = 0; i != m; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			if (j > 0)
				printf(" ");
			printf("%d", v[i][j]);
		}
		printf("\n");
	}
}