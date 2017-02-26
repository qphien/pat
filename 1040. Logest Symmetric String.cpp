#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[1001];
	int t[1001][1001] = { 0 };
	int ans = 1;
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		t[i][i] = 1;
		if (i < len - 1)
		{
			if (s[i] == s[i + 1])
			{
				t[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	for (int L = 3; L <= len; ++L)
	{
		for (int i = 0; i + L - 1 < len; ++i)
		{
			int j = i + L - 1;
			if (s[i] == s[j] && t[i + 1][j - 1] == 1)
			{
				t[i][j] = 1;
				ans = L;
			}
		}
	}
	cout << ans;
}