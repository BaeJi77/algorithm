//
//  1162_도로포장.cpp
//  summer_week5-1
//
//  Created by Hoon on 2018. 8. 2..
//  Copyright © 2018년 Hoon. Aint rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 123456789001
using namespace std;

typedef long long ll;

int v,e,k;
ll minn;
ll dist[10004][24];
vector<vector<pair<int, int>>> vt;
priority_queue<pair<ll, pair<int, int>>> pq;

void dij(){
    pq.push({0,{1,k}});
    while (!pq.empty()) {
        ll cost = -pq.top().first;
        int here = pq.top().second.first;
        int road = pq.top().second.second;
        pq.pop();
        
        if(dist[here][road] < cost) continue;
        dist[here][road] = cost;
        
        for (int i = 0 ; i < vt[here].size(); i++) {
            ll ncost = vt[here][i].second + cost;
            int there = vt[here][i].first;
            
            if(road > 0 && dist[there][road-1] > cost)
                dist[there][road-1] = cost;
                pq.push({-cost,{there,road-1}});
            if(dist[there][road] > ncost)
                dist[there][road] = ncost;
                pq.push({-ncost,{there,road}});
        }
    }
}

int main(){
    scanf("%d %d %d" , &v,&e,&k);
    vt.resize(v+1);
    for (int i = 0; i < 10004; i++) {
        for (int j = 0; j < 24; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0 ; i < e; i++) {
        int a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        vt[a].push_back({b,c});
        vt[b].push_back({a,c});
    }
    
    dij();
    
    minn = INF;
    for (int i = 0; i <= k; i++) {
        minn = min(dist[v][i] , minn);
    }
    
    printf("%lld" , minn);
}

