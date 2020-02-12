//  https://www.acmicpc.net/problem/1275
//  1275_커피숍2.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 20..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
typedef long long ll;
using namespace std;

ll n,q,seg[400004];

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
    for (ll i = 1; i<=n; i++) {
        ll a;
        scanf("%lld" , &a);
        update(i, a, 1, 1, n);
    }
    
    for (ll i = 0; i < q; i++) {
        ll x,y,a,b;
        scanf("%lld %lld %lld %lld" , &x,&y,&a,&b);
        if(x > y) {
            ll temp = x;
            x = y;
            y = temp;
        }
        
        printf("%lld\n" , query(x, y, 1, 1, n));
        update(a, b, 1, 1, n);
    }
}

