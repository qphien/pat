#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class HeadOfGang
{
private:
	int N;
	int K;
	int number = 0;
	map<string, int> m;
	vector<string> v;
	vector<vector<int>> graph;
	vector<bool> collected;
	map<string, int> result;
	map<string, int> m_max;
public:
	void get_data();
	void compute();
	void dfs(int, int&, int&, string&, int);
};
void HeadOfGang::get_data()
{
	cin >> N >> K;
	string temp1, temp2;
	int length;
	graph.resize(2 * N, vector<int>(2 * N, 0));
	collected.resize(N << 1);
	v.resize(N << 1);
	for (int i = 0; i != N; ++i)
	{
		cin >> temp1 >> temp2 >> length;
		if (m.find(temp1) == m.end())
		{
			m[temp1] = i;
			v[i] = temp1;
		}
		if (m.find(temp2) == m.end())
		{
			m[temp2] = N + i;
			v[N + i] = temp2;
		}
		graph[m[temp1]][m[temp2]] = length;
		m_max[temp1] += length;
		m_max[temp2] += length;
		//graph[m[temp2]][m[temp1]] += length;
	}
}
void HeadOfGang::compute()
{
	for (map<string, int>::iterator i = m.begin(); i != m.end(); ++i)
	{
		int index = (*i).second;
		if (collected[index] == false)
		{
			int total_number = 0;
			int total_weight = 0;
			string s_max;
			int max = 0;
			dfs(index, total_number, total_weight, s_max, max);
			if (total_weight > K && total_number > 2)
			{
				++number;
				result[s_max] = total_number;
			}
		}
	}
	cout << number << endl;
	for (map<string, int>::iterator i = result.begin(); i != result.end(); ++i)
		cout << (*i).first << ' ' << (*i).second << endl;
}
void HeadOfGang::dfs(int index, int &total_number, int &total_weight, string &s_max, int max)
{
	collected[index] = true;
	++total_number;
	if (m_max[v[index]] > max)
	{
		s_max = v[index];
		max = m_max[v[index]];
	}
	for (int i = 0; i != 2 * N; ++i)
	{
		if (graph[index][i] != 0)
		{
			total_weight += graph[index][i] + graph[i][index];       //防止回头 如BBB到AAA的边
			graph[i][index] = 0;
			if (collected[i] == false)
			{
				dfs(i, total_number, total_weight, s_max, max);
			}
		}
	}
}
int main()
{
	HeadOfGang hog;
	hog.get_data();
	hog.compute();
}