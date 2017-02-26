#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
//用string和cout会超时
using namespace std;
char name[40000][5];
bool cmp(int a, int b)
{
	return strcmp(name[a], name[b]) < 0;
}
int main()
{
	int N, M;
	cin >> N >> M;
	int C;
	vector<vector<int>> vecCourse(M + 1);
	for (int i = 0; i != N; ++i)
	{
		cin >> name[i];
		cin >> C;
		for (int j = 0; j != C; ++j)
		{
			int temp;
			cin >> temp;
			vecCourse[temp].push_back(i);
		}
	}
	for (int i = 1; i <= M; ++i)
	{
		sort(vecCourse[i].begin(), vecCourse[i].end(), cmp);
		cout << i << ' ' << vecCourse[i].size() << endl;
		for (int j = 0; j != vecCourse[i].size(); ++j)
			printf("%s\n", name[vecCourse[i][j]]);
	}
}