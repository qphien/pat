#include <iostream>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

bool is_prime(int x)
{
	if (x == 1) return false;
	int t = sqrt(x);
	for (int i = 2; i <= t; ++i)
		if (x % i == 0)
			return false;
	return true;
}
int find_prime(int x)
{
	while (!is_prime(x))
		++x;
	return x;
}
int hashing(int x, int tablesize)
{
	return x % tablesize;
}
int find_pos(const vector<bool> &v, int val)
{
	int pos = hashing(val, v.size());
	if (v[pos] == false)
		return pos;
	int m;
	for (int i = 1; i != v.size(); ++i)
	{
		m = (val + i * i) % v.size();
		if (v[m] == false)
			return m;
	}
	return -1;
}
int main()
{
	int M, N;
	cin >> M >> N;
	int tablesize = find_prime(M);
	vector<bool> v(tablesize);
	for (int i = 0; i != N; ++i)
	{
		if (i > 0)
			printf(" ");
		int val;
		scanf("%d", &val);
		int pos = find_pos(v, val);
		if (pos == -1)
			printf("-");
		else
		{
			printf("%d", pos);
			v[pos] = true;
		}

	}
}