#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, p;
int max_factor_sum = -1;
vector<int> v;
vector<int> temp_ans;
vector<int> ans;
void dfs(int index, int sum, int number, int factor_sum)
{
	if (sum == n && number == k)
	{
		if (factor_sum > max_factor_sum)
		{
			ans = temp_ans;
			max_factor_sum = factor_sum;
		}
		return;
	}
	if (sum > n || number > k)
		return;
	if (index >= 1)
	{
		temp_ans.push_back(index);
		dfs(index, sum + v[index], number + 1, factor_sum + index);
		temp_ans.pop_back();
		dfs(index - 1, sum, number, factor_sum);
	}
}
int main()
{
	cin >> n >> k >> p;
	int temp = 0;
	int i = 1;
	while (temp <= n)       //如果不加等号会有一个测试点不通过
	{
		v.push_back(temp);
		temp = pow(i++, p);
	}
	dfs(v.size() - 1, 0, 0, 0);
	if (max_factor_sum == -1)
		printf("Impossible\n");
	else
	{
		printf("%d =", n);
		for (int i = 0; i != ans.size(); ++i)
		{
			if (i != 0)
				printf(" +");
			printf(" %d^%d", ans[i], p);
		}
	}
}