#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int n;
	cin >> n;
	char a[100], b[100];
	bool flag = false;
	int count = 0;
	double sum = 0;
	for (int i = 0; i != n; ++i)
	{
		double temp;
		flag = false;
		scanf("%s", a);
		sscanf(a, "%lf", &temp);
		sprintf(b, "%.2lf", temp);
		for (int j = 0; j != strlen(a); ++j)
		{
			if (a[j] != b[j])
			{
				flag = true;
				break;
			}
		}
		if (flag || temp < -1000 || temp > 1000)
			printf("ERROR: %s is not a legal number\n", a);
		else
		{
			++count;
			sum += temp;
		}
	}
	if (count == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if (count == 1)
		printf("The average of 1 number is %.2lf\n", sum);
	else
		printf("The average of %d numbers is %.2lf\n", count, sum / count);
}