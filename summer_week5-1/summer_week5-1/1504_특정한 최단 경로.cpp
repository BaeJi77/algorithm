//  https://www.acmicpc.net/problem/1504
//  1504_특정한 최단 경로.cpp
//  summer_week5-1
//
//  Created by Hoon on 2018. 8. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n,e,p1,p2,minn;
int dist1[804];
int dist2[804];
int dist3[804];
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

void dij(int start , int dist[]){
    pq.push({0,start});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(dist[here] != -1) continue;
        dist[here] = cost;
        
        for (int i = 0; i < vt[here].size(); i++) {
            int there = vt[here][i].first;
            int ncost = vt[here][i].second + cost;
            
            if(dist[there] == -1) pq.push({-ncost,there});
        }
    }
}

void init(){
    memset(dist1,-1,sizeof(dist1));
    memset(dist2,-1,sizeof(dist2));
    memset(dist3,-1,sizeof(dist3));
    vt.resize(n+1);
}

int main(){
    scanf("%d %d" , &n,&e);
    init();
    for (int i = 0; i < e; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vt[a].push_back({b,c});
        vt[b].push_back({a,c});
    }
    scanf("%d %d" ,&p1,&p2);
    
    
    dij(1,dist1);
    dij(p1,dist2);
    dij(p2,dist3);
    
    minn = min(dist1[p1] + dist2[p2] + dist3[n] , dist1[p2] + dist3[p1] + dist2[n] );
    
    if(dist3[n] == -1 || dist2[n] == -1) printf("-1");
    else printf("%d" , minn);
}
