#include <vector>
#include <algorithm>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
struct Node
{
	int next_address;
	int val;
	int address;
	int order = 1000000;
};
bool cmp(const Node &a, const Node &b)
{
	return a.order < b.order;
}
int main()
{
	int head_node, N, K;
	cin >> head_node >> N >> K;
	vector<Node> v(100001);
	for (int i = 0; i != N; ++i)
	{
		int address;
		scanf("%d", &address);
		v[address].address = address;
		scanf("%d %d", &v[address].val, &v[address].next_address);
	}
	int count = 0;
	while (head_node != -1)     //可能存在不是由头结点引出链表的节点，该节点无效，所以要用count计算有效节点
	{
		v[head_node].order = count;
		head_node = v[head_node].next_address;
		++count;
	}
	sort(v.begin(), v.end(), cmp);
	N = count;
	//int next_block_address;
	for (int i = 0; i != N / K; ++i)
	{
		for (int j = (i + 1) * K - 1; j > i * K; --j)
			printf("%05d %d %05d\n", v[j].address, v[j].val, v[j - 1].address);
		printf("%05d %d ", v[i * K].address, v[i * K].val);
		if (i < N / K - 1)
			printf("%05d\n", v[(i + 2) * K - 1].address);
		else
		{
			if (N % K == 0)
				printf("-1\n");
			else
			{
				printf("%05d\n", v[(i + 1) * K].address);
				for (int j = (i + 1) * K; j != N; ++j)
				{
					printf("%05d %d ", v[j].address, v[j].val);
					if (j != N - 1)
						printf("%05d\n", v[j].next_address);
					else
						printf("-1");
				}
			}


		}
	}
}