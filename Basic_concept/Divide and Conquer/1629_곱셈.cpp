//  https://www.acmicpc.net/problem/1629
//  1629_곱셈.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;
typedef long long ll;

ll a,b,c;

ll power(ll number, ll pow){
    if(pow == 0) return 1;
    if(pow % 2 == 1) return number%c*power(number,pow-1)%c;
    else return power((number%c*number%c)%c,pow/2)%c;
}

int main(){
    scanf("%lld %lld %lld" , &a,&b,&c);
    ll ans = power(a%c,b)%c;
    printf("%lld" , ans);
}
