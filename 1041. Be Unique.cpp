#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> vec(10001);
	vector<int> v(N);
	for (int i = 0; i != N; ++i)
	{
		int temp;
		cin >> temp;
		v[i] = temp;
		++vec[temp];
	}
	for (int i = 0; i != N; ++i)
	{
		if (vec[v[i]] == 1)
		{
			cout << v[i];
			return 0;
		}
	}
	cout << "None";


}