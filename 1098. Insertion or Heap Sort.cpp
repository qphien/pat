#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> origin(n);
	vector<int> changed(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &origin[i]);
	for (int i = 0; i != n; ++i)
		scanf("%d", &changed[i]);
	vector<int> t = origin;
	int flag = false;
	int i;
	for (i = 1; i != n; ++i)
	{
		int temp = t[i];
		int j;
		for (j = i; j > 0 && t[j - 1] > temp; --j)
			t[j] = t[j - 1];
		t[j] = temp;
		if (t == changed)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		printf("Insertion Sort\n");
		++i;
		int temp = t[i];
		int j;
		for (j = i; j > 0 && t[j - 1] > temp; --j)
			t[j] = t[j - 1];
		t[j] = temp;
		for (int p = 0; p != n; ++p)
		{
			if (p != 0)
				printf(" ");
			printf("%d", t[p]);
		}
		printf("\n");
	}
	else
	{
		printf("Heap Sort\n");
		make_heap(origin.begin(), origin.end());
		for (int i = 0; i != n; ++i)
		{
			pop_heap(origin.begin(), origin.end() - i);
			if (origin == changed)
			{
				pop_heap(origin.begin(), origin.end() - i - 1);
				for (int p = 0; p != n; ++p)
				{
					if (p != 0)
						printf(" ");
					printf("%d", origin[p]);
				}
				printf("\n");
				return 0;
			}
		}
	}
}