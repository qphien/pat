#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
struct Person
{
	int arrival_time;
	int serve_time;
};
class QueueAtBank
{
private:
	int N, K;
	int total_time = 0;
	//int PeopleNumber = 0;
	vector<int> time;
	vector<Person> vecPerson;
public:
	void get_data();
	void compute();
	int ConvertTime(string s);
};
bool cmp(Person a, Person b)
{
	if (a.arrival_time < b.arrival_time)
		return true;
	return false;
}
int QueueAtBank::ConvertTime(string s)
{
	return stoi(s.substr(0, 2)) * 60 * 60 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
}
void QueueAtBank::get_data()
{
	cin >> N >> K;
	time.resize(K, 8 * 60 * 60);
	string clock;
	int serve_time;
	//vecPerson.resize(N);
	for (int i = 0; i != N; ++i)
	{
		cin >> clock;
		cin >> serve_time;
		int temp = ConvertTime(clock);
		if (temp > 17 * 60 * 60)
			continue;
		if (serve_time > 60)
			serve_time = 60;
		vecPerson.push_back({ temp, serve_time });
	}
	N = vecPerson.size();
}
void QueueAtBank::compute()
{
	sort(vecPerson.begin(), vecPerson.end(), cmp); //为什么连当前一个人处理完的时间超过17：00， 在17：00之前到来的顾客
												   //还继续服务？
	for (int i = 0; i != N; ++i)
	{
		int index = 0;
		for (int j = 1; j != K; ++j)
		{
			if (time[j] < time[index])
				index = j;
		}
		if (time[index] > vecPerson[i].arrival_time)
		{
			total_time += time[index] - vecPerson[i].arrival_time;
			time[index] += vecPerson[i].serve_time * 60;
		}
		else
			time[index] = vecPerson[i].arrival_time + vecPerson[i].serve_time * 60;

	}
	double result = total_time / N / 60.;
	cout << fixed << setprecision(1) << result << endl;
}

int main()
{
	QueueAtBank qab;
	qab.get_data();
	qab.compute();
}