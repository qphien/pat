#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int K1, K2;
	cin >> K1;
	vector<double> p1(1001, 0);
	vector<double> p2(1001, 0);
	vector<double> result(2001, 0);
	while (K1--)
	{
		int exp;
		double coeff;
		cin >> exp >> coeff;
		p1[exp] += coeff;
	}
	cin >> K2;
	while (K2--)
	{
		int exp;
		double coeff;
		cin >> exp >> coeff;
		p2[exp] += coeff;
	}
	for (int i = 0; i != 1001; ++i)
	{
		if (p1[i] != 0)
		{
			for (int j = 0; j != 1001; ++j)
			{
				if (p2[j] != 0)
				{
					int result_exp = i + j;
					double result_coeff = p1[i] * p2[j];
					result[result_exp] += result_coeff;
				}
			}
		}
	}
	int count = 0;
	for (int i = 0; i != 2001; ++i)
	{
		if (result[i] != 0)
			++count;
	}
	cout << count;
	for (int i = 2000; i >= 0; --i)
	{
		if (result[i] != 0)
		{
			cout << ' ' << i << ' ' << fixed << setprecision(1) << result[i];
		}
	}
}