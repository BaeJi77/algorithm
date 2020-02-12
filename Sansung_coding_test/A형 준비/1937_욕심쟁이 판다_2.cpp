//
//  1937_욕심쟁이 판다_2.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 9. 7..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX 500
using namespace std;

int N,map[MAX+4][MAX+4],dp[MAX+4][MAX+4];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int solve(int y,int x){
    int &ret = dp[y][x];
    if(ret != -1)
        return ret;
    
    ret = 1;
    for (int i = 0; i < 4; i++) {
        int yy = y+dy[i];
        int xx = x+dx[i];
        
        if(map[y][x] < map[yy][xx])
            ret = max(ret, solve(yy, xx)+1);
    }
    
    return ret;
}

int main(){
    scanf("%d" , &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d" , &map[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    
    int ans=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = max(ans,solve(i,j));
        }
    }
    
    printf("%d" , ans);
}
