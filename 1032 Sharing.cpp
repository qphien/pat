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
	node vecNode[100000];                   //Ϊʲôʼ�ճ�ʱ��
											//���һ��flag��ʡȥһ��forѭ��
											//Ϊʲô��vector�ᳬʱ��vector�����Ͼ��Ǽ�ǿ������飬�����������ָ�����ͣ���֪��Ϊʲô
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