#include <iostream>
#include <map>
#include <string>
using namespace std;
bool check(char c)
{
	if (c >= 'A' && c <= 'Z') return true;
	if (c >= '0' && c <= '9') return true;
	if (c >= 'a' && c <= 'z') return true;
	return false;
}
int main()
{
	string s;
	getline(cin, s);
	s.push_back('\n');       //或者在末尾添加一个无效字符，有没有类似getline的函数，但不抛弃尾部的\n
	map<string, int> m;
	int max = 0;
	string result;
	string temp;
	for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
	{
		if (check(*iter))
		{
			if (*iter >= 'A' && *iter <= 'Z')
				*iter += 32;
			temp.push_back(*iter);
		}
		else
		{
			if (temp == "")
				continue;
			++m[temp];
			temp.clear();
		}
		//if (iter == s.end() - 1 && check(*iter))     //如果不加这一行，输入abc就不会有输出，因为前面的判断条件是根据有效字符串后一定跟一个无效字符串
		//++m[temp];

	}
	for (map<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		if ((*iter).second > max)
		{
			max = (*iter).second;
			result = (*iter).first;
		}
	}
	cout << result << ' ' << max;
}
