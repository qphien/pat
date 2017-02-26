#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1, v2, result;
	int result_size = 0;
	int N;
	cin >> N;
	result_size += N;
	for (int i = 0; i != N; ++i)
	{
		int temp;
		cin >> temp;
		v1.push_back(temp);
	}
	cin >> N;
	result_size += N;
	for (int i = 0; i != N; ++i)
	{
		int temp;
		cin >> temp;
		v2.push_back(temp);
	}
	if (result_size != 0)
	{
		result.resize(result_size);
		merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
		cout << result[(result_size - 1) / 2];
	}
}