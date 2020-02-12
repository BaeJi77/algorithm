//  https://www.acmicpc.net/problem/2512
//  2512_예산.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 29..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

ll N,money[10004],M;

ll Search(ll left,ll right){
    ll maxx = INT_MIN;
//    ll minn = ll_MAX;
    while (left+1 < right) {
        ll mid = (left+right)/2;
        ll sum = 0;
        for (ll i = 0 ; i < N; i++) {
            if(mid >= money[i])
                sum += money[i];
            else
                sum += mid;
        }
        if(sum > M){
            right = mid;
            
        }else {
            left = mid;
            maxx = max(maxx , left);
        }
    }
    
    return maxx;
}

int main(){
    scanf("%lld" , &N);
    ll firstMoney = 0;
    ll firstMax = 0;
    for(ll i = 0 ; i < N ; i++){
        scanf("%lld" , &money[i]);
        firstMoney += money[i];
        firstMax = max(firstMax , money[i]);
    }
    
    scanf("%lld" , &M);
    if(M >= firstMoney) printf("%lld" , firstMax);
    else printf("%lld" , Search(0, 1000000000));
}
