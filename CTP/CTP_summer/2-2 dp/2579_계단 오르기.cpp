//  https://www.acmicpc.net/problem/2579
//  2579_계단 오르기.cpp
//  CTP_summer
//
//  Created by Hoon on 2018. 8. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <climits>
#include <algorithm>

#define NMAX 300
#define SMAX 10000
using namespace std;

int N,dp[NMAX+4][5],score[NMAX+4];

int sol(int n, int continuity){
    if(n < 0)
        return INT_MIN;
    
    if(n == 0)
        return 0;
    
    if(continuity == 3)
        return INT_MIN;
    
    int &ret = dp[n][continuity];
    if(ret != -1)
        return ret;
    
    ret = max (sol(n-2, 1),sol(n-1,continuity+1));
    ret += score[n];
    return ret;
}

int main(){
    scanf("%d" , &N);
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= N; i++) {
        scanf("%d" , &score[i]);
    }
    
    printf("%d" , sol(N,1));
}
