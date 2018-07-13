////
////  제목 : 피보나치 수열
////  https://www.acmicpc.net/problem/1003
////  1003.cpp
////  summer_week2-2
////
////  Created by Hoon on 2018. 7. 12..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//
//int T,input,cnt0,cnt1;
//int dp[44];
//
//int fibo(int pos){
//    int &ret = dp[pos];
//    if(ret != -1) return ret;
//    if(pos == 0) {
//        cnt0++;
//        return 1;
//    }else if(pos == 1){
//        cnt1++;
//        return 1;
//    }
//    return fibo(pos-1) + fibo(pos-2);
//}
//
//int main(int argc, const char * argv[]) {
//    scanf("%d" , &T);
//    memset(dp, -1, sizeof(dp));
//    dp[0] = 1;
//    dp[1] = 1;
//    while (T--) {
//        cnt0=cnt1=0;
//        scanf("%d" , &input);
//        fibo(input);
//        printf("%d %d" , cnt0, cnt1);
//        puts("");
//    }
//}

