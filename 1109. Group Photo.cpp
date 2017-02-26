#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
struct person
{
	int height;
	char name[9];
};
bool cmp(const person &a, const person &b)
{
	if (a.height != b.height) return a.height > b.height;
	return strcmp(a.name, b.name) < 0;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector<person> vecPerson(n);
	for (int i = 0; i != n; ++i)
		scanf("%s %d", vecPerson[i].name, &vecPerson[i].height);
	sort(vecPerson.begin(), vecPerson.end(), cmp);
	int number = n - n / k * (k - 1);
	vector<person> temp(number);
	int tallest_index = number / 2;
	temp[tallest_index] = vecPerson[0];
	int flag = 2;
	for (int i = 1; i != number; ++i)
	{
		if (flag % 2 == 0)
			temp[tallest_index - flag / 2] = vecPerson[i];
		else
			temp[tallest_index + flag / 2] = vecPerson[i];
		++flag;
	}
	for (int i = 0; i != temp.size(); ++i)
	{
		if (i != 0)
			printf(" ");
		printf("%s", temp[i].name);
	}
	printf("\n");
	temp.clear();
	temp.resize(n / k);
	for (int i = 0; i != k - 1; ++i)
	{
		int start = number + i * n / k;
		tallest_index = n / k / 2;
		if (!temp.empty())                            //以下可改为函数调用，省的重复上面相同的代码
		{
			temp[tallest_index] = vecPerson[start];
			flag = 2;
			for (int j = start + 1; j != start + n / k; ++j)
			{
				if (flag % 2 == 0)
					temp[tallest_index - flag / 2] = vecPerson[j];
				else
					temp[tallest_index + flag / 2] = vecPerson[j];
				++flag;
			}
			for (int i = 0; i != temp.size(); ++i)
			{
				if (i != 0)
					printf(" ");
				printf("%s", temp[i].name);
			}
		}
		printf("\n");
	}

}
