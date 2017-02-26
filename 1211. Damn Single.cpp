#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	vector<int> companion_number(100001, -1);
	vector<bool> compaion_exist(100001);
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		companion_number[temp1] = temp2;
		companion_number[temp2] = temp1;
	}
	int m;
	cin >> m;
	vector<int> v(m);
	for (int i = 0; i != m; ++i)
	{
		int temp;
		scanf("%d", &temp);
		v[i] = temp;
		compaion_exist[temp] = true;
	}
	int single_dog = 0;
	vector<int> ans;
	for (int i = 0; i != m; ++i)
	{
		if (companion_number[v[i]] == -1)   //single dog
			ans.push_back(v[i]);
		else
		{
			if (!compaion_exist[companion_number[v[i]]])    //companion doesn't attend the party
				ans.push_back(v[i]);
		}
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i != ans.size(); ++i)
	{
		if (i > 0)
			printf(" ");
		printf("%05d", ans[i]);
	}
}