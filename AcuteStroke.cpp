#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class AcuteStroke
{
private:
	int M;
	int N;
	int L;
	int T;
	vector<vector<vector<int>>> data;
	int count = 0;
public:
	void get_data();
	void compute();
	void bfs(int, int, int);
	int output() { return count; };
	bool InRange(int, int, int);
};
void AcuteStroke::get_data()
{
	cin >> M >> N >> L >> T;
	data.resize(L, vector<vector<int>>(M, vector<int>(N)));
	for (int layer = 0; layer != L; ++layer)
	{
		for (int row = 0; row != M; ++row)
		{
			for (int col = 0; col != N; ++col)
				cin >> data[layer][row][col];
		}
	}
}
void AcuteStroke::compute()
{
	for (int layer = 0; layer != L; ++layer)
	{
		for (int row = 0; row != M; ++row)
		{
			for (int col = 0; col != N; ++col)
			{
				if (data[layer][row][col] == 1)
					bfs(layer, row, col);
			}
		}
	}
}
bool AcuteStroke::InRange(int layer, int row, int col)
{
	return layer >= 0 && layer < L && row >= 0 && row < M && col >= 0 && col < N;
}
void AcuteStroke::bfs(int layer, int row, int col)
{
	queue<vector<int>> que;
	int valide_core = 1;
	que.push({ layer, row, col });
	data[layer][row][col] = 0;
	vector<int> dx = { 1, -1, 0, 0, 0, 0 };
	vector<int> dy = { 0, 0, 1, -1, 0,0 };
	vector<int> dz = { 0, 0,0, 0, 1, -1 };
	while (!que.empty())
	{
		vector<int> vTemp = que.front();
		que.pop();
		for (int i = 0; i != 6; ++i)
		{
			int new_layer = vTemp[0] + dz[i];
			int new_row = vTemp[1] + dx[i];
			int new_col = vTemp[2] + dy[i];
			if (InRange(new_layer, new_row, new_col) && data[new_layer][new_row][new_col])
			{
				que.push({ new_layer, new_row, new_col });
				data[new_layer][new_row][new_col] = 0;
				++valide_core;
			}
		}
	}
	if (valide_core >= T)
		count += valide_core;
}
int main()
{
	AcuteStroke as;
	as.get_data();
	as.compute();
	cout << as.output() << flush;
}