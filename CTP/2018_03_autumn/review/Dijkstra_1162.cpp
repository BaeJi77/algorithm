//  https://www.acmicpc.net/problem/1162
//  Dijkstra_1162.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 27..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

#define MAX 10000
using namespace std;
typedef long long ll;

ll N,M,K,dist[MAX+4][24];
vector<vector<pair<ll, ll>>> vt;
priority_queue<pair<ll, pair<ll, ll>>> pq;


void dij(){
    pq.push({0,{1,K}});
    while (!pq.empty()) {
        ll w = -pq.top().first;
        ll here = pq.top().second.first;
        ll k = pq.top().second.second;
        pq.pop();
        
        if(dist[here][k] < w)
            continue;
        dist[here][k] = w;
        
        for (ll i = 0; i < vt[here].size(); i++) {
            ll there = vt[here][i].first;
            ll nw = vt[here][i].second + w;
            
            if(dist[there][k] > nw){
                dist[there][k] = nw;
                pq.push({-nw,{there,k}});
            }
            
            if(k > 0 && dist[there][k-1] > w){
                dist[there][k-1] = w;
                pq.push({-w,{there,k-1}});
            }
        }
    }
}

int main(){
    scanf("%lld %lld %lld" , &N,&M,&K);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dist[i][j] = 12345678900;
        }
    }
    vt.resize(N+1);
    for (ll i = 0; i < M; i++) {
        ll a,b,w;
        scanf("%lld %lld %lld" , &a,&b,&w);
        vt[a].push_back({b,w});
        vt[b].push_back({a,w});
    }
    
    dij();
    ll minn = 12345678900;
    for (ll i = 0; i <= K; i++) {
        minn = min(minn , dist[N][i]);
    }
    printf("%lld" , minn);
}
