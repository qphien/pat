#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct student
{
	string name;
	string id;
	int grade;
};
bool cmp(const student &a, const student &b)
{
	return a.grade > b.grade;
}
int main()
{
	int n;
	cin >> n;
	vector<student> v(n);
	for (int i = 0; i != n; ++i)
		cin >> v[i].name >> v[i].id >> v[i].grade;
	bool flag = false;
	int grade1, grade2;
	cin >> grade1 >> grade2;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i != n; ++i)
	{
		if (v[i].grade >= grade1 && v[i].grade <= grade2)
		{
			cout << v[i].name << ' ' << v[i].id << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << "NONE";

}