#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int size1 = s1.size();
	int size2 = s2.size();
	bool table[128] = {};
	for (int i = 0; i != s2.size(); ++i)
		table[s2[i]] = true;
	int t = 0;
	for (int i = 0; i != s1.size(); ++i)
	{
		if (table[s1[i]] == false)
			cout << s1[i];
	}

}