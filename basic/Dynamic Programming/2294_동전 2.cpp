//  https://www.acmicpc.net/problem/2294
//  2294_동전 2.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 26..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
#define IMPOSSBLE 10000000
using namespace std;

int coin[104],N,K;
int dp[104][10004];

int sol(int coinNumber, int cost){
    if(coinNumber == N){
        if(cost == 0) return 0;
        else return IMPOSSBLE;
    }
    
    if(dp[coinNumber][cost] != -1) return dp[coinNumber][cost];
    
    int result = sol(coinNumber+1 , cost);
    if(cost >= coin[coinNumber]) result = min(result, sol(coinNumber, cost-coin[coinNumber])+1);
    
    return dp[coinNumber][cost] = result;
}


int main(){
    scanf("%d %d" , &N,&K);
    for (int i = 0; i < N; i++) {
        scanf("%d" , &coin[i]);
    }
    for(int i = 0 ; i < 104 ; i++) memset(dp[i],-1,sizeof(dp[i]));
    
    
    int result = sol(0,K);
    if(result == IMPOSSBLE) printf("-1\n");
    else printf("%d" , result);
}
