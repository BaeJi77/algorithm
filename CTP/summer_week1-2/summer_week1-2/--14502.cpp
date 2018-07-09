//
//  14502.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 7. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,maxx,cnt,wallcnt;
int map[10][10];
int exe[10][10];
bool visited[10][10];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void copyMap(){
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            exe[i][j] = map[i][j];
        }
    }
}

bool isposs(int y, int x){
    return (x>=0) && (y>=0) && (x<m) && (y<n);
}

void dfs(int y, int x){
    exe[y][x] = 2;
    visited[y][x] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(isposs(yy, xx) && exe[yy][xx] == 0 && visited[yy][xx] == false) dfs(yy,xx);
    }
}

int countCnt(){
    cnt=0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0 ; i < n; i++) {
        for (int j =0; j < m; j++) {
            if(exe[i][j] == 2 && visited[i][j] == false){
                dfs(i,j);
            }
        }
    }
    
    for (int i = 0 ; i < n; i++) {
        for (int j =0; j < m; j++) {
            printf("%d " ,exe[i][j] );
        }
        puts("");
    }
    puts("");

    int safe = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = 0 ; j < m; j++) {
            if(exe[i][j] == 0) safe++;
        }
    }

    return n*m-cnt-(wallcnt+3);
}

void check(int (*exe)[10] , int dep){
    if(dep == 3){
        int checkCnt = countCnt();
        maxx = max(maxx,checkCnt);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j =0; j < m; j++) {
            if(exe[i][j] == 0){
                exe[i][j] = 1;
                check(exe,dep+1);
                exe[i][j] = 0;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            exe[i][j] = map[i][j];
            if(map[i][j] == 1) wallcnt++;
        }
    }
    
    //벽의 위치 지정 -> dfs로 감염한 지역 늘리기 -> 안전지역 구하기(0의 수 구하기)
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copyMap();
            if(exe[i][j] == 0){
                exe[i][j] = 1;
                check(exe,1);
                exe[i][j] = 0;
            }
        }
    }
    printf("%d" , maxx);
}

