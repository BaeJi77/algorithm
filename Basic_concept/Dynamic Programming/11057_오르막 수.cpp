//  https://www.acmicpc.net/problem/11057
//  11057_오르막 수.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//


#include <stdio.h>
#include <cstring>
#include <algorithm>

#define NMAX 1000
#define mod 10007
using namespace std;
typedef long long ll;

ll N,dp[NMAX+4][14],ans;

ll sol(ll n ,ll lastNumber){
    if(0 > lastNumber || lastNumber > 9)
        return 0;
    if(n == 0)
        return 1;
    
    ll &ret = dp[n][lastNumber];
    if(ret != -1) return ret;
    
    ret = sol(n-1, lastNumber)%mod;
    for (ll i = 1; i < 10; i++) {
        ret += sol(n-1, lastNumber+i)%mod;
        ret %= mod;
    }
    
    return ret;
}

int main(){
    scanf("%lld" , &N);
    for(ll i = 0 ; i < NMAX+4; i++)
        memset(dp[i],-1,sizeof(dp[i]));
    
    for (ll i = 0; i <= 9; i++) {
        ans += sol(N-1,i)%mod;
        ans %= mod;
    }
    
    printf("%lld" , ans);
}

