//  https://www.acmicpc.net/problem/9465
//  9465_스티커.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 26..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAX 100000
using namespace std;

int sticker[2][MAX+4], dp[MAX+4][3],n;

int f(int col, int status){
    if(col == n) return 0;
    if(dp[col][status] != -1) return dp[col][status];
    
    int result = f(col+1 , 0);
    if(status != 1) result = max(result, f(col+1 , 1) + sticker[0][col]);
    if(status != 2) result = max(result, f(col+1 , 2) + sticker[1][col]);
    
    return dp[col][status] = result;
}

void init(){
    for(int i = 0 ; i < 2 ; i++) memset(sticker[i],0,sizeof(sticker[i]));
    for(int i = 0 ; i < MAX+4 ; i++) memset(dp[i] , -1,sizeof(dp[i]));
}

int main(){
    int test;
    scanf("%d", &test);
    while (test--) {
        scanf("%d" , &n);
        init();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d" , &sticker[i][j]);
            }
        }
        
        printf("%d\n" , f(0, 0));
    }
}
