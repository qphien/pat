#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class LargestGeneration
{
private:
	int N;
	int M;
	vector<vector<int>> indegree;
	const int RootID = 1;
	//vector<bool> collected;
	vector<int> level_number;
public:
	void GetData();
	void compute();
	int find_generation();
	int vector_size(const vector<int> &);
};
int LargestGeneration::vector_size(const vector<int> &v)
{
	if (v.empty())
		return 0;
	return v.size();
}
void LargestGeneration::GetData()
{
	cin >> N >> M;
	indegree.resize(N + 1);
	level_number.resize(100, 0);
	for (int i = 0; i != M; ++i)
	{
		int ID;
		int child;
		int number;
		cin >> ID >> number;
		for (int j = 0; j != number; ++j)
		{
			cin >> child;
			indegree[ID].push_back(child);
		}
	}
}
void LargestGeneration::compute()
{
	queue<int> queID;
	queID.push(RootID);
	//collected[RootID] = true;
	level_number[1] = 1;
	int level = 2;
	int tail = 1;
	while (true)
	{
		int id = queID.front();
		queID.pop();
		int size = vector_size(indegree[id]);
		level_number[level] += size; //impovement£º create a vector 
									 //to store the child number when input data so we can bypass the computation of size
		for (int i = 0; i != size; ++i)
		{
			queID.push(indegree[id][i]);
		}
		if (queID.empty())
			break;
		if (id == tail)
		{
			tail = queID.back();
			++level;
		}
	}
	int generation = find_generation();
	cout << level_number[generation] << " " << generation << flush;
}
int LargestGeneration::find_generation()
{
	int index = 0;
	for (int i = 1; i != 100; ++i)
	{
		if (level_number[i] == 0)
			break;
		if (level_number[i] > level_number[index])
			index = i;
	}
	return index;
}
int main()
{
	LargestGeneration lg;
	lg.GetData();
	lg.compute();
}