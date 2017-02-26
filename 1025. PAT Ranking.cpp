#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct StudentInfo
{
	long long register_number;           //可将register_number设为string
	int location;
	int score;
	int local_rank;
	//int final_rank;
};
bool cmp(StudentInfo a, StudentInfo b)
{
	if (a.score != b.score) return a.score > b.score;
	if (a.register_number != b.register_number) return a.register_number < b.register_number;
}
class PATRanking
{
private:
	vector<StudentInfo> vecStudent;
	int location_number;
	int result_number;
public:
	void get_data();
	void compute();
};
void PATRanking::get_data()
{
	cin >> location_number;
	for (int i = 0; i != location_number; ++i)
	{
		int LocationStudentNumber;
		cin >> LocationStudentNumber;
		StudentInfo stuInfo;
		for (int j = 0; j != LocationStudentNumber; ++j)
		{
			long long ID;
			int score;
			cin >> ID >> score;
			stuInfo.register_number = ID;
			stuInfo.score = score;
			stuInfo.location = i + 1;
			vecStudent.push_back(stuInfo);
			++result_number;
		}
		sort(vecStudent.begin() + result_number - LocationStudentNumber, vecStudent.begin() + result_number, cmp);
		vecStudent[result_number - LocationStudentNumber].local_rank = 1;
		for (int k = result_number - LocationStudentNumber + 1; k != result_number; ++k)
		{
			if (vecStudent[k].score == vecStudent[k - 1].score)
				vecStudent[k].local_rank = vecStudent[k - 1].local_rank;
			else
				vecStudent[k].local_rank = k - (result_number - LocationStudentNumber - 1);
		}
	}
}
void PATRanking::compute()
{
	cout << result_number << endl;
	sort(vecStudent.begin(), vecStudent.end(), cmp);
	int r = 1;
	for (int i = 0; i != result_number; ++i)
	{
		if (i > 0 && vecStudent[i].score != vecStudent[i - 1].score)
			r = i + 1;
		cout << setw(13) << setfill('0') << vecStudent[i].register_number << ' ' << r << ' ' <<
			vecStudent[i].location << ' ' << vecStudent[i].local_rank << endl;
	}

}
int main()
{
	PATRanking patranking;
	patranking.get_data();
	patranking.compute();
}