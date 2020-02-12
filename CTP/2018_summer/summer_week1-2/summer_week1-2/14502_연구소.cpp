//  https://www.acmicpc.net/problem/14502
//  14502_연구소.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 8. 21..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m,maxx,map[10][10],temp[10][10];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isposs(int y,int x){
    return y>=0&&x>=0&&y<n&&x<m;
}

void copyMap(int (*a)[10] , int (*b)[10]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

int dfs(){
    int go[10][10];
    bool visited[10][10];
    for(int i = 0 ; i < n ; i++) memset(visited,0,sizeof(visited));
    copyMap(go, temp);
    queue<pair<int , int>> qu;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(go[i][j] == 2) {
                qu.push({i,j});
                visited[i][j] = true;
            }
        }
    }
    
    while (!qu.empty()) {
        int y = qu.front().first;
        int x = qu.front().second;
        qu.pop();
        
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(isposs(yy, xx) && visited[yy][xx] == false && go[yy][xx] == 0){
                qu.push({yy,xx});
                visited[yy][xx] = true;
                go[yy][xx] = 2;
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(go[i][j] == 0) cnt++;
        }
    }
    
    return cnt;
}

void recu(int dep){
    if(dep == 3){
        int count = dfs();
        maxx = max(maxx , count);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(temp[i][j] == 0){
                temp[i][j] = 1;
                recu(dep+1);
                temp[i][j] = 0;
            }
        }
    }
}

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <m; j++) {
            scanf("%d" , &map[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j =0; j < m; j++) {
            copyMap(temp,map);
            if(temp[i][j] == 0){
                temp[i][j] = 1;
                recu(1);
                temp[i][j] = 0;
            }
        }
    }
    
    printf("%d" , maxx);
}
