#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i != K; ++i)
	{
		//bool flag = true;
		stack<int> s;
		vector<int> v(M);
		for (int j = 0; j != M; ++j)
			cin >> v[j];
		int index = 0;
		for (int j = 1; j != M + 1; ++j)
		{
			s.push(j);
			if (s.size() > N)
				break;
			while (!s.empty() && s.top() == v[index])
			{
				s.pop();
				++index;
			}
		}
		if (index == M)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}