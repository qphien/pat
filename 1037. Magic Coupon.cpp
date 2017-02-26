#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
//题意表明all number will not exceed 2^30， 所以最终结果可以不用写成vector而直接使用long long 或int
int main()
{
	int NC, NP;
	cin >> NC;
	vector<int> PositiveCoupon, NegativeCoupon, PositiveProduct, NegativeProduct;
	vector<int> result(30, 0);
	for (int i = 0; i != NC; ++i)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
			PositiveCoupon.push_back(temp);
		else
			NegativeCoupon.push_back(temp);
	}
	cin >> NP;
	for (int i = 0; i != NP; ++i)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
			PositiveProduct.push_back(temp);
		else
			NegativeProduct.push_back(temp);
	}
	sort(PositiveCoupon.begin(), PositiveCoupon.end(), greater<int>());
	sort(PositiveProduct.begin(), PositiveProduct.end(), greater<int>());
	sort(NegativeCoupon.begin(), NegativeCoupon.end());
	sort(NegativeProduct.begin(), NegativeProduct.end());
	int max = 0;
	for (int i = 0; i != min(PositiveCoupon.size(), PositiveProduct.size()); ++i)
	{
		long long temp = PositiveCoupon[i] * PositiveProduct[i];
		int t = 0;
		int carry = 0;
		while (temp || carry)
		{
			result[t] += temp % 10 + carry;
			carry = 0;
			if (result[t] >= 10)
			{
				result[t] -= 10;
				carry = 1;
			}
			temp /= 10;
			++t;
		}
		if (t - 1 > max)
			max = t - 1;
	}
	for (int i = 0; i != min(NegativeCoupon.size(), NegativeProduct.size()); ++i)
	{
		long long temp = NegativeCoupon[i] * NegativeProduct[i];
		int t = 0;
		int carry = 0;
		while (temp || carry)
		{
			result[t] += temp % 10 + carry;
			carry = 0;
			if (result[t] >= 10)
			{
				result[t] -= 10;
				carry = 1;
			}
			temp /= 10;
			++t;
		}
		if (t - 1 > max)
			max = t - 1;
	}
	for (int i = max; i >= 0; --i)
		cout << result[i];
}