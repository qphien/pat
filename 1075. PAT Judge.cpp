#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
struct Info
{
	int id;
	int score[6] = { -1, -1, -1, -1, -1, -1 };
	bool flag = false;   //判断是否输出
	int total_sum = 0;
	int perfectly_solved_number = 0;
};
bool cmp(const Info &a, const Info &b)
{
	if (a.total_sum != b.total_sum) return a.total_sum > b.total_sum;
	if (a.perfectly_solved_number != b.perfectly_solved_number) return a.perfectly_solved_number > b.perfectly_solved_number;
	return a.id < b.id;
}
int main()
{
	int N, K, M;
	scanf("%d%d%d", &N, &K, &M);
	vector<Info> v(N + 1);
	vector<int> point(K + 1);
	for (int i = 1; i != K + 1; ++i)
		scanf("%d", &point[i]);
	for (int i = 1; i != N + 1; ++i)
		v[i].id = i;
	for (int i = 0; i != M; ++i)
	{
		int id, problem, score;
		scanf("%d%d%d", &id, &problem, &score);
		//v[id].id = id;           //为什么id写成这样最后一个测试点不通过？
		if (score != -1)
			v[id].flag = true;
		if (score == -1 && v[id].score[problem] == -1)
			v[id].score[problem] = 0;
		/*	if (score == point[problem] && v[id].score[problem] < point[problem])
		++v[id].perfectly_solved_number;*/
		if (score > v[id].score[problem])
		{
			v[id].score[problem] = score;
		}
	}
	for (int i = 1; i != N + 1; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			if (v[i].score[j] >= 0)
				v[i].total_sum += v[i].score[j];
			if (v[i].score[j] == point[j])
				++v[i].perfectly_solved_number;
		}
	}
	sort(v.begin() + 1, v.end(), cmp);
	int temp_rank = 1;
	for (int i = 1; i != N + 1 && v[i].flag == true; ++i)
	{
		if (i > 1 && v[i].total_sum != v[i - 1].total_sum)
			temp_rank = i;
		printf("%d %05d %d", temp_rank, v[i].id, v[i].total_sum);
		for (int j = 1; j <= K; ++j)
		{
			if (v[i].score[j] == -1)
				printf(" -");
			else
				printf(" %d", v[i].score[j]);
		}
		printf("\n");
	}


}