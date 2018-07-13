////  문제 : 1로 만들기
////  https://www.acmicpc.net/problem/1463
////  1463.cpp
////  summer_week2-2
////
////  Created by Hoon on 2018. 7. 12..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <cstring>
//#include <algorithm>
//#define maxx 1000010;
//using namespace std;
//
//int n,cnt;
//int dp[1000010]; // index는 그 number을 만들기 위해 필요한 연산 (1부터)
//
//
//void init(){
//    memset(dp, 0x3f, sizeof(dp));//매우 큰값으로 바꾸기
//    dp[1] = 0;
//    for (int i = 2; i < 1000010 ; i++) {
//        dp[i] = min(dp[i],dp[i-1] +1); // 2,3으로 나눠서 떨어지지 않는 경우
//        if(i%2==0) dp[i] = min(dp[i] , dp[i/2]+1); // 2로 나눠서 떨어지는 경우
//        if(i%3==0) dp[i] = min(dp[i] , dp[i/3]+1); // 3으로 나눠서 떨어지는 경우
//    }
//}
//
//int main(){
//    init();
//    scanf("%d" , &n);
//    printf("%d" , dp[n]);
//}

