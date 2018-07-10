////
////  11051.cpp
////  summer_week2
////  https://www.acmicpc.net/problem/11051
////  Created by Hoon on 2018. 7. 9..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#define mod 10007
//
//int n,k;
//int list[1010][1010];
//
//int main(){
//    scanf("%d %d" , &n,&k);
//    list[1][0] = list[1][1] = 1;
//    for (int i = 2 ; i <= n; i++) {
//        for (int j = 0; j <=i; j++) {
//            if(j == 0 || i == j){
//                list[i][j] = 1;
//            }else{
//                list[i][j] = list[i-1][j-1]%mod + list[i-1][j]%mod;
//                list[i][j] %= mod;
//            }
//        }
//    }
//    printf("%d" , list[n][k]);
//}
//
//
//
