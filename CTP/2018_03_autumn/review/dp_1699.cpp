//  https://www.acmicpc.net/problem/1699
//  dp_1699.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 7..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX 100000
using namespace std;

int dp[MAX+4],N;

int solve(int number){
    if(number == 0)
        return 0;
    
    int& ret = dp[number];
    if(ret != -1)
        return ret;
    
    ret = solve(number-1)+1;
    for(int i = 1 ; i*i <= number ; i++){
        ret = min(ret , solve(number - i*i)+1);
    }
    
    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d" , &N);
    
    printf("%d" , solve(N));
}
