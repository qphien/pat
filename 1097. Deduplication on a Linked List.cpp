#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int maxn = 100005;
struct node
{
	node() : order(2 * maxn) {}
	int address;
	int val;
	int next;
	int order;
};
bool cmp(const node &a, const node &b)
{
	return a.order < b.order;
}
int main()
{
	int head, n;
	scanf("%d %d", &head, &n);
	vector<node> v(100005);
	vector<bool> flag(10001);
	for (int i = 0; i != n; ++i)
	{
		int address;
		scanf("%d", &address);
		v[address].address = address;
		scanf("%d %d", &v[address].val, &v[address].next);
		//v[address].order = 2 * maxn;
	}
	int valid_number = 0;
	int removed_number = 0;
	while (head != -1)
	{
		if (flag[abs(v[head].val)])
			v[head].order = maxn + removed_number++;
		else
		{
			flag[abs(v[head].val)] = true;
			v[head].order = valid_number++;
		}
		head = v[head].next;
	}
	sort(v.begin(), v.end(), cmp);
	int count = removed_number + valid_number;
	for (int i = 0; i != count; ++i)
	{
		if (i != count - 1 && i != valid_number - 1)
			printf("%05d %d %05d\n", v[i].address, v[i].val, v[i + 1].address);
		else
			printf("%05d %d -1\n", v[i].address, v[i].val);
	}
}