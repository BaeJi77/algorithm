//  https://www.acmicpc.net/problem/2243
//  2243_사탕상자.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 23..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cstring>
#define LAST 1000000
using namespace std;
typedef long long ll;
ll n,seg[4*LAST+4],nodeVal[LAST+4],poll;

ll update(ll pos, ll val, ll node, ll x, ll y){
    if(y < pos || pos < x)
        return seg[node];
    if(x==y)
        return seg[node] = val;
    ll mid = (x+y)/2;
    return seg[node] = update(pos, val, node*2, x, mid) + update(pos, val, node*2+1, mid+1, y);
}

ll query(ll val, ll node, ll x , ll y){
    if(x==y){
        nodeVal[x]--;
        update(x, nodeVal[x] ,1,1,LAST);
        return x;
    }

    ll mid = (x+y)/2;
    if(seg[node*2] >= val)
        return query(val, node*2, x, mid);
    else
        return query(val - seg[node*2], node*2+1, mid+1, y);
}

int main(){
    memset(seg,0,sizeof(seg));
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        ll q;
        scanf("%lld" , &q);
        if(q == 1){
            ll a;
            scanf("%lld" , &a);
            ll result = query(a, 1, 1, LAST);
            printf("%lld\n", result);
        }else{
            ll a,b;
            scanf("%lld %lld" , &a,&b);
            nodeVal[a] += b;
            update(a, nodeVal[a], 1, 1, LAST);
        }
    }
}
