//  https://www.acmicpc.net/problem/5676
//  5676_음주 코딩.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>

#define MAX 100000
using namespace std;
typedef long long ll;

ll N,K,seg[MAX*4+4];

ll update(ll pos,ll val, ll node,ll x,ll y){
    if(y < pos || pos < x)
        return seg[node];
    if(x==y)
        return seg[node] = val;
    
    ll mid = (x+y)/2;
    return seg[node] = update(pos, val, node*2, x, mid) * update(pos, val, node*2+1, mid+1, y);
}

ll query(ll lo,ll hi,ll node,ll x,ll y){
    if(y < lo || hi < x)
        return 1;
    if(lo <= x && y <= hi)
        return seg[node];
    
    ll mid = (x+y)/2;
    return query(lo, hi, node*2, x, mid) * query(lo, hi, node*2+1, mid+1, y);
}

int main(){
    while (scanf("%lld %lld" , &N,&K) != EOF) {
        memset(seg,0,sizeof(seg));
        for (ll i = 1; i <=N; i++) {
            ll a;
            scanf("%lld" , &a);
            if(a > 0)
                a = 1;
            else if(a < 0)
                a = -1;
            else
                a = 0;
            update(i, a, 1, 1, N);
        }
        
        for (ll i = 0 ; i < K; i++) {
            getchar();
            char q = getchar();
            ll a,b;
            scanf("%lld %lld" , &a,&b);
            if(q == 'C'){
                if(b > 0)
                    b = 1;
                else if(b < 0)
                    b = -1;
                else
                    b = 0;
                update(a, b, 1, 1, N);
            }else if(q == 'P'){
                ll out = query(a, b, 1, 1, N);
                if(out > 0)
                    printf("+");
                else if(out < 0)
                    printf("-");
                else
                    printf("0");
            }
        }
        puts("");
    }
}
