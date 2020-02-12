//
//  2146.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int n,cnt,minn;
int map[104][104];
bool visited[104][104];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int, int>> qu;

bool isposs(int y, int x){
    return (x>=0)&&(y>=0)&&(x<n)&&(y<n);
}

bool nearSea(int y,int x){
    for (int i = 0; i < 4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(isposs(yy, xx) && map[yy][xx] == 0){
            return true;
        }
    }
    return false;
}


void giveNumber(int y, int x,int color){
    visited[y][x] = true;
    map[y][x] = color;
    for (int i = 0; i < 4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(isposs(yy, xx) && map[yy][xx] == 1 && visited[yy][xx] == false){
            giveNumber(yy, xx, color);
        }
    }
}

void bfs(int y, int x , int color){
    cnt = 0;
    visited[y][x] = true;
    qu.push({y,x});
    while (int s = qu.size()) {
        while (s--) {
            int Y = qu.front().first;
            int X = qu.front().second;
            qu.pop();
            
//            if(map[Y][X] != color && map[Y][X] != 0) {
//                return;
//            }
            
            for (int i = 0; i < 4; i++) {
                int yy = Y + dy[i];
                int xx = X + dx[i];
                
                if(map[Y][X] != color && map[Y][X] != 0) {
                    return;
                }
                
                if(isposs(yy, xx) == false) continue;
                if(map[yy][xx] == 0 && visited[yy][xx] == false){
                    visited[yy][xx] = true;
                    qu.push({yy,xx});
                }
            }
        }
        cnt++;
    }
}


void init(){
    scanf("%d" , &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            scanf("%d" , &map[i][j]);
        }
    }
}

int main(){
    init();
    
    int color = 1;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            if(visited[i][j] == false && map[i][j] == 1){
                color++;
                giveNumber(i,j,color);
            }
        }
    }
    
    minn = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            memset(visited,0,sizeof(visited));
            if(nearSea(i, j) && map[i][j] != 0){

                int color = map[i][j];
                bfs(i, j, color);
                minn = min(cnt,minn);
            }
        }
    }
    
    printf("%d\n" , minn);

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%d ", map[i][j]);
//        }
//        puts("");
//    }
}

