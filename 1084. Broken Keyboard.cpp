#include <string>
#include <iostream>
#include <set>
using namespace std;

char switch_case(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return c;
}
int main()
{
	bool hashtable[256] = {};
	set<char> sc;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i != s2.size(); ++i)
		hashtable[switch_case(s2[i])] = true;
	for (int i = 0; i != s1.size(); ++i)
	{
		if (hashtable[switch_case(s1[i])] == false)
		{
			auto p = sc.insert(switch_case(s1[i]));
			if (p.second)
				cout << switch_case(s1[i]);
		}
	}
}
