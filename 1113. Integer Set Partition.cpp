#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int t = n / 2;
	if (n % 2 == 0)
		printf("0 ");
	else
		printf("1 ");
	int n1 = accumulate(v.begin(), v.begin() + t, 0);
	int n2 = accumulate(v.begin() + t, v.end(), 0);
	printf("%d\n", n2 - n1);

}