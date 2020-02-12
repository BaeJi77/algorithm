//  문제 : RGB거리
//  https://www.acmicpc.net/problem/1149
//  1149.cpp
//  summer_week2-2
//
//  Created by Hoon on 2018. 7. 12..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int house[1010][3]; //[0]빨강 [1]초록 [2]파랑
int dp[1010][3];  //[0]빨강 [1]초록 [2]파랑 -> 전에 그 색을 선택했을 때 이번에 가장 최저로 색을 칠하는 방법

int N,minn;

void dpfunction(){
    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];
    for (int i = 1 ; i <= N; i++) {
        dp[i][0] = min(dp[i-1][1] + house[i][0], dp[i-1][2] + house[i][0]);
        dp[i][1] = min(dp[i-1][0] + house[i][1], dp[i-1][2] + house[i][1]);
        dp[i][2] = min(dp[i-1][0] + house[i][2], dp[i-1][1] + house[i][2]);
    }
}

int main(){
    scanf("%d" , &N);
    for (int i = 0 ; i < N; i++) {
        for (int j = 0 ; j < 3 ;  j++) {
            scanf("%d" , &house[i][j]);
        }
    }
    dpfunction();
    printf("%d" , min(dp[N][0] , min(dp[N][1] , dp[N][2])));
}

