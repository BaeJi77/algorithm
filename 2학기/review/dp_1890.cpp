//  https://www.acmicpc.net/problem/1890
//  dp_1890.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#define MAX 100
using namespace std;
typedef long long ll;

ll N;
ll map[MAX+4][MAX+4];
ll dp[MAX+4][MAX+4];
ll dy[] = {0,1};
ll dx[] = {1,0};

bool isposs(ll y,ll x){
    return y>=0&&x>=0&&y<N&&x<N;
}

ll solve(ll y,ll x){
    if(y==N-1 && x==N-1){
        return 1;
    }
    
    ll& ret = dp[y][x];
    if(ret != -1)
        return ret;
    ret = 0;
    
    for (ll i = 0; i < 2; i++) {
        ll yy = y + dy[i]*map[y][x];
        ll xx = x + dx[i]*map[y][x];
        
        if(isposs(yy, xx) == false)
            continue;
        
        ret += solve(yy,xx);
    }
    
    return ret;
}

int main(){
    scanf("%lld" ,&N);
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            scanf("%lld" , &map[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld",solve(0, 0));
}

