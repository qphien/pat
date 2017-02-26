#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
	int next_address;
	bool flag;
};
int main()
{
	node vecNode[100000];                   //为什么始终超时？
											//添加一个flag可省去一个for循环
											//为什么用vector会超时？vector本质上就是加强版的数组，其迭代器都是指针类型，不知道为什么
	int address1, address2, N;
	cin >> address1 >> address2 >> N;
	for (int i = 0; i != N; ++i)
	{
		int temp1, temp2;
		char temp;
		cin >> temp1 >> temp >> temp2;
		vecNode[temp1] = { temp2, false };
	}
	int i;
	for (i = address1; i != -1; i = vecNode[i].next_address)
		vecNode[i].flag = true;
	for (i = address2; i != -1; i = vecNode[i].next_address)
		if (vecNode[i].flag == true) break;
	if (i == -1)
		cout << -1;
	else
		cout << setw(5) << setfill('0') << i;
}