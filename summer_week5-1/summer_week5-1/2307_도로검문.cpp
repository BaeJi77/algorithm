//
//  2307_도로검문.cpp
//  summer_week5-1
//
//  Created by Hoon on 2018. 7. 31..
//  Copyright © 2018년 Hoon. All rights reserved.
//  1. 내가 한 방법 -> 모든 경로를 하나씩 막아본다. (간선이 적으면 -> 시간복잡도가 큼)
//  2. 최단 경로만을 알아내서 그것만을 막는다. (간선이 많이지면)

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int v,e,baseValue,maxx,inf;
int dist[1004];
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> line;

void dij(int es, int ee){
    memset(dist,-1,sizeof(dist));
    pq.push({0,1});
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[here] != -1) continue;
        dist[here] = cost;

        for (int i = 0; i < vt[here].size(); i++) {
            int there = vt[here][i].first;
            int ncost = vt[here][i].second + cost;
            if(here == es && there == ee) continue;
            if(dist[there] == -1) pq.push({-ncost, there});
        }
    }
}

int main(){
    scanf("%d %d" , &v , &e);
    vt.resize(v+1);
    for (int i = 0; i < e; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt[a].push_back({b,c});
        line.push_back({a,b});
    }

    dij(0,0);
    baseValue = dist[v];

    for (int i = 0; i < line.size(); i++) {
        int es = line[i].first;
        int ee = line[i].second;
        dij(es,ee);
        if(dist[v] == -1) {
            inf = 1;
            break;
        }
        int temp = dist[v] - baseValue;
        maxx = max(maxx,temp);
    }

    if(inf == 1) printf("-1");
    else printf("%d" , maxx);
}


