//  https://www.acmicpc.net/problem/1238
//  Dijkstra_1238.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 27..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>

#define MAX 1000
using namespace std;

int N,M,X,dist[MAX+4],rdist[MAX+4];
vector<vector<pair<int, int>>> vt;
vector<vector<pair<int, int>>> rvt;
priority_queue<pair<int, int>> pq;

void dij(int start){
    pq.push({0,start});
    while (!pq.empty()) {
        int here = pq.top().second;
        int w = -pq.top().first;
        pq.pop();
        
        if(dist[here] != -1)
            continue;
        dist[here] = w;
        
        for (int i = 0; i < vt[here].size(); i++) {
            int there = vt[here][i].first;
            int nw = vt[here][i].second + w;
            if(dist[there] == -1)
                pq.push({-nw, there});
        }
    }
}

void rdij(int start){
    pq.push({0,start});
    while (!pq.empty()) {
        int here = pq.top().second;
        int w = -pq.top().first;
        pq.pop();
        
        if(rdist[here] != -1)
            continue;
        rdist[here] = w;
        
        for (int i = 0; i < rvt[here].size(); i++) {
            int there = rvt[here][i].first;
            int nw = rvt[here][i].second + w;
            if(rdist[there] == -1)
                pq.push({-nw, there});
        }
    }
}


int main(){
    scanf("%d %d %d" , &N,&M,&X);
    vt.resize(N+1);
    rvt.resize(N+1);
    memset(dist,-1,sizeof(dist));
    memset(rdist,-1,sizeof(rdist));
    for (int i = 0 ; i < M; i++) {
        int a,b,w;
        scanf("%d %d %d", &a,&b,&w);
        vt[a].push_back({b,w});
        rvt[b].push_back({a,w});
    }
    
    dij(X);
    rdij(X);
    
    int MAXX = INT_MIN;
    for (int i = 1; i <= N; i++) {
//        if(dist[i] == -1 || rdist[i] == -1)
//            continue;
        MAXX = max(MAXX , dist[i]+rdist[i]);
    }
    
    printf("%d" , MAXX);
}
