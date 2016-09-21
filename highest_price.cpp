#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;

class HighestPrice
{
public:
	int N;
	double price;
	double rate;
	vector<int> supplier;
public:
	void get_data();
	void compute();
	int find_path_number_to_root(int);
};
int HighestPrice::find_path_number_to_root(int i)
{
	int count = 0;
	while (supplier[i] != -1)
	{
		count += 1;
		i = supplier[i];
	}
	return count;
}
void HighestPrice::get_data()
{
	cin >> N >> price >> rate;
	supplier.resize(N);
	for (int i = 0; i != N; ++i)
		cin >> supplier[i];
}
void HighestPrice::compute()
{
	int count = 1;
	int max = numeric_limits<int>::min();
	for (int i = 0; i != N; ++i)
	{
		int temp = find_path_number_to_root(i);
		if (temp > max)
		{
			max = temp;
			count = 1;
		}
		else if (temp == max)
			++count;
	}
	double real_rate = 1 + rate / 100.;
	double highest_price = price * pow(real_rate, max);
	//cout.precision(2);
	cout << fixed << setprecision(2) << highest_price << " ";
	cout << count << flush;
}
int main()
{
	HighestPrice hp;
	hp.get_data();
	hp.compute();
}