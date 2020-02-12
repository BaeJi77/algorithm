//  https://www.acmicpc.net/problem/5676
//  5676_음주 코딩.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 23..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;

ll n,k,seg[4*MAX+4],nodeVal[MAX+4];

ll update(ll pos, ll val, ll node, ll x,ll y){
    if(y < pos || pos < x)
        return seg[node];
    if(y==x)
        return seg[node] = val;
    
    ll mid = (x+y)/2;
    return seg[node] = update(pos, val, node*2, x, mid)*update(pos, val, node*2+1, mid+1, y);
}

ll query(ll lo, ll hi , ll node ,ll x, ll y){
    if(y < lo || hi < x)
        return 1;
    if(lo <= x && y <= hi)
        return seg[node];
    ll mid = (x+y)/2;
    return query(lo, hi, node*2, x, mid) * query(lo, hi, node*2+1, mid+1, y);
}

int main(){
    while (scanf("%lld %lld", &n,&k) != EOF) {
        memset(nodeVal , 0, sizeof(nodeVal));
        memset(seg,0,sizeof(seg));
        fill(seg, seg+4*MAX+4, 1);
//        for (int i = 1; i <= 4*MAX+4; i++)
//            seg[i] = 1;
        
        for (ll i = 1; i <= n; i++) {
            ll a;
            scanf("%lld" , &a);
            nodeVal[i] = a;
            update(i, a, 1, 1, n);
        }
        
        for (ll i = 1; i <= k; i++) {
            getchar();
            char Q = getchar();
            ll a,b;
            scanf("%lld %lld" , &a,&b);
            if(Q == 'C'){
                nodeVal[a] = b;
                update(a, b, 1, 1, n);
            }else{
                ll ans = query(a, b, 1, 1, n);
//                printf("%lld\n" , ans);
                if(ans > 0) printf("+");
                else if(ans < 0) printf("-");
                else printf("0");
            }
        }
        puts("");
    }
}
