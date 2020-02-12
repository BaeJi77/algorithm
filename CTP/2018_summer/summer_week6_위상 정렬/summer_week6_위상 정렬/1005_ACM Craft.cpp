//  https://www.acmicpc.net/problem/1005
//  1005_ACM Craft.cpp
//  summer_week6_위상 정렬
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int test,n,m,goal;
int in[1004];
int cost[1004];
int preCost[1004];
vector<vector<int>> vt;
priority_queue<int> pq;


int main(){
    scanf("%d" , &test);
    while (test--) {
        memset(in,0,sizeof(in));
        memset(cost,0,sizeof(cost));
        memset(preCost,0,sizeof(preCost));
        scanf("%d %d" , &n,&m);
        vt.clear();
        vt.resize(n+1);
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d" , &a);
            cost[i] = a;
            preCost[i] = a;
        }
        
        for (int i = 0; i < m; i++) {
            int a,b;
            scanf("%d %d", &a,&b);
            vt[a].push_back(b);
            in[b]++;
        }
        
        scanf("%d" , &goal);
        
        for (int i = 1; i <= n; i++) {
            if(in[i] == 0) pq.push(-i);
        }
        
        while (!pq.empty()) {
            int here = -pq.top();
            pq.pop();
            
            for (int i = 0; i < vt[here].size(); i++) {
                int there = vt[here][i];
                preCost[there] = max(preCost[there] , preCost[here] + cost[there]);
                
                in[there]--;
                if(in[there] == 0) pq.push(-there);
            }
        }
        
        printf("%d\n",preCost[goal]);
    }
}
