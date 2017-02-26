#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	set<int> s;
	for (int i = 0; i != n; ++i)
	{
		string temp;
		cin >> temp;
		int sum = 0;
		for (int j = 0; j != temp.size(); ++j)
			sum += temp[j] - '0';
		s.insert(sum);
	}
	cout << s.size() << endl;
	for (auto iter = s.begin(); iter != s.end(); ++iter)
	{
		if (iter != s.begin())
			printf(" ");
		printf("%d", *iter);
	}
}