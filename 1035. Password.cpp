#include <vector>
#include <iostream>
#include <string>
using namespace std;
//如果用map来写的话，可能会有account重复的test，所以应选取unordered_multimap
//multimap没有operator[]操作符，只能使用insert
struct Info
{
	string name;
	string password;
	bool is_changed;
};
class Password
{
private:
	int N;
	int change_number = 0;
	vector<Info> vecInfo;
public:
	void get_data();
	void change_password(Info&);
	void compute();
};
void Password::get_data()
{
	cin >> N;
	vecInfo.resize(N);
	for (int i = 0; i != N; ++i)
	{
		cin >> vecInfo[i].name >> vecInfo[i].password;
		change_password(vecInfo[i]);
	}
}
void Password::change_password(Info &node)
{
	for (int i = 0; i != node.password.size(); ++i)
	{
		if (node.password[i] == '1')
		{
			node.password[i] = '@';
			node.is_changed = true;
		}
		else if (node.password[i] == '0')
		{
			node.password[i] = '%';
			node.is_changed = true;
		}
		else if (node.password[i] == 'l')
		{
			node.password[i] = 'L';
			node.is_changed = true;
		}
		else if (node.password[i] == 'O')
		{
			node.password[i] = 'o';
			node.is_changed = true;
		}
	}
	if (node.is_changed)
		++change_number;
}
void Password::compute()
{
	if (N == 1)
	{
		cout << "There is 1 account and no account is modified";
		return;
	}
	if (change_number == 0)
		cout << "There are " << N << " accounts and no account is modified";
	else
	{
		cout << change_number << endl;
		for (int i = 0; i != N; ++i)
		{
			if (vecInfo[i].is_changed)
				cout << vecInfo[i].name << ' ' << vecInfo[i].password << endl;
		}
	}
}
int main()
{
	Password ps;
	ps.get_data();
	ps.compute();
}