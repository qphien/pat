#include <iostream>
#include <string>

using namespace std;
int n;
string deal(string s, int &exp)
{
	while (!s.empty() && s.front() == '0')
		s.erase(s.begin());
	if (!s.empty() && s.front() == '.')
	{
		s.erase(s.begin());
		while (!s.empty() && s.front() == '0')
		{
			s.erase(s.begin());
			--exp;
		}
	}
	else
	{
		for (int i = 0; i != s.size(); ++i)
		{
			if (s[i] == '.')
			{
				s.erase(i, 1);
				break;
			}
			++exp;
		}
	}
	string result;
	if (s.empty())
		exp = 0;
	for (int i = 0; i != n; ++i)
	{
		if (i < s.size())
			result.push_back(s[i]);
		else
			result.push_back('0');
	}
	return result;
}
int main()
{
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int exp1 = 0, exp2 = 0;
	s1 = deal(s1, exp1);
	s2 = deal(s2, exp2);
	if (exp1 == exp2 && s1 == s2)
		cout << "YES 0." << s1 << "*10^" << exp1;
	else
		cout << "NO 0." << s1 << "*10^" << exp1 << " 0." << s2 << "*10^" << exp2;
}