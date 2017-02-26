#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Record
{
	string ID_number;
	int sign_in_time_h;
	int sign_in_time_m;
	int sign_in_time_s;
	int sign_out_time_h;
	int sign_out_time_m;
	int sign_out_time_s;
};
class SignInAndOut
{
private:
	vector<Record> v;
	int M;
	int lock_index = 0;
	int unlock_index = 0;
public:
	void get_data();
	void compute();
	void output();
};
void SignInAndOut::get_data()
{
	cin >> M;
	string ID;
	string sign_in, sign_out;
	for (int i = 0; i != M; ++i)
	{
		cin >> ID;
		cin >> sign_in >> sign_out;
		v.push_back({ ID,
			stoi(sign_in.substr(0, 2)), stoi(sign_in.substr(3, 2)),stoi(sign_in.substr(6)),
			stoi(sign_out.substr(0,2)), stoi(sign_out.substr(3, 2)),stoi(sign_out.substr(6)) });
	}
}
void SignInAndOut::compute()
{
	for (int i = 1; i != M; ++i)
	{
		if (v[i].sign_in_time_h < v[unlock_index].sign_in_time_h)
			unlock_index = i;
		else if (v[i].sign_in_time_h == v[unlock_index].sign_in_time_h &&
			v[i].sign_in_time_m < v[unlock_index].sign_in_time_m)
			unlock_index = i;
		else if (v[i].sign_in_time_h == v[unlock_index].sign_in_time_h &&
			v[i].sign_in_time_m == v[unlock_index].sign_in_time_m &&
			v[i].sign_in_time_s < v[unlock_index].sign_in_time_s)
			unlock_index = i;
		if (v[i].sign_out_time_h > v[lock_index].sign_out_time_h)
			lock_index = i;
		else if (v[i].sign_out_time_h == v[lock_index].sign_out_time_h &&
			v[i].sign_out_time_m > v[i].sign_out_time_m)
			lock_index = i;
		else if (v[i].sign_out_time_h == v[lock_index].sign_out_time_h &&
			v[i].sign_out_time_m == v[lock_index].sign_out_time_m &&
			v[i].sign_out_time_s > v[lock_index].sign_out_time_s)
			lock_index = i;
	}
}
void SignInAndOut::output()
{
	cout << v[unlock_index].ID_number << ' ' << v[lock_index].ID_number << flush;
}
int main()
{
	SignInAndOut s;
	s.get_data();
	s.compute();
	s.output();
}