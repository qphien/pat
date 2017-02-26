#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int pos_of_E = s.find('E');
	int count = 0;
	string result;
	if (s[0] == '-')
		result = "-";
	if (pos_of_E != string::npos)
	{
		int temp = pos_of_E;
		int exp = stoi(s.substr(pos_of_E + 1));
		//exp = exp < 0 ? -exp : exp;
		int pos_of_point = s.find('.');
		//result.assign(s.begin() + 1, s.begin() + pos_of_point);
		int new_pos_of_point = pos_of_point + exp;
		if (new_pos_of_point >= pos_of_E - 1)
		{
			result.append(s.begin() + 1, s.begin() + pos_of_point);
			result.append(s.begin() + pos_of_point + 1, s.begin() + pos_of_E);
			result.append(new_pos_of_point - pos_of_E + 1, '0');
		}
		else if (new_pos_of_point <= 1)
		{
			result.append("0.");
			result.append(1 - new_pos_of_point, '0');
			result.append(s.begin() + 1, s.begin() + pos_of_point);
			result.append(s.begin() + pos_of_point + 1, s.begin() + pos_of_E);
		}
		else
		{
			//result.append(s.begin() + 1, s.begin() + pos_of_E);
			if (new_pos_of_point > pos_of_point)
			{
				for (int i = pos_of_point; i != new_pos_of_point; ++i)
					s[i] = s[i + 1];
				s[new_pos_of_point] = '.';
			}
			else
			{
				for (int i = pos_of_point; i != new_pos_of_point; --i)
					s[i] = s[i - 1];
				s[new_pos_of_point] = '.';
			}
			result.append(s.begin() + 1, s.begin() + pos_of_E);
		}
	}
	cout << result;

}