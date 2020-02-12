//  https://www.acmicpc.net/problem/1753
//  Dijkstra_1753.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 27..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

#define MAX 20000
using namespace std;

int V,E,sp;
int dist[MAX+4];
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

void dij(int start){
    pq.push({0,start});
    while (!pq.empty()) {
        int w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(dist[u] != -1)
            continue;
        
        dist[u] = w;
        for (int i = 0; i < vt[u].size(); i++) {
            int v = vt[u][i].first;
            int nw = vt[u][i].second + w;
            if(dist[v] == -1){
                pq.push({-nw,v});
            }
        }
    }
}

int main(){
    scanf("%d %d",&V,&E);
    scanf("%d" , &sp);
    vt.resize(V+1);
    memset(dist,-1,sizeof(dist));
    for (int i = 0 ; i < E; i++) {
        int a,b,w;
        scanf("%d %d %d" , &a,&b,&w);
        vt[a].push_back({b,w});
    }
    
    dij(sp);
    
    for (int i = 1; i <= V; i++) {
        if(dist[i] == -1)
            cout<<"INF\n";
        else
            printf("%d\n" , dist[i]);
    }
}
