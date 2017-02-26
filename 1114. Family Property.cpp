#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<int> father(10000);

int find_father(int x)
{
	return x == father[x] ? x : (father[x] = find_father(father[x]));
}

void Union(int x, int y)
{
	int fax = find_father(x);
	int fay = find_father(y);
	if (fax < fay)
		father[fay] = fax;
	else
		father[fax] = fay;
}
struct Person
{
	int id;
	int father;
	int mother;
	double estate;
	double area;
};
struct Family
{
	int family_id;
	int family_number = 0;
	double total_esate = 0;
	double total_area = 0;
	double aver_esate;
	double avera_area;
	bool flag;
};
bool cmp(const Family &a, const Family &b)
{
	if (a.avera_area != b.avera_area) return a.avera_area > b.avera_area;
	return a.family_id < b.family_id;
}
int main()
{
	for (int i = 0; i != 10000; ++i)
		father[i] = i;
	int n;
	vector<bool> flag(10000);
	scanf("%d", &n);
	vector<Person> person(n);
	vector<Family> family(10000);
	for (int i = 0; i != n; ++i)
	{
		int id, father, mother;
		scanf("%d %d %d", &id, &father, &mother);
		person[i].id = id;
		person[i].mother = mother;
		person[i].father = father;
		flag[id] = true;
		if (mother != -1)
		{
			Union(id, mother);
			flag[mother] = true;
		}
		if (father != -1)
		{
			Union(id, father);
			flag[father] = true;
		}
		int k;
		scanf("%d", &k);
		for (int j = 0; j != k; ++j)
		{
			int child;
			scanf("%d", &child);
			flag[child] = true;
			Union(id, child);
		}
		double estate, area;
		scanf("%lf %lf", &estate, &area);
		person[i].estate = estate;
		person[i].area = area;
	}
	for (int i = 0; i != n; ++i)
	{
		int father = find_father(person[i].id);
		family[father].family_id = father;
		family[father].total_area += person[i].area;
		family[father].total_esate += person[i].estate;
		family[father].flag = true;
	}
	for (int i = 0; i != 10000; ++i)
	{
		if (flag[i])
			++family[find_father(i)].family_number;
	}
	int count = 0;
	for (int i = 0; i != 10000; ++i)
	{
		if (family[i].flag)
		{
			++count;
			family[i].aver_esate = family[i].total_esate / family[i].family_number;
			family[i].avera_area = family[i].total_area / family[i].family_number;
		}
	}
	sort(family.begin(), family.end(), cmp);
	printf("%d\n", count);
	for (int i = 0; i != count; ++i)
		printf("%04d %d %.3lf %.3lf\n", family[i].family_id, family[i].family_number,
			family[i].aver_esate, family[i].avera_area);
}