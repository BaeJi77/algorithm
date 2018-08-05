//  https://www.acmicpc.net/problem/9370
//  9370_미확인 도착지.cpp
//  summer_week5-1
//
//  Created by Hoon on 2018. 8. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int test,n,m,t,s,g,h;
int dist1[2004];
int dist2[2004];
int dist3[2004];
vector<int> ans;
vector<int> des;
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

void dij(int start,int dist[]){
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
            
            if(dist[there] == -1 ) pq.push({-ncost,there});
        }
    }
}

void init(){
    ans.clear();
    vt.clear();
    vt.resize(n+1);
    memset(dist1,-1,sizeof(dist1));
    memset(dist2,-1,sizeof(dist2));
    memset(dist3,-1,sizeof(dist3));
}

int main(){
    scanf("%d" , &test);
    while (test--) {
        scanf("%d %d %d" , &n,&m,&t);
        scanf("%d %d %d" , &s,&g,&h);
        init();
        
        for (int i = 0; i < m; i++) {
            int a,b,c;
            scanf("%d %d %d", &a,&b,&c);
            vt[a].push_back({b,c});
            vt[b].push_back({a,c});
        }
        for (int i = 0; i < t; i++) {
            int a;
            scanf("%d" , &a);
            des.push_back(a);
        }
        
        dij(s,dist1);
        dij(g,dist2);
        dij(h,dist3);
        
        for (int i = 0; i < des.size(); i++) {
            int destination = des[i];
            // s->g->h->destination
            if(dist1[g] + dist2[h] + dist3[destination] == dist1[destination]) {
                ans.push_back(destination);
            }// s->h->g->destination
            else if(dist1[h] + dist3[g] + dist2[destination] == dist1[destination]){
                ans.push_back(destination);
            }
        }
        sort(ans.begin(), ans.end());
        
        if(ans.size() != 0){
            for (int i = 0; i < ans.size(); i++) {
                printf("%d " , ans[i]);
            }
            puts("");
        }
    }
}

