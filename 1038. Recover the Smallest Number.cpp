#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//注意当输出为0时，此时s为空
bool cmp(const string &a, const string &b)
{
	return a + b < b + a;
}
int main()
{
	int N;
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i != N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	string s;
	for (int i = 0; i != N; ++i)
		s += v[i];
	size_t pos = s.find_first_not_of('0');
	if (pos != 0)
		s.erase(0, pos);
	if (s.empty())
		cout << 0;
	else
		cout << s;
}
