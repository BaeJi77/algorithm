//
//  1976.cpp
//  10week-second
//
//  Created by Hoon on 2018. 5. 11..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

int n;
int a, b, c;
int u, r;
int dist[11000];
vector<vector<pair<int,int>>> vt;

void dfs(int here, int dep) {
    dist[here] = dep;
    if (r < dist[here]) {
        r = dist[here];
        u = here;
    }
    for (auto i : vt[here]) {
        
        int there = i.first;
        int d = i.second;
        if (dist[there] != INF)    continue;
        dfs(there, d + dep);
    }
}
int main() {
    scanf("%d", &n);
    vt.resize(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        vt[a].push_back({ b,c });
        vt[b].push_back({ a,c });
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    r = 0;
    
    dfs(u, 0);
    printf("%d", r);
}
