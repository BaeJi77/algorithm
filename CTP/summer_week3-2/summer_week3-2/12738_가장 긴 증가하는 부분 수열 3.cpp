//
//  12738_가장 긴 증가하는 부분 수열 3.cpp
//  summer_week3-2
//
//  Created by Hoon on 2018. 7. 21..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> vt;
ll n,input;

int main(){
    scanf("%lld" , &n);
    vt.push_back(INT_MAX);
    for (int i = 0 ; i < n; i++) {
        scanf("%lld" , &input);
        if(vt.back() < input) vt.push_back(input);
        else{
            ll index = lower_bound(vt.begin(), vt.end(), input) - vt.begin();
            vt[index] = input;
        }
    }
    
    printf("%lld" , vt.size());
}
