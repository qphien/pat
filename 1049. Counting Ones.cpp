#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int N;
	scanf("%d", &N);
	int a = 1;
	int left, right, now;
	int result = 0;
	while (N / a != 0)         //不这么写会超时，因为存在int到bool的转换
	{
		left = N / (a * 10);
		now = N / a % 10;
		right = N % a;
		if (now == 0) result += left * a;
		else if (now == 1) result += left * a + right + 1;
		else result += (left + 1) * a;
		a *= 10;
	}
	printf("%d", result);
}