#include <iostream>
#include <math.h>
using namespace std;
const int maxn = 100010;
bool p[maxn] = {};
int cnt = 0;
int primer[maxn];
int n;
struct Factor
{
	int x;
	int cnt;
};
void Find_primer()
{
	primer[0] = 1;
	cnt = 1;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (p[i] == false)
		{
			primer[cnt++] = i;
			for (int j = i + i; j <= sqrt(n); j += i)
				p[j] = true;
		}
	}
}
int main()
{
	cin >> n;
	Factor factor[10];
	Find_primer();
	if (n == 1)
		cout << "1=1";
	else
	{
		cout << n << '=';
		int num = 0;
		for (int i = 1; i != cnt; ++i)
		{
			if (n % primer[i] == 0)
			{
				factor[num].x = primer[i];
				factor[num].cnt = 0;
				while (n % primer[i] == 0)
				{
					n /= primer[i];
					++factor[num].cnt;
				}
				++num;
			}
			if (n == 1) break;
		}
		if (n != 1)
		{
			factor[num].x = n;
			factor[num++].cnt = 1;
		}
		cout << factor[0].x;
		if (factor[0].cnt > 1)
			cout << '^' << factor[0].cnt;
		for (int i = 1; i != num; ++i)
		{
			cout << '*' << factor[i].x;
			if (factor[i].cnt > 1)
				cout << '^' << factor[i].cnt;
		}
	}
}
