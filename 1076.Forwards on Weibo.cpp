//
//  main.cpp
//  HelloWorld
//
//  Created by Dummy on 2016/11/3.
//  Copyright © 2016年 Dummy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N, L;
    scanf("%d%d", &N, &L);
    vector<vector<int>> graph(N+1);
    for(int i = 1; i != N + 1; ++i)
    {
        int number;
        int temp;
        scanf("%d", &number);
        for(int j = 0 ; j != number; ++j)
        {
            scanf("%d", &temp);
            graph[temp].push_back(i);
        }
    }
    int query;
    scanf("%d", &query);
    vector<bool> collected(N+1);
    for(int i = 0; i != query; ++i)
    {
        int user;
        int result_number = 0;
        int layer = 0;
        vector<bool> collected(N+1);
        scanf("%d", &user);
        int header = user;
        int tail;
        queue<int> que;
        que.push(user);
        collected[user] = true;
        while(!que.empty())
        {
            int t = que.front();
            que.pop();
            for(int i = 0; i != graph[t].size(); ++i)
            {
                if(collected[graph[t][i]] == false)
                {
                    ++result_number;
                    que.push(graph[t][i]);
                    collected[graph[t][i]] = true;
                    tail = graph[t][i];
                }
            }
            if(header == t)
            {
                header = tail;
                ++layer;
            }
            if(layer == L)
                break;
            
        }
        printf("%d\n", result_number);
    }
}
