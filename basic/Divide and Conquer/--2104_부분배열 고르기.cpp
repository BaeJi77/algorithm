//  https://www.acmicpc.net/problem/2104
//  2104_부분배열 고르기.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,maxx,sum;
vector<ll> vt;

int main(){
    scanf("%lld" , &n);
    for (ll i = 1; i <= n; i++) {
        ll a;
        scanf("%lld" , &a);
        vt.push_back(a);
    }
    
    sort(vt.begin(),vt.end());
    for (ll i = vt.size()-1; i >=0; i--) {
        sum += vt[i];
        maxx = max(maxx , sum*vt[i]);
    }
    
    printf("%lld" , maxx);
}
