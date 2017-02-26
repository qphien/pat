#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
	string name;
	char gender;
	string ID;
	int grade;
};
bool cmp(const Student &a, const Student &b)
{
	return a.grade < b.grade;
}
class BoysVsGirls
{
private:
	int N;
	vector<Student> vecMale;
	vector<Student> vecFemale;
public:
	void get_data();
	void compute();
};
void BoysVsGirls::get_data()
{
	cin >> N;
	string name;
	char gender;
	string ID;
	int grade;
	for (int i = 0; i != N; ++i)
	{
		cin >> name >> gender >> ID >> grade;
		if (gender == 'M')
			vecMale.push_back({ name, gender, ID, grade });
		else
			vecFemale.push_back({ name, gender, ID, grade });
	}
}
void BoysVsGirls::compute()
{
	sort(vecFemale.begin(), vecFemale.end(), cmp);
	sort(vecMale.begin(), vecMale.end(), cmp);
	int highest_grade;
	int lowest_grade;
	if (!vecFemale.empty())
	{
		cout << vecFemale.back().name << ' ' << vecFemale.back().ID << endl;
		highest_grade = vecFemale.back().grade;
	}
	else
	{
		cout << "Absent" << endl;
		highest_grade = -1;
	}
	if (!vecMale.empty())
	{
		cout << vecMale.front().name << ' ' << vecMale.front().ID << endl;
		lowest_grade = vecMale.front().grade;
	}
	else
	{
		cout << "Absent" << endl;
		lowest_grade = -1;
	}
	if (highest_grade == -1 || lowest_grade == -1)
		cout << "NA" << endl;
	else
		cout << highest_grade - lowest_grade << endl;
}
int main()
{
	BoysVsGirls bvg;
	bvg.get_data();
	bvg.compute();
}