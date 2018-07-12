//  문제 : 동전 1
//  https://www.acmicpc.net/problem/2293
//  2293.cpp
//  summer_week2-2
//
//  Created by Hoon on 2018. 7. 12..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int n,k;
int coin[104];
int dp[10004];
int main(){
    scanf("%d %d" , &n,&k);
    for (int i = 0; i < n; i++) {
        scanf("%d" , &coin[i]);
    }
    dp[0] = 0;
    
    //dp는 인덱스 값을 나타낼수 있는 경우의 수
    for (int i = 1 ; i <= k; i++) {
        dp[i] = 0;
    }
}
