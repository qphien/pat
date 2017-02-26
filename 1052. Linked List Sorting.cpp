#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
	int address;
	int key;
	int next;
	bool flag = false;
};
bool cmp(const node &a, const node &b)    //可能有节点不在链表中需考虑
{
	if (a.flag == false || b.flag == false)
		return a.flag > b.flag;
	else
		return a.key < b.key;
}
int main()
{
	int N, head;
	cin >> N >> head;
	vector<node> v(100000);
	for (int i = 0; i != N; ++i)
	{
		int address;
		cin >> address;
		cin >> v[address].key >> v[address].next;
		v[address].address = address;
	}
	int p = head;
	int count = 0;
	while (p != -1)
	{
		v[p].flag = true;
		p = v[p].next;
		++count;
	}
	if (count == 0)
		cout << "0 -1";
	else
	{
		sort(v.begin(), v.end(), cmp);
		printf("%d %05d\n", count, v[0].address);
		for (int i = 0; i != count - 1; ++i)
			printf("%05d %d %05d\n", v[i].address, v[i].key, v[i + 1].address);
		printf("%05d %d %d", v[count - 1].address, v[count - 1].key, -1);
	}
}