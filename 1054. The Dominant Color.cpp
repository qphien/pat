#include <unordered_map>
#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
//cin会超时
//int main()
//{
//	int M, N;
//	cin >> M >> N;
//	unordered_map<int, int> result;
//	int half = M * N / 2;
//	for (int i = 0; i != N; ++i)
//	{
//		for (int j = 0; j != M; ++j)
//		{
//			int temp;
//			scanf("%d", &temp);
//			++result[temp];
//			if (result[temp] > half)
//			{
//				cout << temp;
//				break;
//			}
//		}
//	}
//	
//}
//
//第二种方法

int main()
{
	int M, N;
	cin >> M >> N;
	int ans = 0;
	int count = 0;
	for (int i = 0; i != N; ++i)
	{
		for (int j = 0; j != M; ++j)
		{
			int temp;
			scanf("%d", &temp);
			if (count == 0)
			{
				ans = temp;
				count = 1;
				continue;
			}
			if (ans == temp)
				++count;
			else
				--count;
		}
	}
	cout << ans;
}