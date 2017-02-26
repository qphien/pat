#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
//cin，cout会超时，以后写算法暂时不用
struct Person
{
	char name[9];
	int age;
	int wealth;
};
bool cmp(const Person &a, const Person &b)
{
	if (a.wealth != b.wealth) return a.wealth > b.wealth;
	if (a.age != b.age) return a.age < b.age;
	return strcmp(a.name, b.name) < 0;
}
class TheWorldRichest
{
private:
	int N;
	int K;
	vector<Person> vecPerson;
public:
	void get_data();
	void compute(int, int, int, int);
};
void TheWorldRichest::get_data()
{
	cin >> N >> K;
	vecPerson.resize(N);
	for (int i = 0; i != N; ++i)
		scanf("%s%d%d", &vecPerson[i].name, &vecPerson[i].age, &vecPerson[i].wealth);
	sort(vecPerson.begin(), vecPerson.end(), cmp);
	for (int i = 1; i <= K; ++i)
	{
		int max_output;
		int Amin, Amax;
		cin >> max_output >> Amin >> Amax;
		compute(max_output, Amin, Amax, i);
	}
}
void TheWorldRichest::compute(int max_output, int Amin, int Amax, int order)
{
	int count = 0;
	printf("%s%d:\n", "Case #", order);
	for (int i = 0; i != N; ++i)
	{
		if (count >= max_output)
			return;
		Person p = vecPerson[i];
		if (p.age >= Amin && p.age <= Amax)
		{
			printf("%s %d %d\n", p.name, p.age, p.wealth);
			++count;
		}
	}
	if (count == 0)
		cout << "None" << endl;
}
int main()
{
	TheWorldRichest wr;
	wr.get_data();
}