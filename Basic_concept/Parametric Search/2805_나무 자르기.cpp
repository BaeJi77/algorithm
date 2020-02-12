//  https://www.acmicpc.net/problem/2805
//  2805_나무 자르기.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 29..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

#define MAX 1000000
using namespace std;
typedef long long ll;

ll N,K,wood[MAX+4],maxx;

ll search(ll left,ll right){
    while (left+1 < right) {
        ll mid = (left+right)/2;
        ll sum = 0;
        for (ll i = 0; i < N; i++) {
            if(wood[i] > mid)
                sum += wood[i]-mid;
        }
        
        if(sum >= K){
            left = mid;
            maxx = max(left , maxx);
        }
        else right = mid;
    }
    
    return maxx;
}

int main(){
    scanf("%lld %lld" , &N,&K);
    for (ll i = 0 ; i < N; i++) {
        scanf("%lld" , &wood[i]);
    }
    
    printf("%lld" , search(0, 2000000000));
}
