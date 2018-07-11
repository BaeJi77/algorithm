//
//  2146.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int minn = 123456789;

int n,cnt,tcnt;
int color = 2;
int map[110][110];
bool visited[110][110];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
queue<pair<int, int>> qu;


bool isposs(int y,int x){
    return (x>=0)&&(y>=0)&&(x<n)&&(y<n);
}

bool nearZero(int y,int x){
    for (int i = 0; i < 4; i++) {
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        
        if(isposs(yy, xx) && map[yy][xx] == 0) {
            printf("y : %d x : %d\n" , y,x);
            return true;
        }
    }
    return false;
}

void giveNumber(int y, int x, int same){
    visited[y][x] = true;
    map[y][x] = same;
    for (int i = 0 ; i < 4; i++) {
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        
        if(isposs(yy, xx) && visited[yy][xx] == false && map[yy][xx] == 1) {
            giveNumber(yy, xx, color);
        }
    }
}

void bfs(int y, int x, int islandColor){
    qu.push({y,x});
    visited[y][x] = true;
    while (int s = qu.size()) {
        while (s--) {
            int Y = qu.front().first;
            int X = qu.front().second;
            if(map[Y][X] != islandColor && map[Y][X] != 0) return;
            
            for (int i = 0; i < 4; i++) {
                int yy = dy[i] + Y;
                int xx = dx[i] + X;
                if(isposs(yy, xx) && map[yy][xx] != islandColor && visited[yy][xx] == false){
                    qu.push({yy,xx});
                    visited[yy][xx] = true;
                }
            }
        }
        cnt++;
    }
}


//같은 번호를 주고 같은 번호끼리는 신경안쓰고 max를 한번 찾아보자
int main(){
    scanf("%d" , &n);
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j] == false && map[i][j] == 1) {
                giveNumber(i , j , color);
                color++;
            }
        }
    }
    
    //주변에 0이 있으면 bfs시작한다.
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            if(nearZero(i, j)){
                //true라면 bfs를 돌려보자!!
                printf("y %d x %d\n" , i , j);
                memset(visited, 0, sizeof(visited));
                cnt = 0;
                bfs(i,j,map[i][j]);
                if(minn > cnt) minn = min(minn,cnt);
            }
        }
    }
    printf("%d" , minn);
    
}
