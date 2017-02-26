#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int getID(char *name)              //string效率低于char数组， cin，cout效率低于scanf，printf
{
	int id = 0;
	for (int i = 0; i != 3; ++i)
		id = id * 26 + name[i] - 'A';
	id = id * 10 + name[3] - '0';
	return id;
}
int main()
{
	int N, K;
	char name[5];
	vector<int> m[26 * 26 * 26 * 10 + 1];
	scanf("%d%d", &N, &K);
	for (int i = 0; i != K; ++i)
	{
		int course_index, student_count;
		scanf("%d%d", &course_index, &student_count);
		for (int j = 0; j != student_count; ++j)
		{
			scanf("%s", name);
			int id = getID(name);
			m[id].push_back(course_index);
		}
	}
	for (int i = 0; i != N; ++i)
	{
		scanf("%s", name);
		int id = getID(name);
		sort(m[id].begin(), m[id].end());
		cout << name << ' ' << m[id].size();
		for (int j = 0; j != m[id].size(); ++j)
			cout << ' ' << m[id][j];
		cout << endl;
	}
}