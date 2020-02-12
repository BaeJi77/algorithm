//  https://www.acmicpc.net/problem/2343
//  2343_기타 레슨.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 30..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <climits>
#include <algorithm>

#define MAX 100000
using namespace std;
typedef long long ll;

ll N,M,lesson[MAX+4];

ll search(ll left,ll right){
    ll minn = INT_MAX;
    while (left+1 < right) {
        ll mid = (left+right)/2;
        ll sum = 0;
        ll cnt = 1;
        for (ll i = 0; i < N; i++) {
            sum += lesson[i];
            if(sum > mid){
                cnt++;
                sum = lesson[i];
            }
        }
        
        if(cnt > M){
            left = mid;
        }else{
            right = mid;
            minn = min(minn , mid);
        }
    }
    
    return minn;
}

int main(){
    scanf("%lld %lld" , &N,&M);
    ll MAXX = 0;
    for(ll i = 0 ; i < N ; i++){
        scanf("%lld" , &lesson[i]);
        MAXX = max(MAXX , lesson[i]);
    }
    
    ll ans = search(0,1000000000);
    if(MAXX > ans)
        printf("%lld" , MAXX);
    else
        printf("%lld" , ans);
}

//9 3
//1 2 3 4 5 6 7 8 9

//7 6
//100 400 300 100 500 101 400

//7 7
//5 9 6 8 7 7 5

//8 7
//3 3 10 10 3 2 6 2

//7 7
//1 5 9 9 9 2 9

