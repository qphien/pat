#include <iostream>
#include <string>
#include <vector>
using namespace std;
void hash_func(char c, vector<int> &v)
{
	int t;
	if (c >= '0' && c <= '9')
		t = c - '0';
	else if (c >= 'a' && c <= 'z')
		t = c - 'a' + 10;
	else
		t = c - 'A' + 36;
	++v[t];
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> hash1(10 + 26 + 26);
	vector<int> hash2(10 + 26 + 26);
	for (int i = 0; i != s1.size(); ++i)
		hash_func(s1[i], hash1);
	for (int i = 0; i != s2.size(); ++i)
		hash_func(s2[i], hash2);
	int missing_cnt = 0;
	for (int i = 0; i != hash1.size(); ++i)
	{
		if (hash2[i] - hash1[i] > 0)
			missing_cnt += hash2[i] - hash1[i];
	}
	if (missing_cnt == 0)
		cout << "Yes " << s1.size() - s2.size() << endl;
	else
		cout << "No " << missing_cnt << endl;
}