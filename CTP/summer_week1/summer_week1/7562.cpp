//
//  7562.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 4..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};
int t,n,a,b,c,d,cnt;
queue<pair<int, int>> qu;
bool visited[310][310];

bool isposs(int y, int x){
    return (x>=0) && (y>=0) && (x<n) && (y<n);
}

void bfs(int y,int x){
    qu.push({y,x});
    visited[y][x] = true;
    while (int s = qu.size()) {
        while (s--) {
            int py = qu.front().first;
            int px = qu.front().second;
            qu.pop();
            if(py == d && px == c) return;
            for (int i = 0; i < 8; i++) {
                int yy = py + dy[i];
                int xx = px + dx[i];
                if(isposs(yy, xx) && visited[yy][xx] == false){
                    qu.push({yy,xx});
                    visited[yy][xx] = true;
                }
            }
        }
        cnt++;
    }
}



int main(){
    scanf("%d" , &t);
    while (t--) {
        scanf("%d" , &n);
        scanf("%d %d",&b,&a);
        scanf("%d %d",&d,&c);
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        while (qu.size() != 0) {
            qu.pop();
        }
        bfs(b,a);
        printf("%d\n" , cnt);
    }
}

