#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool IsPalindromic(vector<int> &x, int len)
{
	for (int i = 0; i <= len / 2; ++i)
	{
		if (x[i] != x[len - 1 - i])
			return false;
	}
	return true;
}
void convert(string &x, vector<int> &convert_N)
{
	int size = x.size();
	for (int i = 0; i != size; ++i)
		convert_N[size - i - 1] = x[i] - '0';
}
void add(vector<int> &convert_N, const vector<int> &reverse_N, int &len)
{
	int carry = 0;
	for (int i = 0; i != len; ++i)
	{
		int temp = convert_N[i] + reverse_N[i] + carry;
		convert_N[i] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0)
		convert_N[len++] = carry;
}
int main()
{
	string N;                        //因为N可能为10的1000次方 远超过long long
	int K;
	cin >> N >> K;
	vector<int> convert_N(1000);
	int step = 0;
	int len = N.size();
	convert(N, convert_N);
	vector<int> reverse_N;
	while (!IsPalindromic(convert_N, len))
	{
		reverse_N.assign(convert_N.begin(), convert_N.begin() + len);
		reverse(reverse_N.begin(), reverse_N.end());
		add(convert_N, reverse_N, len);
		++step;
		if (step == K)
			break;

	}
	for (int i = len - 1; i >= 0; --i)
	{
		cout << convert_N[i];
	}
	cout << endl;
	cout << step;
}