#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const string &a, const string &b)
{
	return a.size() < b.size();
}
int main()
{
	int N;
	cin >> N;
	string ans;
	vector<string> v(N);
	cin.ignore();
	for (int i = 0; i != N; ++i)
		getline(cin, v[i]);
	sort(v.begin(), v.end(), cmp);
	size_t t = v[0].size();
	bool flag = true;
	for (int i = 0; i != t && flag; ++i)
	{
		char c = v[0][t - i - 1];
		for (int j = 1; j != v.size() && flag; ++j)
		{
			if (v[j][v[j].size() - 1 - i] != c)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
		ans += c;
	}
	if (ans == "")
		cout << "nai";
	for (int i = ans.size() - 1; i >= 0; --i)
		printf("%c", ans[i]);
}