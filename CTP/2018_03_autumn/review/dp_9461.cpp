//
//  dp_9461.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 7..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[104];

int main(){
    ll test;
    scanf("%lld" , &test);
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;
    for (ll i = 6; i < 101; i++)
        dp[i] = dp[i-2]+dp[i-3];
    
    for (ll i = 0; i < test; i++) {
        ll k;
        scanf("%lld" , &k);
        printf("%lld\n" , dp[k]);
    }
}
