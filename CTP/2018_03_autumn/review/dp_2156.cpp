//  https://www.acmicpc.net/problem/2156
//  dp_2156.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX 10000
using namespace std;

int N,arr[MAX+4],dp[MAX+4][4];

int solve(int x,int k){
    if(x==N+1)
        return 0;
    
    int &ret = dp[x][k];
    if(ret != -1)
        return ret;
    
    //아무것도 추가안하고 넘어가는 경우
    ret = solve(x+1,0);
    if(k < 2) ret = max(ret , solve(x+1,k+1) + arr[x]);

    return ret;
}

int main(){
    scanf("%d" , &N);
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= N; i++) {
        scanf("%d" , &arr[i]);
    }
    
    printf("%d" , solve(1,0));
}

