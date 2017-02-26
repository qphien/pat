#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int times;
	cin >> times;
	vector<string> vecStr;
	vecStr.push_back("1");
	vector<string> v = { "S", "H", "C", "D" };
	for (int j = 0; j != 4; ++j)
		for (char i = 1; i <= 13; ++i)
			vecStr.push_back(v[j] + to_string(i));
	vecStr.push_back("J1");
	vecStr.push_back("J2");
	vector<string> result(55);
	vector<int> index(55);
	vector<int> result_index(55);
	for (int i = 1; i != 55; ++i)
		cin >> index[i];
	for (int i = 1; i != 55; ++i)
	{
		int temp = index[i];
		for (int j = 0; j != times - 1; ++j)
		{
			temp = index[temp];
		}
		result[temp] = vecStr[i];
	}
	cout << result[1];
	for (int i = 2; i != 55; ++i)
		cout << ' ' << result[i];
}