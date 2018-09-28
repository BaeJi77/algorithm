//  https://www.acmicpc.net/problem/2307
//  Dijkstra_2307.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 27..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 1000
using namespace std;

int N,M,dist[MAX+4];
int base;
vector<pair<int , int>> line;
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

int dij(int sp,int ep){
    memset(dist,-1,sizeof(dist));
    pq.push({0,1});
    while (!pq.empty()) {
        int w = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(dist[here] != -1)
            continue;
        dist[here] = w;
        
        for (int i = 0; i < vt[here].size(); i++) {
            int there = vt[here][i].first;
            int nw = vt[here][i].second + w;
            if(here == sp && there == ep)
                continue;
            
            if(dist[there] == -1)
                pq.push({-nw,there});
        }
    }
    return dist[N];
}

int main(){
    scanf("%d %d" , &N,&M);
    vt.resize(N+1);
    memset(dist,-1,sizeof(dist));
    for (int i = 0; i < M; i++) {
        int a,b,w;
        scanf("%d %d %d" , &a,&b,&w);
        vt[a].push_back({b,w});
        line.push_back({a,b});
    }
    base = dij(-1,-1);
    
    int maxx = 0;
    bool good = false;
    for (int i = 0; i < M; i++) {
        int from = line[i].first;
        int to = line[i].second;
        
        int result = dij(from,to);
        
        if(result == -1)
            good = true;
        
        maxx = max(maxx , result);
    }
    
    if(good == true) printf("-1");
    else printf("%d" , maxx-base);
}
