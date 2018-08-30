//  https://www.acmicpc.net/problem/1912
//  1912_연속합.cpp
//  CTP_summer
//
//  Created by Hoon on 2018. 8. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <climits>

#define MAX 100000

using namespace std;

int N,dp[MAX+4],arr[MAX+4];

int sol(int n){
    if(n == N+1)
        return 0;
    
    int &ret = dp[n];
    if(ret != -1)
        return ret;
    
    ret = sol(n+1) + arr[n];
    ret = max(ret , arr[n]);
    
    return ret;
}

int main(){
    scanf("%d" , &N);
    memset(dp,-1,sizeof(dp));
    for(int i = 1 ; i <= N ; i++)
        scanf("%d" , &arr[i]);
    
    int ans = INT_MIN;
    for (int i = 1; i <= N; i++) {
//        printf("%d %d\n" , i , sol(i));
        ans = max(ans,sol(i));
    }
    
    printf("%d" , ans);
}
