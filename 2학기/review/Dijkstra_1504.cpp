//  https://www.acmicpc.net/problem/1504
//  Dijkstra_1504.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 800
using namespace std;

int N,E,p1,p2;
int dist1[MAX+4],dist2[MAX+4],dist3[MAX+4],dist4[MAX+4],dist5[MAX+4],dist6[MAX+4];
bool check1 = false;
bool check2 = false;
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

void dij(int dist[],int sp){
    pq.push({0,sp});
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
            
            if(dist[there] == -1)
                pq.push({-nw,there});
        }
    }
}

void init(){
    vt.resize(N+1);
    memset(dist1,-1,sizeof(dist1));
    memset(dist2,-1,sizeof(dist2));
    memset(dist3,-1,sizeof(dist3));
}

int main(){
    scanf("%d %d" , &N,&E);
    init();
    for (int i = 0; i < E; i++) {
        int a,b,w;
        scanf("%d %d %d" ,&a,&b,&w);
        vt[a].push_back({b,w});
        vt[b].push_back({a,w});
    }
    scanf("%d %d" , &p1,&p2);
    
    dij(dist1,1);
    dij(dist2,p1);
    dij(dist3,p2);
    
    int minn = min(dist1[p1] + dist2[p2] + dist3[N] , dist1[p2] + dist3[p1] + dist2[N]);
    
    if(dist3[N] == -1 || dist2[N] == -1)
        printf("-1");
    else
        printf("%d" , minn);
}
