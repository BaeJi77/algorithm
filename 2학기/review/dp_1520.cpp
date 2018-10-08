//  https://www.acmicpc.net/problem/1520
//  dp_1520.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 7..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>

#define MAX 500
using namespace std;

int map[MAX+4][MAX+4];
int dp[MAX+4][MAX+4];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int N,M;

bool isposs(int y,int x){
    return y>=0&&x>=0&&y<N&&x<M;
}

int solve(int y,int x){
    if(y==0 && x==0)
        return 1;
    
    int& ret = dp[y][x];
    if(ret != -1)
        return ret;
    
    ret = 0;
    
    for (int i = 0; i < 4; i++) {
        int yy = y+dy[i];
        int xx = x+dx[i];
        
        if(isposs(yy, xx)==false || map[y][x] >= map[yy][xx])
            continue;
        
        ret += solve(yy,xx);
    }
    
    return ret;
}


int main(){
    scanf("%d %d" , &N,&M);
    memset(dp,-1,sizeof(dp));
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d" , &map[i][j]);
        }
    }
    
    printf("%d" , solve(N-1,M-1));
}
