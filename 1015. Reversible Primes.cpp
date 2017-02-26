#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool IsPrime(int x)
{
	if (x <= 1) return false;
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int N, radix;
	while (true)
	{
		cin >> N;
		if (N < 0)
			break;
		cin >> radix;
		if (!IsPrime(N))
		{
			cout << "No" << endl;
			continue;
		}
		vector<int> arr;
		while (N)
		{
			arr.push_back(N % radix);
			N /= radix;
		}
		for (int i = 0; i != arr.size(); ++i)
			N = N * radix + arr[i];
		if (IsPrime(N))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}