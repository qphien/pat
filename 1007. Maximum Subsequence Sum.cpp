#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class MaxSubSum
{
private:
	int K;
	vector<int> v;
	bool flag = false;
	int start = 0, end;
	int sum = numeric_limits<int>::min();
public:
	void get_data();
	void compute();
	void output();
};
void MaxSubSum::get_data()
{
	cin >> K;
	for (int i = 0; i != K; ++i)
	{
		int temp;
		cin >> temp;
		if (temp >= 0)
			flag = true;
		v.push_back(temp);
	}
}
void MaxSubSum::compute()
{
	if (!flag)
	{
		start = 0;
		end = K - 1;
		sum = 0;
		return;
	}
	int sub_sum = 0;
	int TempStart = 0;
	int times = 0;
	for (int i = 0; i != K; ++i)
	{
		sub_sum += v[i];
		if (sub_sum > sum)
		{
			//++times;
			//if (times == 1)					//为什么用times这种方法有部分测试点是错误的？
			//start = i;
			start = TempStart;
			end = i;
			sum = sub_sum;
		}
		if (sub_sum < 0)
		{
			sub_sum = 0;
			//times = 0;
			TempStart = i + 1;
		}
	}
}
void MaxSubSum::output()
{
	cout << sum << ' ' << v[start] << ' ' << v[end] << flush;
}
int main()
{
	MaxSubSum mss;
	mss.get_data();
	mss.compute();
	mss.output();
}