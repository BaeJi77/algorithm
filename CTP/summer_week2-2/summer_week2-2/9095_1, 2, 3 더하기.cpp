//  https://www.acmicpc.net/problem/9095
//  9095_1, 2, 3 더하기.cpp
//  summer_week2-2
//
//  Created by Hoon on 2018. 7. 16..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>

using namespace std;

int N,dp[15];

int sol(int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    
    int &ret = dp[n];
    if(ret != -1)
        return ret;
    
    ret = sol(n-1) + sol(n-2);
    if(n >= 3)
        ret += sol(n-3);
    
    return ret;
}

int main(){
    int test;
    scanf("%d" , &test);
    while (test--) {
        scanf("%d" , &N);
        memset(dp,-1,sizeof(dp));
        
        printf("%d\n" , sol(N));
    }
}

