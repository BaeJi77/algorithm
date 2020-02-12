//  https://www.acmicpc.net/problem/2193
//  2193_이친수.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 26..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <climits>
#define MAX 90
using namespace std;
typedef long long  ll;

ll N,dp[MAX+4][2];

ll sol(ll n,ll ended){
    if(n == 0) return 1;
    if(dp[n][ended] != -1) return dp[n][ended];
    
    ll result = sol(n-1,0);
    if(ended == 0) result+= sol(n-1,1);
    
    return dp[n][ended] = result;
}

int main(){
    scanf("%lld" , &N);
    for(ll i = 0 ; i < MAX+4 ; i++) memset(dp[i],-1,sizeof(dp[i]));
    
    printf("%lld" , sol(N-1,1));
}
