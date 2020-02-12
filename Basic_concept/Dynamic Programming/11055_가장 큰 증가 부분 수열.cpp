//  https://www.acmicpc.net/problem/11055
//  11055_가장 큰 증가 부분 수열.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX 1000
using namespace std;

int N,dp[MAX+4][MAX+4],arr[MAX+4];

int sol(int n,int lastValue){
    if(n == N)
        return 0;
    
    int &ret = dp[n][lastValue];
    if(ret != -1)
        return ret;
    
    ret = sol(n+1 , lastValue);
    if(lastValue < arr[n])
        ret = max(ret , sol(n+1, arr[n]) + arr[n]);

    return ret;
}

int main(){
    scanf("%d" , &N);
    for(int i = 1 ; i <= N ; i++)
        scanf("%d" , &arr[i]);
    
    for(int i = 0 ; i < MAX+4 ; i++)
        memset(dp[i],-1,sizeof(dp[i]));
    
    if(N == 1) printf("%d\n" , arr[1]);
    else printf("%d" , sol(0,0));
}
