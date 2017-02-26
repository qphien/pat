#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;


struct MoonCake
{
	double inventory;      //inventory 可能为浮点数，不然会有一个测试点不通过
	double total_profit;
	double profit_per_ton;
};
bool cmp(const MoonCake &a, const MoonCake &b)
{
	return a.profit_per_ton > b.profit_per_ton;
}
int main()
{
	int N, D;
	cin >> N >> D;
	vector<MoonCake> mVec(N);
	for (int i = 0; i != N; ++i)
		scanf("%lf", &mVec[i].inventory);
	for (int i = 0; i != N; ++i)
	{
		scanf("%lf", &mVec[i].total_profit);
		mVec[i].profit_per_ton = mVec[i].total_profit / mVec[i].inventory;
	}
	sort(mVec.begin(), mVec.end(), cmp);
	double total_profit = 0;
	for (int i = 0; D != 0 && i != N; ++i)
	{
		if (mVec[i].inventory >= D)
		{
			total_profit += D * mVec[i].profit_per_ton;
			D = 0;
		}
		else
		{
			total_profit += mVec[i].total_profit;
			D -= mVec[i].inventory;
		}
	}
	printf("%.2lf", total_profit);
}
