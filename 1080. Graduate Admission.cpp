#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

struct Student
{
	int Ge;
	int Gi;
	int rank;
	int final_sorce;
	int index;
	vector<int> school;
};
int N, M, K;
vector<int> school_quota;
vector<Student> vecStudent;
bool cmp(const Student &a, const Student &b)
{
	if (a.final_sorce != b.final_sorce) return a.final_sorce > b.final_sorce;
	return a.Ge > b.Ge;
}
int main()
{
	cin >> N >> M >> K;
	vecStudent.resize(N);
	school_quota.resize(M);
	vector<vector<int>> ans(M);
	for (int i = 0; i != M; ++i)
		scanf("%d", &school_quota[i]);
	for (int i = 0; i != N; ++i)
	{
		scanf("%d %d", &vecStudent[i].Ge, &vecStudent[i].Gi);
		vecStudent[i].final_sorce = (vecStudent[i].Ge + vecStudent[i].Gi) / 2;
		vecStudent[i].index = i;
		for (int j = 0; j != K; ++j)
		{
			int school_number;
			scanf("%d", &school_number);
			vecStudent[i].school.push_back(school_number);
		}
	}
	sort(vecStudent.begin(), vecStudent.end(), cmp);
	vecStudent[0].rank = 1;
	for (int i = 1; i != N; ++i)
	{
		if (vecStudent[i].final_sorce == vecStudent[i - 1].final_sorce &&
			vecStudent[i].Ge == vecStudent[i - 1].Ge)
			vecStudent[i].rank = vecStudent[i - 1].rank;
		else
			vecStudent[i].rank = i + 1;
	}
	int last_choose_school;
	for (int i = 0; i != N; ++i)
	{
		if (i == 0)
		{
			--school_quota[vecStudent[i].school[0]];
			ans[vecStudent[i].school[0]].push_back(vecStudent[i].index);
			last_choose_school = vecStudent[i].school[0];
		}
		else
		{
			if (vecStudent[i].rank != vecStudent[i - 1].rank)
			{
				for (int j = 0; j != K; ++j)
				{
					if (school_quota[vecStudent[i].school[j]] > 0)
					{
						--school_quota[vecStudent[i].school[j]];
						ans[vecStudent[i].school[j]].push_back(vecStudent[i].index);
						last_choose_school = vecStudent[i].school[j];
						break;
					}
				}
			}
			else
			{
				for (int j = 0; j != K; ++j)
				{
					if (vecStudent[i].school[j] != last_choose_school)
					{
						if (school_quota[vecStudent[i].school[j]] > 0)
						{
							--school_quota[vecStudent[i].school[j]];
							ans[vecStudent[i].school[j]].push_back(vecStudent[i].index);
							last_choose_school = vecStudent[i].school[j];
							break;
						}
					}
					else
					{
						--school_quota[vecStudent[i].school[j]];
						ans[vecStudent[i].school[j]].push_back(vecStudent[i].index);
						last_choose_school = vecStudent[i].school[j];
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i != M; ++i)
	{
		sort(ans[i].begin(), ans[i].end());
		for (int j = 0; j != ans[i].size(); ++j)
		{
			if (j > 0)
				printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
}