#include <iostream>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
bool is_prime(int x)
{
	if (x <= 1) return false;
	for (int i = 2; i <= sqrt(x); ++i)
		if (x % i == 0)
			return false;
	return true;
}
int main()
{
	vector<int> flag(10001);
	vector<int> rank(10001);
	int n;
	scanf("%d", &n);
	for (int i = 1; i != n + 1; ++i)
	{
		int id;
		scanf("%d", &id);
		flag[id] = 1;
		rank[id] = i;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i != m; ++i)
	{
		int id;
		scanf("%d", &id);
		printf("%04d: ", id);
		if (flag[id])
		{
			if (flag[id] == 1)
			{
				if (rank[id] == 1)
					printf("Mystery Award\n");
				else
				{
					if (is_prime(rank[id]))
						printf("Minion\n");
					else
						printf("Chocolate\n");
				}
				++flag[id];
			}
			else
				printf("Checked\n");
		}
		else
			printf("Are you kidding?\n");
	}
}