//  https://www.acmicpc.net/problem/2843
//  2843_마블.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 14..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int n,q,lastPoint;
bool cycle;
bool visited[300004];
bool finished[300004];
int p[5];
vector<vector<int>> map;

void dfs(int here){
    visited[here] = true;
    if(map[here].size() == 0) lastPoint = here;
    for (int i = 0 ; i < map[here].size(); i++) {
        int next = map[here][i];
        if(visited[next] == false) dfs(next);
    }
}

void existCycle(int here){
    visited[here] = true;
    if(map[here].size() == 0) lastPoint = here;
    for (int i = 0; i<map[here].size(); i++) {
        int there =map[here][i];
        if(visited[there] == false) existCycle(there);
        else if(finished[there]==false) cycle = true;
    }
    finished[here] = true;
}

//int find(int x){
//    if(p[x] == -1) return x;
//    return p[x] = find(p[x]);
//}
//
//bool Merge(int u, int v){
//    int uu = find(u);
//    int vv = find(v);
//
//    if(uu == vv) return false;
//    p[vv] = uu;
//    return true;
//}

int main(){
    scanf("%d" , &n);
    map.resize(n+1);
    memset(p,-1,sizeof(p));
    for (int i = 1; i <= n ; i++) {
        int a;
        scanf("%d" , &a);
        map[i].push_back(a);
        p[i] = a;
    }
    
    scanf("%d" , &q);
    while (q--) {
        int a,b;
        scanf("%d %d" , &a,&b);
        if(a == 1){
            cycle = false;
            lastPoint = 0;
            memset(visited,0,sizeof(visited));
            memset(finished,0, sizeof(finished));
            existCycle(b);
            if(cycle) printf("CIKLUS\n");
            else printf("%d\n" , lastPoint);
        }else if(a == 2){
            p[b] = -1;
            map[b].erase(map[b].begin());
        }
    }
}
