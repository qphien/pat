#include <iostream>
#include <cstring>
#include <stack>
#pragma warning(disable:4996)
using namespace std;
//或者使用分块
const int maxn = 100001;
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int v, int *c)
{
	for (int i = x; i < maxn; i += lowbit(i))
		c[i] += v;
}
int getSum(int x, int *c)
{
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		sum += c[i];
	return sum;
}
int PeekMedian(int *c, int K)
{
	int left = 1;
	int right = maxn;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (getSum(mid, c) >= K)
			right = mid;
		else
			left = mid + 1;
	}
	return left;

}
int main()
{
	int N;
	scanf("%d", &N);
	//int *a = new int[N] {};
	int *c = new int[maxn] {};
	stack<int> s;
	char p[11];
	for (int i = 0; i != N; ++i)
	{
		scanf("%s", p);
		if (strcmp(p, "Push") == 0)
		{
			int temp;
			scanf("%d", &temp);
			s.push(temp);
			update(temp, 1, c);
		}
		else if (strcmp(p, "Pop") == 0)
		{
			if (s.empty())
				printf("Invalid\n");
			else
			{
				int top = s.top();
				printf("%d\n", top);
				update(top, -1, c);
				s.pop();
			}
		}
		else
		{
			if (s.empty())
				printf("Invalid\n");
			else
			{
				int K = (s.size() + 1) / 2;
				int temp = PeekMedian(c, K);
				printf("%d\n", temp);
			}
		}
	}
}