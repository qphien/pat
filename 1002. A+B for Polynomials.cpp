#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void get_data(vector<double> &result)
{
	int K;
	double coeff;
	int exp;
	cin >> K;
	for (int i = 0; i != K; ++i)
	{
		cin >> exp >> coeff;
		result[exp] += coeff;
	}
}
int main()
{
	vector<double> result(1001, 0.0);
	for (int i = 0; i != 2; ++i)
		get_data(result);
	int size = 0;
	for (int i = 0; i != 1001; ++i)
	{
		if (result[i] != 0)
			++size;
	}
	cout << size;
	if (size != 0)   //pay attention to size == 0
	{
		cout << ' ';
		int i = 1000;
		for (; i >= 0; --i)
		{
			if (result[i] != 0)
			{
				if (size == 1)
					break;
				cout << i << " " << fixed << setprecision(1) << result[i] << ' ';
				--size;
			}
		}
		cout << i << ' ' << fixed << setprecision(1) << result[i] << flush;
	}
}