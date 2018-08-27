//  https://www.acmicpc.net/problem/1904
//  1904_01타일.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 27..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#define MAX 1000000
#define mod 15746
typedef long long ll;
using namespace std;

ll N,dp[MAX+4][2];

ll sol(ll n, ll currentNumber){
    if(n == 0) return 1;
    if(n < 0) return 0;
    
    ll &ret = dp[n][currentNumber];
    if(ret != -1) return ret;
    
    ret = ((sol(n-1 , 1))%mod + (sol(n-2,0)%mod))%mod;
    
    return ret;
}

int main(){
    scanf("%lld" , &N);
    for(ll i = 0 ; i < MAX+4;i++) memset(dp[i],-1,sizeof(dp[i]));
    
    printf("%lld" , (sol(N-1,1)%mod + sol(N-2,0)%mod)%mod);
}
