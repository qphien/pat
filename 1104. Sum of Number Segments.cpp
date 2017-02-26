#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<double> v(n);
	double ans = 0;
	double temp;
	for (int i = 0; i != n; ++i)
	{
		cin >> temp;
		ans += temp * (n - i) * (i + 1);
	}
	printf("%.2lf", ans);

}