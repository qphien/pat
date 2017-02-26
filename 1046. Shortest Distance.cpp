#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int sum = 0;
	vector<int> dist(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		int temp;
		cin >> temp;
		sum += temp;
		dist[i] = sum;
	}
	int M;
	cin >> M;
	for (int i = 0; i != M; ++i)
	{
		int src, dest;
		cin >> src >> dest;
		if (src > dest)
			swap(src, dest);
		int result = dist[dest - 1] - dist[src - 1];
		cout << min(sum - result, result) << endl;
	}

}