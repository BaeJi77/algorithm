//  https://www.acmicpc.net/problem/1600
//  1600_말이 되고픈 원숭이.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 9. 4..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

int W,H,K,map[204][204];
bool visited[204][204][34];
queue<pair<int, pair<int, int>>> qu;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int hy[8] = {1,1,2,2,-1,-1,-2,-2};
int hx[8] = {2,-2,1,-1,-2,2,1,-1};

bool isposs(int y,int x){
    return y>=0&&x>=0&&y<H&&x<W;
}

int bfs(int y,int x,int k){
    int cnt = 0;
    visited[y][x][k] = true;
    qu.push({k,{y,x}});
    while (int s = qu.size()) {
        while (s--) {
            int kk = qu.front().first;
            int Y = qu.front().second.first;
            int X = qu.front().second.second;
            qu.pop();
            
            if(Y == H-1 && X == W-1)
                return cnt;
            
            for (int i = 0; i < 4; i++) {
                int yy = dy[i] + Y;
                int xx = dx[i] + X;
                
                if(isposs(yy, xx) == false) continue;
                if(map[yy][xx] == 1) continue;
                if(visited[yy][xx][kk] == true) continue;
                qu.push({kk,{yy,xx}});
                visited[yy][xx][kk] = true;
            }
            
            if(kk > 0){
                for (int i = 0; i < 8; i++) {
                    int yy = hy[i] + Y;
                    int xx = hx[i] + X;
                    
                    if(isposs(yy, xx) == false) continue;
                    if(map[yy][xx] == 1) continue;
                    if(visited[yy][xx][kk-1] == true) continue;
                    qu.push({kk-1,{yy,xx}});
                    visited[yy][xx][kk-1] = true;
                }
            }
        }
        cnt++;
    }
    
    return -1;
}

int main(){
    scanf("%d" , &K);
    scanf("%d %d" , &W,&H);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d" , &map[i][j]);
        }
    }
    
    printf("%d" , bfs(0,0,K));
}

