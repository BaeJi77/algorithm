//
//  11401.cpp
//  summer_week2
//  https://www.acmicpc.net/problem/11401
//  이항 계수 3
//  Created by Hoon on 2018. 7. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#define mod 1000000007LL
typedef long long ll;

using namespace std;
long long n,k;
ll a=1;
ll b=1;

ll lowPow(ll val, ll power){
    if(power == 0) return 1;
    if(power % 2) return (val%mod)*lowPow( val%mod, (power-1)%mod )%mod;
    else return lowPow((val*val)%mod, power/2 )%mod;
}

int main(){
    scanf("%lld %lld" , &n,&k);
    for (ll i = 1; i <= n; i++) {
        a *= i;
        a %= mod;
    }

    for (ll i = 1; i <= k; i++) {
        b *= i;
        b %= mod;
    }
    for (ll i = 1; i <= n-k; i++) {
        b *= i;
        b %= mod;
    }
    printf("%lld" , (a*lowPow(b, mod-2)) % mod);
}

