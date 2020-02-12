//  https://www.acmicpc.net/problem/2206
//  2206_벽 부수고 이동하기.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 8. 21..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int N,M,map[1004][1004];
int Y[4] = {1,-1,0,0};
int X[4] = {0,0,1,-1};
queue<pair<int, pair<int, int>>> qu;

bool isposs(int y, int x){
    return x>=1&&y>=1&&x<=M&&y<=N;
}

int bfs(int y, int x,int firstCnt){
    int cnt = 0;
    bool visited[1004][1004][2];
    
    qu.push({firstCnt,{y,x}});
    visited[y][x][firstCnt] = true;
    
    while (int s = qu.size()) {
        while (s--) {
            int crashed = qu.front().first;
            int yy = qu.front().second.first;
            int xx = qu.front().second.second;
            qu.pop();
            
            if(yy == N && xx == M) return cnt+1;
            
            for (int i = 0; i < 4; i++) {
                int dy = yy + Y[i];
                int dx = xx + X[i];
                if(isposs(dy, dx) == false) continue;
                
                if(map[dy][dx] == 1 && crashed > 0 && visited[dy][dx][crashed-1] == false){
                    qu.push({crashed - 1,{dy,dx}});
                    visited[dy][dx][crashed-1] = true;
                }
                if(map[dy][dx] == 0 && visited[dy][dx][crashed] == false) {
                    qu.push({crashed , {dy,dx}});
                    visited[dy][dx][crashed] = true;
                }
            }
        }
        cnt++;
    }
    
    return INT_MAX;
}

int main(){
    scanf("%d %d" , &N,&M);
    for (int i = 1; i <= N; i++) {
        getchar();
        for (int j = 1; j <= M; j++) {
            int ch = getchar();
            map[i][j] = ch - '0';
        }
    }

    int ans = bfs(1,1,1);
    
    if(ans == INT_MAX) printf("-1");
    else printf("%d" , ans);
}
