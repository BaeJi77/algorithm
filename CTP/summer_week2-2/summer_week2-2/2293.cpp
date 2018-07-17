////  문제 : 동전 1
////  https://www.acmicpc.net/problem/2293
////  2293.cpp
////  summer_week2-2
////
////  Created by Hoon on 2018. 7. 12..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <cstring>
//
//using namespace std;
//
//int n,k;
//int coin[104];
//int dp[10004]; //dp는 인덱스 값을 나타낼수 있는 경우의 수
//
//void dpfunction(){
//    dp[0] = 1;
//
//    for (int i = 0 ; i < n; i++) {
//        //동전 하나당 한번씩 dp를 업데이트해줌
//        if(coin[i] <= k){
//            for (int j = 1; j <= k; j++) {
//                if(j-coin[i] < 0) continue; //index error 조심하자~
//                dp[j] = dp[j] + dp[j - coin[i]];
//            }
//        }
//    }
//}
//
//int main(){
//    scanf("%d %d" , &n,&k);
//    for (int i = 0; i < n; i++) {
//        scanf("%d" , &coin[i]);
//    }
//    dpfunction();
//    printf("%d" , dp[k]);
//}
//
