#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
struct Station
{
	double price;
	double distance;
};
bool cmp(Station a, Station b)
{
	return a.distance < b.distance;
}
class ToFill
{
private:
	double Cmax;
	double D;
	double Davg;
	int N;
	vector<Station> vecStation;
public:
	void get_data();
	void compute();
};
void ToFill::get_data()
{
	cin >> Cmax >> D >> Davg >> N;
	vecStation.resize(N + 1);
	vecStation[N] = { 0, D };
	for (int i = 0; i != N; ++i)
	{
		cin >> vecStation[i].price >> vecStation[i].distance;
	}
}
void ToFill::compute()
{
	sort(vecStation.begin(), vecStation.end(), cmp);
	if (vecStation[0].distance != 0)
	{
		cout << "The maximum travel distance = 0.00" << flush;
		return;
	}
	int now = 0;
	double largest_distance = Cmax * Davg;
	double nowTank = 0, result_price = 0;
	while (now < N + 1)
	{
		double min_price = (1 << 31) - 1;
		int k = -1;
		double need;
		for (int i = now + 1; i != N + 1 && vecStation[i].distance - vecStation[now].distance <= largest_distance
			; ++i)
		{
			if (vecStation[i].price < min_price)
			{
				min_price = vecStation[i].price;
				k = i;
			}
			if (min_price < vecStation[now].price)
				break;
		}
		if (k == -1)
			break;
		need = (vecStation[k].distance - vecStation[now].distance) / Davg;
		if (min_price < vecStation[now].price)
		{
			if (nowTank < need)
			{
				result_price += (need - nowTank) * vecStation[now].price;
				nowTank = 0;
			}
			else
				nowTank -= need;
		}
		else
		{
			result_price += (Cmax - nowTank) * vecStation[now].price;
			nowTank = Cmax - need;
		}
		now = k;
	}
	if (now == N)
		cout << fixed << setprecision(2) << result_price << flush;
	else
		cout << "The maximum travel distance = " << fixed << setprecision(2) << vecStation[now].distance + largest_distance;
}
int main()
{
	ToFill tf;
	tf.get_data();
	tf.compute();
}