#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int arr[4];
void getArray(int n)
{
	for (int i = 0; i != 4; ++i)
	{
		arr[i] = n % 10;
		n /= 10;
	}
	/*int i = 0;     如果第一次a-b得到3位数，例如123，此时arr[4]应为0，但写成这种形式，a[4]没有覆盖为0，所以有
	一个测试点错误
	while (n)
	{
	arr[i] = n % 10;
	n /= 10;
	++i;
	}*/
}
int getMin()
{
	int sum = 0;
	sort(arr, arr + 4);
	for (int i = 0; i != 4; ++i)
		sum = sum * 10 + arr[i];
	return sum;
}
int getMax()
{
	int sum = 0;
	sort(arr, arr + 4, greater<int>());
	for (int i = 0; i != 4; ++i)
		sum = sum * 10 + arr[i];
	return sum;
}
int main()
{
	int N;
	cin >> N;
	int difference = N;
	int max_number, min_number;
	do
	{
		getArray(difference);
		max_number = getMax();
		min_number = getMin();
		difference = max_number - min_number;
		if (difference == 0)
		{
			printf("%04d - %04d = 0000\n", max_number, min_number);
			return 0;
		}
		printf("%04d - %04d = %04d\n", max_number, min_number, difference);
	} while (difference != 6174);
}