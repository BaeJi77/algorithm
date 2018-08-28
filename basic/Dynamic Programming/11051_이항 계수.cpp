//  https://www.acmicpc.net/problem/11051
//  11051_이항 계수.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>

#define MAX 1000
#define mod 10007
using namespace std;
typedef long long ll;

ll N,K,dp[MAX+4][MAX+4];

ll sol(ll n,ll k){
    ll &ret = dp[n][k];
    if(ret != -1) return ret;
    
    if(k == 0 || k == n)
        return ret = 1;
    
    ret = (sol(n-1,k) + sol(n-1,k-1))%mod;
    return ret;
}

int main(){
    scanf("%lld %lld" , &N,&K);
    for(int i = 0 ; i < MAX+4 ; i++) memset(dp[i],-1,sizeof(dp[i]));

    printf("%lld" , sol(N,K)%mod);
}
