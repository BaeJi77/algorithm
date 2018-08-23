//
//  15712.cpp
//  summer_week2
//  제목 : 등비수열
//  https://www.acmicpc.net/problem/15712
//  Created by Hoon on 2018. 7. 10..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cmath>
typedef long long ll;

ll a, r, n , mod;
ll sum;

ll lowPow(ll val, ll power){
    if(power == 0) return 1;
    if(power % 2 == 1) return (val%mod)*lowPow( val%mod, (power-1)%mod )%mod;
    else return lowPow((val*val)%mod, power/2 )%mod;
}

int main(){
    scanf("%lld %lld %lld %lld" , &a, &r, &n, &mod);
    if(r == 1){
        sum = n;
    }else {
//        printf("%d\n" , (pow(r,n)-1)/(r-1));
//        printf("%d\n" , (lowPow(r, n)-1)/(r-1));
//        sum = ((a*(lowPow(r, n))-1))%mod/(r-1);
        sum = (pow(r,n)-1)/(r-1);
        sum = sum % mod;
    }
    
    printf("%lld" , (sum)%mod);
}

