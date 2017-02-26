#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int>::iterator viter;
int flag = 0;
vector<int> changed;
vector<int> v;
void merge_sort(viter begin, viter end)
{
	if (end - begin > 1)
	{
		int i = *begin;
		int j = *(end - 1);
		merge_sort(begin, begin + (end - begin) / 2);
		merge_sort(begin + (end - begin) / 2, end);
		if (flag == 1)
		{
			inplace_merge(begin, begin + (end - begin) / 2, end);
			return;
		}
		inplace_merge(begin, begin + (end - begin) / 2, end);
		if (v == changed)
			++flag;
	}
}
int main()
{
	int n;
	cin >> n;
	v.resize(n);
	changed.resize(n);
	for (int i = 0; i != n; ++i)
		cin >> v[i];
	for (int i = 0; i != n; ++i)
		cin >> changed[i];
	vector<int> v1 = v;
	for (int i = 2; i <= n; ++i)         //中间序列不包括初始序列，不然有一个测试点不能通过
	{
		sort(v1.begin(), v1.begin() + i);
		if (v1 == changed)
		{
			cout << "Insertion Sort" << endl;
			sort(v1.begin(), v1.begin() + i + 1);
			for (int j = 0; j != n; ++j)
			{
				if (j != 0)
					cout << ' ';
				cout << v1[j];
			}
			return 0;
		}
	}
	for (int i = 2; i / 2 <= n; i *= 2)
	{
		for (int j = 0; j < n; j += i)
			sort(v.begin() + j, v.begin() + min(j + i, n));
		if (v == changed)
		{
			cout << "Merge Sort" << endl;
			i *= 2;
			for (int j = 0; j < n; j += i)
				sort(v.begin() + j, v.begin() + min(j + i, n));
			for (int i = 0; i != n; ++i)
			{
				if (i != 0)
					cout << ' ';
				cout << v[i];
			}
			return 0;
		}
	}

}