#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int c = a + b;
	if (c == 0)
		cout << 0 << flush;
	if (c < 0)
	{
		cout << '-' << flush;
		c = -c;
	}
	vector<int> seperate_c;
	while (c)
	{
		int temp = c % 10;
		seperate_c.push_back(temp);
		c /= 10;
	}
	int size = seperate_c.size();
	for (int i = size - 1; i >= 0; --i)
	{
		cout << seperate_c[i];
		--size;
		if (size % 3 == 0 && size != 0)
			cout << ',' << flush;
	}
}