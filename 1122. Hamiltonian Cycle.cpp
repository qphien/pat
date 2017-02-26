#include <vector>
#include <iostream>
#include <set>
#pragma warning(disable:4996)
using namespace std;
int n, m;
bool is_cycle(int number, const vector<vector<int>> &graph)
{
	vector<int> v;
	set<int> s;
	for (int i = 0; i != number; ++i)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
		s.insert(temp);
	}
	if (v.front() != v.back() || s.size() != n)
		return false;
	for (int i = 0; i != number - 1; ++i)
	{
		if (!graph[v[i]][v[i + 1]])
			return false;
	}
	return true;
	/*
	int head;          //为什么这么写有一个测试点不能通过
	scanf("%d", &head);
	s.insert(head);
	int front = head;
	for (int i = 1; i != number; ++i)
	{
	int next;
	scanf("%d", &next);
	s.insert(next);
	if (!graph[front][next])
	{
	return false;
	}
	else
	front = next;
	}*/
	/*if (head != front || s.size() != n)
	return false;*/
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	vector<vector<int>> graph(n + 1, vector<int>(n + 1));
	for (int i = 0; i != m; ++i)
	{
		int vertex1, vertex2;
		scanf("%d %d", &vertex1, &vertex2);
		graph[vertex1][vertex2] = graph[vertex2][vertex1] = 1;
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i != k; ++i)
	{
		int number;
		scanf("%d", &number);
		if (number != n + 1)
		{
			int waste;
			for (int j = 0; j != number; ++j)
				scanf("%d", &waste);
			printf("NO\n");
		}
		else
		{
			bool flag = is_cycle(number, graph);
			if (flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}