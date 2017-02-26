#include <iostream>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int number;
	cin >> number;
	int t = sqrt(number);
	for (int len = 17; len >= 1; --len)      //注意len == 1的情况
	{
		for (int start = 2; start <= t; ++start)
		{
			int ans = 1;
			for (int i = start; i != start + len; ++i)
				ans *= i;
			if (number % ans == 0)
			{
				printf("%d\n", len);
				for (int i = start; i != start + len; ++i)
				{
					if (i != start)
						printf("*");
					printf("%d", i);
				}
				return 0;
			}
		}
	}
	printf("1\n%d", number);

}