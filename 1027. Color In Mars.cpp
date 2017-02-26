#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int red, green, blue;
	cin >> red >> green >> blue;
	vector<int> vColor = { red, green, blue };
	vector<vector<int>> v(3);
	vector<char>  m = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C' };
	cout << '#';
	if (red == 0 && green == 0 && blue == 0)
		cout << "000000";
	for (int i = 0; i != 3; ++i)
	{
		while (vColor[i])
		{
			v[i].push_back(vColor[i] % 13);
			vColor[i] /= 13;
		}
		if (v[i].size() == 1)
			cout << 0 << m[v[i][0]];
		else
		{
			for (int j = v[i].size() - 1; j >= 0; --j)
				cout << m[v[i][j]];
		}
	}
}