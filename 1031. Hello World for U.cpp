#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n1_temp, n2_temp, n3_temp;
	int n1 = 0, n3 = 0, n2;
	int N = s.size();
	for (int n2_temp = 3; n2_temp <= N; ++n2_temp)
	{
		n1_temp = n3_temp = (N + 2 - n2_temp) / 2;    //注意，此时n1_temp可能会向下取整，使得n1_temp + n2_temp + n3_temp != N + 2
		if (n1_temp + n2_temp + n3_temp != N + 2)
			continue;
		if (n1_temp <= n2_temp && n1_temp > n1)
		{
			n1 = n3 = n1_temp;
			n2 = n2_temp;
		}
	}
	int i = 0;
	for (; i != n1 - 1; ++i)
	{
		cout << left << setw(n2 - 1) << s[i] << s[N - i - 1] << endl;
	}
	for (; i != n1 - 1 + n2; ++i)
		cout << s[i];
}