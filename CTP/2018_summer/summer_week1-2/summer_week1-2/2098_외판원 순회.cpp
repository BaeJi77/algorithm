//  https://www.acmicpc.net/problem/2098
//  2098_외판원 순회.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 8. 21..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 100000000;
int N,W[20][20];
int dp[20][1<<17];

int tsp(int node, int visited){
    if(visited == (1<<N)-1){
        if(W[node][0] != 0)
            return W[node][0];
        else return INF;
    }
    
    int &ret = dp[node][visited];
    if(ret != -1) return ret;
    ret = INF;
    
    for (int i = 0; i < N; i++) {
        if((visited & (1<<i)) == false && W[node][i] != 0){
            ret = min(ret, W[node][i] + tsp(i, visited | (1<<i)));
        }
    }
    
    return ret;
}


int main(){
    scanf("%d" , &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d" , &W[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%d" , tsp(0,1));
}


