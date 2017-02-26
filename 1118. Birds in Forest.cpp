#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
vector<int> father(10001);
int FindFather(int x)
{
	if (x == father[x])
		return x;
	else
	{
		int f = FindFather(father[x]);
		father[x] = f;
		return f;
	}
}
int main()
{
	for (int i = 0; i != 10001; ++i)
		father[i] = i;
	vector<int> flag(10001);
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int i = 0; i != n; ++i)
	{
		int k;
		scanf("%d", &k);
		int first;
		for (int j = 0; j != k; ++j)
		{
			int bird;
			scanf("%d", &bird);
			if (!flag[bird])
			{
				flag[bird] = true;
				++count;
			}
			if (j == 0)
				first = FindFather(bird);
			else
			{
				if (FindFather(bird) != first)
					father[FindFather(bird)] = first;
			}
		}
	}
	int tree = 0;
	for (int i = 1; i <= count; ++i)
	{
		if (FindFather(i) == i)
			++tree;
	}
	cout << tree << ' ' << count << endl;
	int k;
	scanf("%d", &k);
	for (int i = 0; i != k; ++i)
	{
		int bird1, bird2;
		scanf("%d %d", &bird1, &bird2);
		if (father[bird1] == father[bird2])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}