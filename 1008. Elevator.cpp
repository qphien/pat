#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int cur_floor = 0;
	int second = 0;
	for (int i = 0; i != N; ++i)
	{
		int next_floor;
		cin >> next_floor;
		int difference = next_floor - cur_floor;
		second += difference < 0 ? (-difference) * 4 : difference * 6;
		cur_floor = next_floor;
	}
	cout << second + N * 5 << flush;
}