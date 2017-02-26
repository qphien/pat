#include <vector>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s;
	cin >> s;
	vector<int> v1(10);
	vector<int> v2(10);
	for (int i = 0; i != s.size(); ++i)
	{
		int index = s[i] - '0';
		++v1[index];
	}
	int carry = 0;
	int len = 0;
	vector<int> double_v;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		int temp = (s[i] - '0') * 2 + carry;
		double_v.push_back(temp % 10);
		carry = temp / 10;
		++len;
	}
	while (carry)
	{
		double_v.push_back(carry % 10);
		carry /= 10;
		++len;
	}
	if (len != s.size())
		cout << "No" << endl;
	else
	{
		for (auto val : double_v)
			++v2[val];
		if (v1 == v2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	for (int i = double_v.size() - 1; i >= 0; --i)
		cout << double_v[i];

}