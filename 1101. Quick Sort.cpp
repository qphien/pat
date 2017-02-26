#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
const int inf = 1000000001;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	vector<int> leftMax(n), rightMin(n);
	leftMax[0] = 0;
	rightMin.back() = inf;
	for (int i = 1; i != n; ++i)
		leftMax[i] = max(leftMax[i - 1], v[i - 1]);
	for (int i = n - 2; i >= 0; --i)
		rightMin[i] = min(rightMin[i + 1], v[i + 1]);
	vector<int> ans;
	for (int i = 0; i != n; ++i)
	{
		if (v[i] > leftMax[i] && v[i] < rightMin[i])
			ans.push_back(v[i]);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i != ans.size(); ++i)
	{
		if (i != 0)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");      //必须要有换行，不然有一个测试点错误
}