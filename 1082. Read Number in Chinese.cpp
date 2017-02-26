#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	vector<string> num = { "ling", "yi", "er", "san", "si",
		"wu", "liu", "qi", "ba", "jiu" };
	vector<string> wei1 = { "Shi", "Bai", "Qian" };
	vector<string> wei2 = { "Wan", "Yi" };
	string s;
	cin >> s;
	int left = 0;
	if (s[0] == '-')
	{
		cout << "Fu";
		++left;
	}
	int right = s.size() - 1;
	while (left + 4 <= right)
		right -= 4;
	while (left < s.size())
	{
		bool flag = false;
		bool isPrint = false;
		while (left <= right)
		{
			if (left > 0 && s[left] == '0')
				flag = true;
			else
			{
				if (flag)
				{
					cout << " ling";
					flag = false;
				}
				if (left > 0)
					cout << ' ';
				cout << num[s[left] - '0'];
				isPrint = true;
				if (left != right)
					cout << ' ' << wei1[right - left - 1];
			}
			++left;
		}
		if (isPrint && right != s.size() - 1)
			cout << ' ' << wei2[(s.size() - 1 - right) / 4 - 1];
		right += 4;
	}
}