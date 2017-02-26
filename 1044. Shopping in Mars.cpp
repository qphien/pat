#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
//int upper_bound(int left, int right, int x, int *sum)
//{
//	int mid;
//	while (left < right)
//	{
//		mid = (left + right) / 2;
//		if (sum[mid] > x)
//			right = mid;
//		else
//			left = mid + 1;
//	}
//	return left;
//}
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> sum(N + 1);
	int nearS = (1 << 31) - 1;
	for (int i = 1; i != N + 1; ++i)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i != N + 1; ++i)
	{
		vector<int>::iterator j = upper_bound(sum.begin() + i, sum.end(), sum[i - 1] + M);
		if (*(j - 1) == sum[i - 1] + M)
		{
			nearS = M;
			break;
		}
		else if (j != sum.end() && *j - sum[i - 1] < nearS)
		{
			nearS = *j - sum[i - 1];
		}
	}
	for (int i = 1; i != N + 1; ++i)
	{
		vector<int>::iterator j = upper_bound(sum.begin() + i, sum.end(), nearS + sum[i - 1]);
		if (*(j - 1) - sum[i - 1] == nearS)
			printf("%d-%d\n", i, j - 1 - sum.begin());
	}
}