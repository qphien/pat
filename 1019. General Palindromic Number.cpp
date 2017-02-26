#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, base;
	cin >> N >> base;
	vector<int> v;
	while (N)
	{
		v.push_back(N % base);
		N /= base;
	}
	vector<int> temp = v;
	reverse(temp.begin(), temp.end());
	if (temp == v)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if (temp.empty())
		cout << 0;
	else
	{
		cout << temp[0];
		for (int i = 1; i != temp.size(); ++i)
			cout << ' ' << temp[i];
	}
}