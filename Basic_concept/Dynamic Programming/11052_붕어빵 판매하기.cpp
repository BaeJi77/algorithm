//  https://www.acmicpc.net/problem/11052
//  11052_붕어빵 판매하기.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <climits>

#define NMAX 1000
#define PMAX 10000

using namespace std;
int N,P[PMAX+4],dp[NMAX+4][PMAX+4];

int sol(int n, int setNumber){
    if(n < 0) return INT_MIN;
    if(n == 0) return 0;
    if(setNumber <= 0) return INT_MIN;
    
    int &ret = dp[n][setNumber];
    if(ret != -1) return ret;
    
    ret = sol(n, setNumber-1);
    ret = max(ret, sol(n-setNumber, setNumber) + P[setNumber]);
    
    return ret;
}


int main(){
    scanf("%d" , &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d" , &P[i]);
    }
    for(int i = 0 ; i < NMAX+4 ; i++)
        memset(dp[i], -1, sizeof(dp[i]));
    
    printf("%d" , sol(N,N));
}
