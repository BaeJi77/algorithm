//  https://www.acmicpc.net/problem/13418
//  13418_학교 탐방하기.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 17..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m,minn,maxx,conNum,p[1004];
bool visited[1004];
queue<pair<int, int>> qu;
vector<pair<int, pair<int, int>>> vt;
vector<vector<pair<int, int>>> map;

void init(){
    memset(visited,0,sizeof(visited));
    map.clear();
    map.resize(n+1);
    for (int i = 1; i<=n; i++) {
        p[i] = i;
    }
}

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

bool Merge(int u , int v){
    int uu = Find(u);
    int vv = Find(v);
    if(uu == vv) return false;
    p[vv] = uu;
    return true;
}

int bfs(int x){
    int ans = 0;
    conNum = 0;
    visited[x] = true;
    qu.push({-1,x});
    while (int s = qu.size()) {
        while (s--) {
            int here = qu.front().second;
            int k = qu.front().first;
            qu.pop();
            
            if(k == 1) {
                ans += conNum*conNum;
                conNum = 0;
            }
            else if(k == 0)conNum++;
            
            for (int i = 0 ; i < map[here].size(); i++) {
                int there = map[here][i].first;
                int nk = map[here][i].second;
                if(visited[there] == false) {
                    qu.push({nk,there});
                    visited[there] = true;
                }
            }
        }
    }
    
    return ans + conNum*conNum;
}

int main(){
    scanf("%d %d" , &n,&m);
    init();
    for (int i = 0 ; i < m+1; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt.push_back({c,{a,b}});
    }
    
    sort(vt.begin(),vt.end());
    for (int i = 0; i < m+1; i++) {
        int w = vt[i].first -1;
        int a=  vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Find(a) == Find(b)) continue;
        Merge(a, b);
        maxx += w;
    }
    
    init();
    reverse(vt.begin(), vt.end());
    for (int i = 0; i < m+1; i++) {
        int w = vt[i].first -1;
        int a=  vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Find(a) == Find(b)) continue;
        Merge(a, b);
        minn += w;
    }

    printf("%d" , maxx*maxx - minn*minn);
}
