////
////  1018.cpp
////  11week
////
////  Created by Hoon on 2018. 5. 23..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <string>
//#include <iostream>
//
//using namespace std;
//int m,n,cnt;
//char arr[60][60];
//string str;
//int bcnt, wcnt;
//int bneed, wneed;
//int mmin=12345678;
//
//
//int main(){
//    scanf("%d %d" , &m , &n);
//    getchar();
//    for(int i = 0 ; i < m ; i++ ){
//        getline(cin, str);
//        for(int j = 0  ; j < n ; j++){
//            arr[i][j] = str[j];
//        }
//    }
//    for(int i = 0 ; i <= m-8 ; i++){
//        for(int j = 0 ; j <= n-8 ; j++){
//            for(int k = i ; k < i+8 ; k++){
//                for(int x = j ; x < j+8 ; x++){
//                    if(arr[k][x] == 'B') bcnt++;
//                    if(arr[k][x] == 'W') wcnt++;
//                }
//            }
//            printf("%d %d %d %d\n" , bcnt , wcnt , i , j);
//            //                bneed = 32-bcnt;
//            //                wneed = 32-wcnt;
//            //
//            while (1) {
//                if(bcnt == 32){
//                    break;
//                }else if(bcnt > 32){
//                    bcnt--;
//                    wcnt++;
//                    cnt++;
//                }else {
//                    bcnt++;
//                    wcnt--;
//                    cnt++;
//                }
//            }
//            mmin = min(mmin, cnt);
//            bcnt=0; wcnt=0; cnt=0;
//        }
//    }
//
//    printf("%d" , mmin);
//
//}
//
//
