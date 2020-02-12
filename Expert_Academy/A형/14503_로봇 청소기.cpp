//  https://www.acmicpc.net/problem/14503
//  14503_로봇 청소기.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 9. 3..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int N,M,r,c,d,map[54][54],cnt;
int dx[8] = {0,-1,0,1,0,-1,0,1}; // 북 서 남 동
int dy[8] = {-1,0,1,0,-1,0,1,0};
bool visited[54][54];

//int dx[4] = { 0, 1, 0, -1 }; // 북 동 남 서
//int dy[4] = { -1, 0, 1, 0 };


bool isposs(int y,int x){
    return y>=0&&x>=0&&y<N&&x<M;
}

int turnDirection(int d) {
    // 북 서 남 동
    if (d == 0) {
        return 1;
    } else if (d == 3) {
        return 2;
    } else if (d == 2) {
        return 1;
    } else {
        return 0;
    }
}

int FuncnextDirection(int y,int x) {
    if(y==0&&x==1){
        return 3;
    }else if(y==0&&x==-1){
        return 1;
    }else if(y==1&&x==0){
        return 2;
    }else {
        return 0;
    }
}

void dfs(int y, int x,int dd){
    cnt++;
    visited[y][x] = true;
    map[y][x] = cnt;
    
    int newDirection = dd;
    newDirection = turnDirection(newDirection);
    
//    if(dd == 0)
//        newDirection = 0;
//    else if(dd == 1)
//        newDirection = 3;
//    else if(dd == 2)
//        newDirection = 2;
//    else if(dd == 3)
//        newDirection = 1;
    
    for (int i = newDirection; i < newDirection + 4; i++) {
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        
        //        if(y==7 && x ==3)
        //            printf("%d %d\n", yy,xx);
        
        if(isposs(yy, xx) == false) continue;
        if(map[yy][xx] != 0) continue;
        if(visited[yy][xx] == true) continue;
        
        int nextD = FuncnextDirection(dy[i], dx[i]);
        dfs(yy,xx,nextD);
//        if(dy[i] == 0 && dx[i] == 1) // d=1;
//            dfs(yy,xx,1);
//        else if(dy[i] == 0 && dx[i] == -1) //d=3;
//            dfs(yy,xx,3);
//        else if(dy[i] == 1 && dx[i] == 0) //d=2;
//            dfs(yy,xx,2);
//        else if(dy[i] == -1 && dx[i] == 0) //d=0;
//            dfs(yy,xx,0);
    }
}

int main(){
    scanf("%d %d" , &N,&M);
    scanf("%d %d %d" , &r,&c,&d);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d" , &map[i][j]);
        }
    }
    
    cnt = 100;
    
    dfs(r,c,d);
    printf("%d\n" , cnt);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d   " , map[i][j]);
        }
        puts("");
    }
    puts("");
}
