#include <iostream>
#include <vector>
#include <set>
#pragma warning(disable:4996)
using namespace std;
vector<set<int>> v;
void compute(int s1, int s2)
{
	int Nc = 0;
	int total = v[s2].size();
	for (set<int>::iterator iter = v[s1].begin(); iter != v[s1].end(); ++iter)
	{
		if (v[s2].find(*iter) != v[s2].end())
			++Nc;
		else
			++total;
	}
	printf("%.1f%%\n", Nc * 100. / total);
}
int main()
{
	int N;
	scanf("%d", &N);
	v.resize(N);
	int temp;
	int val;
	for (int i = 0; i != N; ++i)
	{
		scanf("%d", &temp);
		//v[i].resize(temp);
		for (int j = 0; j != temp; ++j)
		{
			scanf("%d", &val);
			v[i].insert(val);
		}
	}
	int K;
	scanf("%d", &K);
	int s1, s2;
	for (int i = 0; i != K; ++i)
	{
		scanf("%d%d", &s1, &s2);
		compute(s1 - 1, s2 - 1);
	}
}