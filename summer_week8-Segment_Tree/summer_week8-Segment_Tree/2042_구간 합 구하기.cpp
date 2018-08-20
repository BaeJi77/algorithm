//  https://www.acmicpc.net/problem/2042
//  2042_구간 합 구하기.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 20..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
typedef long long ll;
ll n,m,k;
ll seg[4000004];

ll update(ll pos,ll value,ll node, ll x,ll y){
    if(y < pos || pos < x) return seg[node];
    if(x==y) return seg[node] = value;
    ll mid = (x+y)/2;
    return seg[node] = update(pos, value, node*2 , x, mid) + update(pos, value, node*2+1, mid+1, y);
}

ll query(ll lo,ll hi, ll node, ll x, ll y){
    if(y < lo || hi < x) return 0;
    if(lo <= x && y <= hi) return seg[node];
    ll mid = (x+y)/2;
    return query(lo, hi, node*2, x, mid) + query(lo, hi, node*2+1, mid+1, y);
}

int main() {
    scanf("%lld %lld %lld" , &n,&m,&k);
    for (ll i = 1; i <= n; i++) {
        ll a;
        scanf("%lld" , &a);
        update(i, a, 1, 1, n);
    }
    
    for (ll i = 0; i < m+k; i++) {
        ll a,b,c;
        scanf("%lld %lld %lld" , &a,&b,&c);
        if(a==1){
            update(b, c, 1, 1, n);
        }else if(a==2){
            printf("%lld\n" , query(b, c, 1, 1, n));
        }
    }
}
