#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	vector<long long> v(n);
	for (int i = 0; i != n; ++i)
		scanf("%lld", &v[i]);
	sort(v.begin(), v.end());
	int max_ans = 0;
	for (int i = 0; i != n; ++i)
	{
		auto j = upper_bound(v.begin() + i + 1, v.end(), p * v[i]);
		max_ans = max(max_ans, (int)(j - v.begin() - i));
	}
	cout << max_ans << endl;
}
