#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

struct mouse
{
	int weight;
	int rank;
};

int main()
{
	int Np, Ng;
	cin >> Np >> Ng;
	vector<mouse> vecMouse(Np);
	for (int i = 0; i != Np; ++i)
		scanf("%d", &vecMouse[i].weight);
	queue<int> que;
	for (int i = 0; i != Np; ++i)
	{
		int temp;
		scanf("%d", &temp);
		que.push(temp);
	}
	int group, temp = Np;
	while (que.size() != 1)
	{
		if (temp % Ng == 0)
			group = temp / Ng;
		else
			group = temp / Ng + 1;

		for (int i = 0; i != group; ++i)
		{
			int max_mice_index = que.front();
			for (int j = 0; j != Ng; ++j)
			{
				if (i * Ng + j >= temp) break;
				int front = que.front();
				if (vecMouse[front].weight > vecMouse[max_mice_index].weight)
					max_mice_index = front;
				vecMouse[front].rank = group + 1;
				que.pop();
			}
			que.push(max_mice_index);
		}
		temp = group;
	}
	vecMouse[que.front()].rank = 1;
	printf("%d", vecMouse[0].rank);
	for (int i = 1; i != Np; ++i)
		printf(" %d", vecMouse[i].rank);
}