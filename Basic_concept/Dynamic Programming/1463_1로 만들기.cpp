//  https://www.acmicpc.net/problem/1463
//  1463_1로 만들기.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 26..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int N;
int dp[1000004];

int sol(int x){
    if(x == 1) return 0;
    if(dp[x] != -1) return dp[x];
    
    int result = sol(x-1) +1;
    if(x % 3 == 0) result = min(result,sol(x/3) +1);
    if(x % 2 == 0) result = min(result,sol(x/2) +1);
    
    return dp[x] = result;
}

int main(){
    scanf("%d" , &N);
    memset(dp,-1,sizeof(dp));
    
    printf("%d" , sol(N));
}
