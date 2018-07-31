//
//  1238_파티.cpp
//  summer_week5-1
//
//  Created by Hoon on 2018. 7. 30..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int v,e,startPoint;
int dist[1004];
int rdist[1004];
vector<vector<pair<int, int>>> vt;
vector<vector<pair<int, int>>> rvt;
priority_queue<pair<int, int>> pq;

void rdij(int start){
    pq.push({0,start});
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(rdist[here] != -1) continue;
        rdist[here] = cost;

        for (int i = 0; i < rvt[here].size(); i++) {
            int there = rvt[here][i].first;
            int ncost = rvt[here][i].second + cost;
            if(rdist[there] == -1) pq.push({-ncost,there});
        }
    }
}

void dij(int start){
    pq.push({0,start});
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
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

int main(){
    scanf("%d %d %d" , &v,&e,&startPoint);
    vt.resize(v+1);
    rvt.resize(v+1);
    memset(dist,-1,sizeof(dist));
    memset(rdist,-1,sizeof(rdist));
    for (int i = 0; i < e; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt[a].push_back({b,c});
        rvt[b].push_back({a,c});
    }

    rdij(startPoint);
    dij(startPoint);
    int maxx = 0;
    for (int i = 1; i <= v; i++) {
        int tempSum = dist[i] + rdist[i];
        maxx = max(maxx , tempSum);
    }
    printf("%d" , maxx);
}

