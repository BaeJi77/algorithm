//  https://www.acmicpc.net/problem/3745
//  3745_오름세.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 21..
//  Copyright © 2018년 Hoon. All rights reserved.
//


#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,seg[400004];
pair<ll, ll> arr[400004];

ll update(ll pos, ll val, ll node, ll x, ll y){
    if(y < pos || pos < x) return seg[node];
    if(x==y) return seg[node] = val;
    ll mid = (x+y)/2;
    ll front = update(pos, val, node*2, x, mid);
    ll back = update(pos, val, node*2+1, mid+1, y);
    if(front > back){
        return seg[node] = front;
    }else {
        return seg[node] = back;
    }
}

ll query(ll lo, ll hi, ll node, ll x, ll y){
    if(y < lo || hi < x) return 0;
    if(lo <= x && y <= hi) return seg[node];
    ll mid = (x+y)/2;
    ll front = query(lo, hi, node*2, x, mid);
    ll back = query(lo, hi, node*2+1, mid+1, y);
    if(front> back){
        return front;
    }else {
        return back;
    }
}

int main(){
    while (scanf("%lld" ,&n) != -1) {
        memset(seg,0,sizeof(seg));
        memset(arr,0,sizeof(arr));
        for (ll i = 1; i <= n; i++) {
            ll a;
            scanf("%lld" , &a);
            arr[i] = make_pair(a, i);
        }
        
        sort(arr , arr+n+1 , [](const pair<ll, ll> &a , const pair<ll, ll> &b){
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        
        for (ll i = 1; i <= n; i++) {
            ll pre = query(1, arr[i].second, 1, 1, n);
            update(arr[i].second, pre+1, 1, 1, n);
        }
        
        printf("%lld\n" , seg[1]);
    }
}

