#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> leftP(s.size());
	vector<int> rightT(s.size());
	long long ans = 0;
	for (int i = 1; i != s.size(); ++i)
		leftP[i] = s[i - 1] == 'P' ? leftP[i - 1] + 1 : leftP[i - 1];
	for (int i = s.size() - 2; i >= 0; --i)
	{
		rightT[i] = s[i + 1] == 'T' ? rightT[i + 1] + 1 : rightT[i + 1];
		if (s[i] == 'A')
			ans += leftP[i] * rightT[i];
	}
	cout << ans % 1000000007 << endl;
}
