#include <iostream>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
struct frac
{
	ll down;
	ll up;
};
ll gcd(ll x, ll y)
{
	ll r = x % y;
	while (r)
	{
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}
frac reduction(frac a)
{
	if (a.down < 0)
	{
		a.up = -a.up;
		a.down = -a.down;
	}
	if (a.up == 0)
		a.down = 1;
	else
	{
		int d = gcd(abs(a.up), abs(a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}
frac add(frac &a, frac &b)
{
	frac c;
	c.up = a.up * b.down + b.up * a.down;
	c.down = a.down * b.down;
	return reduction(c);
}
frac minu(frac &a, frac &b)
{
	frac c;
	c.up = a.up * b.down - b.up * a.down;
	c.down = a.down * b.down;
	return reduction(c);
}
frac multi(frac &a, frac &b)
{
	frac c;
	c.up = a.up * b.up;
	c.down = a.down * b.down;
	return reduction(c);
}
frac divide(frac &a, frac &b)
{
	frac c;
	c.up = a.up * b.down;
	c.down = a.down * b.up;
	return reduction(c);
}
void show_result(frac result)
{
	result = reduction(result);
	if (result.up < 0)
		printf("(");
	if (result.down == 1)
		printf("%lld", result.up);
	else if (abs(result.up) > abs(result.down))
	{
		printf("%lld %lld/%lld", result.up / result.down, abs(result.up) % result.down,
			result.down);
	}
	else
		printf("%lld/%lld", result.up, result.down);
	if (result.up < 0)
		printf(")");
}

int main()
{
	frac a, b;
	scanf("%lld/%lld", &a.up, &a.down);
	scanf("%lld/%lld", &b.up, &b.down);
	show_result(a);
	cout << " + ";
	show_result(b);
	cout << " = ";
	show_result(add(a, b));
	cout << endl;
	show_result(a);
	cout << " - ";
	show_result(b);
	cout << " = ";
	show_result(minu(a, b));
	cout << endl;
	show_result(a);
	cout << " * ";
	show_result(b);
	cout << " = ";
	show_result(multi(a, b));
	cout << endl;
	show_result(a);
	cout << " / ";
	show_result(b);
	cout << " = ";
	if (b.up != 0)
		show_result(divide(a, b));
	else
		cout << "Inf";
	cout << endl;
}