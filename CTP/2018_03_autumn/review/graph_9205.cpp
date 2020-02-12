//  https://www.acmicpc.net/problem/9205
//  graph_9205.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <cstring>
#include <cmath>


using namespace std;

int N;
bool visited[32770];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
vector<pair<int, int>> vt;
vector<vector<int>> map;
queue<int> qu;

bool bfs(int p){
    qu.push(p);
    visited[p] = true;
    while (int s = qu.size()) {
        while (s--) {
            int here = qu.front();
            qu.pop();
            
            if(here == N+1)
                return true;
            
            for (int i = 0; i < map[here].size(); i++) {
                int there = map[here][i];
                if(visited[there] == false){
                    qu.push(there);
                    visited[there] = true;
                }
            }
        }
    }
    return false;
}



int main(){
    int test;
    scanf("%d" , &test);
    while (test--) {
        scanf("%d" , &N);
        vt.clear();
        map.clear();
        map.resize(N+2);
        memset(visited,0,sizeof(visited));
        while (!qu.empty()) {
            qu.pop();
        }
        for (int i = 0; i < N+2; i++) {
            int a,b;
            scanf("%d %d" , &a,&b);
            vt.push_back({a,b});
        }
        
        for (int i = 0; i < N+2; i++) {
            for (int j = i+1; j < N+2; j++) {
                
                if((abs(vt[i].first-vt[j].first)+abs(vt[i].second-vt[j].second)) <= 1000){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        bool result = bfs(0);
        if(visited[N+1])
            printf("happy\n");
        else
            printf("sad\n");
    }
}
