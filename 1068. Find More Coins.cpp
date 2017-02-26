#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const int &a, const int &b)
{
	return a > b;
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> w(N + 1);
	w[0] = 0;
	vector<int> dp(M + 1);
	vector<vector<int>> choice(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i)
		cin >> w[i];
	sort(w.begin() + 1, w.end(), cmp);
	for (int i = 1; i <= N; ++i)
	{
		for (int v = M; v >= w[i]; --v)
		{
			if (dp[v] <= dp[v - w[i]] + w[i])
			{
				dp[v] = dp[v - w[i]] + w[i];
				choice[i][v] = 1;
			}
		}
	}
	if (dp[M] != M)
		cout << "No Solution";
	else
	{
		int k = N;
		int v = M;
		int number = 0;
		vector<bool> flag(N + 1);
		while (k > 0)
		{
			if (choice[k][v])
			{
				flag[k] = true;
				v -= w[k];
				++number;
			}
			--k;
		}
		for (int i = N; i > 0; --i)
		{
			if (flag[i])
			{
				cout << w[i];
				--number;
				if (number > 0)
					cout << ' ';
				else
					break;
			}
		}
	}
}