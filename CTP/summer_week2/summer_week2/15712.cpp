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


int main(){
    scanf("%lld %lld %lld %lld" , &a, &r, &n, &mod);
    if(r == 1){
        sum = n;
    }else {
        sum = (pow(r, n)-1)/(r-1);
        sum = sum % mod;
    }
    
    printf("%lld" , (a*sum)%mod);
}
