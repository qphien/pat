#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
int flag;
struct Student
{
	int ID;
	double grades[4];      //vector instead
	int rank[4];
	int best_rank_index;
};
class BestRank
{
	friend bool cmp(Student, Student);
private:
	int N;
	int M;
	//int flag;
	vector<Student> vecStudent;
	vector<int> StudentIndex;
	vector<char> map = { 'A', 'C', 'M', 'E' };
public:
	void get_data();
	void compute();

};
bool cmp(Student i, Student j)
{
	return i.grades[flag] > j.grades[flag];
}
void BestRank::get_data()
{
	cin >> N >> M;
	vecStudent.resize(N);
	StudentIndex.resize(1000000, 0);
	int ID;
	for (int i = 0; i != N; ++i)
	{
		cin >> ID;
		//StudentIndex[ID] = i + 1;
		vecStudent[i].ID = ID;
		for (int j = 1; j != 4; ++j)
			cin >> (vecStudent[i].grades)[j];
		(vecStudent[i].grades)[0] = accumulate(vecStudent[i].grades + 1, vecStudent[i].grades + 4, 0) / 3.0;
	}
	for (flag = 0; flag != 4; ++flag)
	{
		sort(vecStudent.begin(), vecStudent.end(), cmp);
		vecStudent[0].rank[flag] = 1;
		for (int i = 1; i != N; ++i)
		{
			vecStudent[i].rank[flag] = i + 1;
			if (vecStudent[i].grades[flag] == vecStudent[i - 1].grades[flag])
				vecStudent[i].rank[flag] = vecStudent[i - 1].rank[flag];
		}
	}
	for (int i = 0; i != N; ++i)
	{
		StudentIndex[vecStudent[i].ID] = i + 1;
		int best_rank_index = 0;
		for (int j = 1; j != 4; ++j)
		{
			if (vecStudent[i].rank[j] < vecStudent[i].rank[best_rank_index])
				best_rank_index = j;
		}
		vecStudent[i].best_rank_index = best_rank_index;
	}
}
void BestRank::compute()
{
	int CheckID;
	int index;
	/*if (index)
	{
	index -= 1;
	int best_rank_index = vecStudent[index].best_rank_index;
	cout << vecStudent[index].rank[best_rank_index] << ' ' << map[best_rank_index];
	}
	else
	cout << "N/A";*/
	for (int i = 0; i != M; ++i)
	{
		cin >> CheckID;
		index = StudentIndex[CheckID];
		if (index)
		{
			index -= 1;
			int best_rank_index = vecStudent[index].best_rank_index;
			cout << vecStudent[index].rank[best_rank_index] << ' ' << map[best_rank_index] << endl;;
		}
		else
			cout << "N/A" << endl;;
	}
}
int main()
{
	BestRank br;
	br.get_data();
	br.compute();
}