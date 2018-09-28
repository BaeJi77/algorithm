//  https://www.acmicpc.net/problem/10999
//  10999_구간 합 구하기2.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

#define MAX 1000000
using namespace std;
typedef long long ll;

ll N,M,K,seg[MAX*4+4],lazy[MAX*4+4];

void propagation(ll node,ll x,ll y){
    if(lazy[node]){
        seg[node] += (y-x+1)*lazy[node];
        if(x==y){
            lazy[node] = 0;
            return;
        }
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
        lazy[node] = 0;
    }
}

ll update(ll lo,ll hi,ll val,ll node,ll x,ll y){
    propagation(node, x, y);
    if(y < lo || hi < x)
        return seg[node];
    if(lo <= x && y <= hi){
        lazy[node] += val;
        propagation(node, x, y);
        return seg[node];
    }
    ll mid = (x+y)/2;
    return seg[node] = update(lo,hi, val, node*2, x, mid) + update(lo,hi, val, node*2+1, mid+1, y);
}

ll query(ll lo,ll hi,ll node,ll x,ll y){
    propagation(node, x, y);
    if(y < lo || hi < x)
        return 0;
    if(lo <= x && y <= hi)
        return seg[node];
    
    ll mid = (x+y)/2;
    return query(lo, hi, node*2, x, mid) + query(lo, hi, node*2+1, mid+1, y);
}

int main(){
    scanf("%lld %lld %lld" , &N,&M,&K);
    for (ll i = 1; i <= N; i++) {
        ll input;
        scanf("%lld" , &input);
        update(i,i, input, 1, 1, N);
    }
    
    for (ll i = 0; i < M+K; i++) {
        ll q;
        scanf("%lld" , &q);
        if(q == 1){
            ll a,b,c;
            scanf("%lld %lld %lld" , &a,&b,&c);
            update(a, b, c, 1, 1, N);
        }else if(q == 2){
            ll a,b;
            scanf("%lld %lld" , &a,&b);
            printf("%lld\n" , query(a, b, 1, 1, N));
        }
    }
}
