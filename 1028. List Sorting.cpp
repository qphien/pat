#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student
{
	int id;
	char name[10];
	int grade;
};
bool cmp1(Student a, Student b)
{
	return a.id < b.id;
}
bool cmp2(Student a, Student b)
{
	int t = strcmp(a.name, b.name);         //如何用string类型会超时
	if (t != 0)
		return t < 0;
	return a.id < b.id;
}
bool cmp3(Student a, Student b)
{
	if (a.grade != b.grade) return a.grade < b.grade;
	return a.id < b.id;
}
int main()
{
	int N, C;
	cin >> N >> C;
	vector<Student> vecStudent(N);
	for (int i = 0; i != N; ++i)
		cin >> vecStudent[i].id >> vecStudent[i].name >> vecStudent[i].grade;
	switch (C)
	{
	case 1:
		sort(vecStudent.begin(), vecStudent.end(), cmp1);
		break;
	case 2:
		sort(vecStudent.begin(), vecStudent.end(), cmp2);
		break;
	case 3:
		sort(vecStudent.begin(), vecStudent.end(), cmp3);
	}
	for (int i = 0; i != N; ++i)
	{
		printf("%06d %s %d\n", vecStudent[i].id, vecStudent[i].name, vecStudent[i].grade);
	}
}