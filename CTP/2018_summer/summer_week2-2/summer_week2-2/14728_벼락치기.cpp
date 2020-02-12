//  https://www.acmicpc.net/problem/14728
//  14728_벼락치기.cpp
//  summer_week2-2
//
//  Created by Hoon on 2018. 7. 16..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>

#define NMAX 100
#define TMAX 10000
using namespace std;

int N,T,dp[NMAX+4][TMAX+4];
pair<int, int> arr[1004];

int sol(int n ,int totalTime){
    if(n == N+1)
        return 0;
    
    int &ret = dp[n][totalTime];
    if(ret != -1) return ret;
    
    ret = sol(n+1 , totalTime);
    if(totalTime + arr[n].first <= T)
        ret = max(ret , sol(n+1 , totalTime + arr[n].first) + arr[n].second);
    
    return ret;
}

int main(){
    scanf("%d %d" , &N,&T);
    for (int i = 1; i <= N; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        arr[i] = make_pair(a, b);
    }
    
    for(int i = 0 ; i < NMAX+4 ; i++)
        memset(dp[i],-1,sizeof(dp[i]));
    
    printf("%d" , sol(1,0));
}


