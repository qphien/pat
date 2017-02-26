#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
vector<int> map(256);
long long convert_to_number(string s, long long radix)
{
	long long ans = 0;
	for (int i = 0; i != s.size(); ++i)
	{
		ans = ans * radix + map[s[i]];
		if (ans < 0) return -1;
	}
	return ans;
}
int find_largest_digit(string s)
{
	int ans = -1;
	for (int i = 0; i != s.size(); ++i)
	{
		if (map[s[i]] > ans)
			ans = map[s[i]];
	}
	return ans;
}
int cmp(string N2, long long radix, long long n1)
{
	long long num = convert_to_number(N2, radix);
	if (num < 0) return 1;
	if (n1 > num) return -1;
	else if (n1 == num) return 0;
	else return 1;
}
long long binary_search(long long n1, string N2, long long left, long long right)
{
	long long mid;
	//long long  result_radix = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, n1);
		if (flag == 0) return mid;
		else if (flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
int main()
{
	for (int i = '0'; i <= '9'; ++i)
		map[i] = i - '0';
	for (int i = 'a'; i <= 'z'; ++i)
		map[i] = i - 'a' + 10;
	string N1, N2;
	int tag;
	int radix;
	cin >> N1 >> N2 >> tag >> radix;
	if (tag == 2)
		swap(N1, N2);
	long long n1 = 0;
	n1 = convert_to_number(N1, radix);
	long long low = find_largest_digit(N2) + 1;
	long long high = max(low, n1) + 1;
	long long result_radix = binary_search(n1, N2, low, high);
	if (result_radix == -1)
		cout << "Impossible";
	else
		cout << result_radix;
}