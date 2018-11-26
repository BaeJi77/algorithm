//  https://www.acmicpc.net/problem/1261
//  Dijkstra_1261.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 27..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
int map[104][104];
int dist[104][104];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,-1,1};
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, pair<int, int>>> pq;

bool isposs(int y, int x){
    return y>=0&&x>=0&&y<=N-1&&x<=M-1;
}

void dij(){
    pq.push({0,{0,0}});
    while (!pq.empty()) {
        int w = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if(dist[y][x] != -1)
            continue;
        dist[y][x] = w;
        
        for (int i = 0; i < 4; i++) {
            int yy = y+dy[i];
            int xx = x+dx[i];
            int ncost = w + map[yy][xx];
            
            if(isposs(yy, xx) == false) continue;
            if(dist[yy][xx] == -1)
                pq.push({-ncost , {yy,xx}});
        }
    }
}

int main(){
    scanf("%d %d" , &M,&N);
    memset(dist,-1,sizeof(dist));
    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < M; j++) {
            char in = getchar();
            map[i][j] = in-'0';
        }
    }
    
    dij();
    
    printf("%d" , dist[N-1][M-1]);
}
