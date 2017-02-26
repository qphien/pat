#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string x;             //由于x位数过高，故使用string类型
	cin >> x;
	int sum = 0;
	vector<int> v;
	for (auto val : x)
		sum += val - '0';
	while (sum)
	{
		v.push_back(sum % 10);
		sum /= 10;
	}
	vector<string> m = { "zero", "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine" };
	if (v.empty())
		cout << "zero" << flush;
	else
	{
		for (int i = v.size() - 1; i >= 0; --i)
		{
			if (i == 0)
				cout << m[v[i]] << flush;
			else
				cout << m[v[i]] << ' ';         //也可以先输出第一位，后面的就不用判断了
		}
	}


}
