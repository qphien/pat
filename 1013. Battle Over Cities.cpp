#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BattleOverCity
{
private:
	int N;
	int M;
	int K;
	vector<vector<int>> connection;
	void dfs(const vector<vector<int>> &conn, vector<bool> &collected, int j);
	//int number = 1;
public:
	void get_data();
	void compute();
	int GetConectionComponetsNum(vector<vector<int>>, int);
};
void BattleOverCity::get_data()
{
	cin >> N >> M >> K;
	connection.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i != M; ++i)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		connection[temp1][temp2] = connection[temp2][temp1] = 1;
	}
}
void BattleOverCity::compute()
{
	for (int i = 0; i != K; ++i)
	{
		int temp;
		cin >> temp;
		cout << GetConectionComponetsNum(connection, temp) - 1 << endl;
	}
}
int BattleOverCity::GetConectionComponetsNum(vector<vector<int>> conn, int i)
{
	//for (int j = 1; j != N + 1; ++j)
	//conn[i][j] = conn[j][i] = 0;
	int number = 0;
	vector<bool> collected(N + 1, false);
	collected[i] = true;
	//queue<int> que;
	for (int j = 1; j != N + 1; ++j)
	{
		/*que.push(j);
		if (collected[j] == false)   //bfs    运行会超时
		{
		++number;
		while (!que.empty())
		{
		int temp = que.front();
		que.pop();
		collected[temp] = true;
		for (int k = 1; k != N + 1; ++k)
		{
		if (conn[temp][k] == 1 && collected[k] == false)
		{
		que.push(k);
		}
		}
		}
		}*/
		if (collected[j] == false)
		{
			++number;
			dfs(conn, collected, j);
		}

	}
	return number;
}
void BattleOverCity::dfs(const vector<vector<int>> &conn, vector<bool> &collected, int j)
{
	collected[j] = true;
	for (int i = 1; i != N + 1; ++i)
	{
		if (conn[j][i] == 1 && collected[i] == false)
			dfs(conn, collected, i);
	}
}
int main()
{
	BattleOverCity boc;
	boc.get_data();
	boc.compute();
}