#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Record
{
	string name;
	int month, date, hour, min;
	bool flag;
};
bool cmp(Record a, Record b)
{
	if (a.name != b.name) return a.name < b.name;
	if (a.month != b.month) return a.month < b.month;
	if (a.date != b.date) return a.date < b.date;
	if (a.hour != b.hour) return a.hour < b.hour;
	if (a.min != b.min) return a.min < b.min;
}
class PhoneBills
{
private:
	int toll[24];
	vector<Record> record;
	int N;
public:
	void get_data();
	void compute();
	void GetMoneyAndTime(Record on, Record off, int &time, int &money);
};
void PhoneBills::get_data()
{
	for (int i = 0; i != 24; ++i)
		cin >> toll[i];
	cin >> N;
	record.resize(N);
	string temp;
	for (int i = 0; i != N; ++i)
	{
		cin >> (record[i].name);
		scanf("%d:%d:%d:%d", &record[i].month, &record[i].date, &record[i].hour, &record[i].min);
		cin >> temp;
		if (temp == "on-line")
			record[i].flag = true;
		else
			record[i].flag = false;
	}
}
void PhoneBills::GetMoneyAndTime(Record a, Record b, int &time, int &money)
{
	while (a.date < b.date || a.hour < b.hour || a.min < b.min)
	{
		++time;
		money += toll[a.hour];
		if (++a.min == 60)
		{
			++a.hour;
			a.min = 0;
			if (a.hour == 24)
			{
				a.hour = 0;
				++a.date;
			}
		}
	}
}
void PhoneBills::compute()
{
	sort(record.begin(), record.end(), cmp);
	int on = 0;
	int next;
	int off;
	while (on < N)
	{
		int pair = 0;
		next = on;
		while (next < N && record[on].name == record[next].name)
		{
			if (pair == 0 && record[next].flag == true)
				++pair;
			if (pair == 1 && record[next].flag == false)
				++pair;
			++next;
		}
		if (pair != 2)
		{
			on = next;
			continue;
		}
		int total_money = 0;
		cout << record[on].name << ' ' << setw(2) << setfill('0') << record[on].month << endl;
		while (on < next)
		{
			while (on < next - 1 && !(record[on].flag == true && record[on + 1].flag == false))
				++on;
			off = on + 1;
			if (off == next)
			{
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", record[on].date, record[on].hour, record[on].min);
			printf("%02d:%02d:%02d ", record[off].date, record[off].hour, record[off].min);
			int time = 0, money = 0;
			GetMoneyAndTime(record[on], record[off], time, money);
			cout << time << " $" << fixed << setprecision(2) << money / 100.0 << endl;
			total_money += money;
			on = off + 1;
		}
		cout << "Total amount: $" << fixed << setprecision(2) << total_money / 100.0 << endl;
	}
}
int main()
{
	PhoneBills pb;
	pb.get_data();
	pb.compute();
}