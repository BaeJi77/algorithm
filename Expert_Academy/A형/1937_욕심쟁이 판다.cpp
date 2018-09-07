//  https://www.acmicpc.net/problem/1937
//  1937_욕심쟁이 판다.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 9. 6..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

#define MAX 500
using namespace std;

int N,map[MAX+4][MAX+4],copyM[MAX+4][MAX+4];
int maxx;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

bool isposs(int y,int x){
    return y>=0&&x>=0&&y<N&&x<N;
}

void copyMap(int a[][MAX+4], int b[][MAX+4]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void solve(int y,int x, int pre,int dep,int eachMap[][MAX+4]){
    eachMap[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(isposs(yy, xx) == false) continue;
        if(pre >= eachMap[yy][xx]) continue;
        solve(yy,xx,eachMap[yy][xx],dep+1,eachMap);
    }
    maxx = max(maxx , dep);
    eachMap[y][x] = pre;
}

int main(){
    scanf("%d" , &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d" , &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            copyMap(copyM, map);
            solve(i,j,copyM[i][j],1,copyM);
        }
    }
    printf("%d" , maxx);
    
}
