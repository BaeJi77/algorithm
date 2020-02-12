//  https://www.acmicpc.net/problem/13911
//  13911_집 구하기.cpp
//  summer_week5-1
//
//  Created by Hoon on 2018. 8. 1..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int v,e,macNumber , x , staNumber , y , minn;
int macPoss[10004];
int staPoss[10004];
int dist[10004];
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

void dij(int startPoint){
    memset(dist,-1,sizeof(dist));
    pq.push({0,startPoint});
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
    scanf("%d %d" , &v,&e);
    vt.resize(v+4);
    for (int i = 0; i < e; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt[a].push_back({b,c});
        vt[b].push_back({a,c});
    }
    memset(macPoss, -1, sizeof(macPoss));
    memset(staPoss, -1, sizeof(staPoss));
    minn = INT_MAX;

    scanf("%d %d" , &macNumber , &x);
    for (int i = 0; i < macNumber; i++) {
        int a;
        scanf("%d" , &a);
        vt[0].push_back({a,0});
    }
    dij(0);
    for (int i = 1; i <= v; i++) {
        if(dist[i] <= x) {
            macPoss[i] = dist[i];
        }
    }
    

    scanf("%d %d" , &staNumber , &y);
    for (int i = 0; i < staNumber; i++) {
        int a;
        scanf("%d" , &a);
        vt[v+1].push_back({a,0});
    }
    dij(v+1);
    for (int i = 1; i <= v; i++) {
        if(dist[i] <= y) {
            staPoss[i] = dist[i];
        }
    }

    for (int i = 1; i <= v; i++) {
        if(macPoss[i] == -1 || staPoss[i] == -1) continue;
        if(macPoss[i] == 0 || staPoss[i] == 0) continue;
        int sum = macPoss[i] + staPoss[i];
        minn = min(minn , sum);
        
    }

    if(minn == INT_MAX) printf("-1");
    else printf("%d" , minn);
}

