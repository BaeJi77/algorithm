//  https://www.acmicpc.net/problem/11401
//  11401_이항 계수 3.cpp
//  CTP_summer
//
//  Created by Hoon on 2018. 8. 22..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

#define mod 1000000007
using namespace std;
typedef long long ll;

ll n,k;

ll lowPow(ll val, ll power){
    if(power == 0 ) return 1;
    if(power % 2 == 1) return (val*lowPow(val, power-1))%mod;
    else return (lowPow((val*val)%mod, power/2))%mod;
}

int main(){
    scanf("%lld %lld" , &n,&k);
    ll a = 1;
    ll b = 1;
    for (int i = 1; i <= n; i++) {
        a *= i;
        a %= mod;
    }
    
    for (int i = 1; i <=k; i++) {
        b *= i;
        b %= mod;
    }
    
    for (int i = 1; i <= n-k; i++) {
        b *= i;
        b %= mod;
    }
    
    printf("%lld" , (a*lowPow(b,mod-2))%mod );
}
