//
//  1162_도로포장.cpp
//  summer_week5-1
//
//  Created by Hoon on 2018. 8. 2..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef long long ll;

ll v,e,k,minn;
ll dist[10004][24];
vector<vector<pair<ll, ll>>> vt;
priority_queue<pair<ll, pair<ll, ll>>> pq;

void dij(){
    pq.push({0,{1,k}});
    while (!pq.empty()) {
        ll cost = -pq.top().first;
        ll here = pq.top().second.first;
        ll road = pq.top().second.second;
        pq.pop();
        
        if(dist[here][road] != -1) continue;
        dist[here][road] = cost;
        
        for (ll i = 0 ; i < vt[here].size(); i++) {
            ll ncost = vt[here][i].second + cost;
            ll there = vt[here][i].first;
            
            if(k > 0 && dist[there][k-1] == -1) pq.push({-cost,{there,road-1}});
            if(dist[there][k] == -1) pq.push({-ncost,{there,road}});
        }
    }
}

int main(){
    scanf("%lld %lld %lld" , &v,&e,&k);
    vt.resize(v+1);
    for (ll i = 0; i < 10004; i++) memset(dist[i],-1,sizeof(dist[i]));
    for (ll i = 0 ; i < e; i++) {
        ll a,b,c;
        scanf("%lld %lld %lld", &a,&b,&c);
        vt[a].push_back({b,c});
        vt[b].push_back({a,c});
    }
    
    dij();
    
    minn = INF;
    for (ll i = 0; i <= k; i++) {
        minn = min(dist[v][i],minn);
    }
    
    printf("%lld" , minn);
}

