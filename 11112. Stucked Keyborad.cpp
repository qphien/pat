#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int k;
	string s;
	cin >> k >> s;
	string stucked_key;
	int i = 0;
	while (i < s.size())
	{
		bool flag = true;
		for (int j = i; j != i + k - 1; ++j)
		{
			if (s[j] != s[j + 1])
			{
				flag = false;
				break;
			}
		}
		auto iter = stucked_key.find(s[i]);
		if (flag)
		{
			if (iter == string::npos)
				stucked_key += s[i];
			i += k;
		}
		else
		{

			if (iter != string::npos)
				stucked_key.erase(iter);
			++i;
		}
	}
	for (auto val : stucked_key)
		cout << val;
	cout << endl;
	i = 0;
	while (i < s.size())
	{
		cout << s[i];
		if (stucked_key.find(s[i]) != string::npos)
			i += k;
		else
			++i;
	}
}