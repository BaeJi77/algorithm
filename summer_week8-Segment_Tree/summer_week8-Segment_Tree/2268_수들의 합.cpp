//  https://www.acmicpc.net/problem/2268
//  2268_수들의 합.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 20..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
typedef long long ll;
using namespace std;

ll n,q,seg[4000004];

ll update(ll pos, ll val, ll node, ll x,ll y){
    if(y < pos || pos < x) return seg[node];
    if(x==y) return seg[node] = val;
    ll mid = (x+y)/2;
    return seg[node] = update(pos, val, node*2, x, mid) + update(pos, val, node*2+1, mid+1, y);
}

ll query(ll lo, ll hi, ll node, ll x, ll y){
    if(y < lo || hi < x) return 0;
    if(lo <= x && y <= hi) return seg[node];
    ll mid = (x+y)/2;
    return query(lo, hi, node*2, x, mid) + query(lo, hi, node*2+1, mid+1, y);
}

int main(){
    scanf("%lld %lld" , &n,&q);
    
    for (ll i = 0; i < q; i++) {
        ll a,b,c;
        scanf("%lld %lld %lld" , &a,&b,&c);
        if(a == 0){
            if(b > c) {
                ll temp = b;
                b = c;
                c = temp;
            }
            printf("%lld\n" , query(b, c, 1, 1, n));
        }else{
            update(b, c, 1, 1, n);
        }
    }
}

