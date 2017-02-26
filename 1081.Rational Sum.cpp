#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
long long get_common_divisor(long long x, long long y)
{
	if (x < y) swap(x, y);
	long long r = x % y;
	while (r)
	{
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}
long long get_common_multiple(long long x, long long y)
{
	long long r = x * y / get_common_divisor(x, y);
	return r;
}
struct rational
{
	long long numerator;
	long long denomintor;
};
int main()
{
	int N;
	cin >> N;
	vector<rational> v(N);
	long long common_multiply = 1;
	for (int i = 0; i != N; ++i)
	{
		scanf("%lld/%lld", &v[i].numerator, &v[i].denomintor);
		common_multiply = get_common_multiple(common_multiply, v[i].denomintor);
	}
	long long numerator = 0;
	for (int i = 0; i != N; ++i)
		numerator += common_multiply / v[i].denomintor * v[i].numerator;
	long long integer = numerator / common_multiply;
	long long rest_numerator = numerator % common_multiply;
	if (rest_numerator == 0)
		cout << integer;
	else
	{
		if (integer != 0)
			cout << integer << ' ';
		long long common_divisor = get_common_divisor(rest_numerator, common_multiply);
		rest_numerator /= common_divisor;
		common_multiply /= common_divisor;
		printf("%lld/%lld", rest_numerator, common_multiply);
	}
}
