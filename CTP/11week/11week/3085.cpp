////
////  3085.cpp
////  11week
////
////  Created by Hoon on 2018. 5. 16..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <string>
//#include <iostream>
//
//using namespace std;
//int n;
//string str;
//char arr[60][60];
//int MAXX;
//int cnt;
//
//void check(){
//    for(int i = 0 ; i < n ; i++){
//        for(int j = 0 ; j < n-1 ; j++){
//            if(arr[i][j] == arr[i][j+1]){
//                cnt++;
//                MAXX = max(MAXX , cnt);
//            }else{
//                cnt = 0;
//            }
//        }
//        cnt = 0;
//    }
//
//    for(int i = 0 ; i < n ; i++){
//        for(int j = 0 ; j < n-1 ; j++){
//            if(arr[j][i] == arr[j+1][i]){
//                cnt++;
//                MAXX = max(MAXX , cnt);
//            }else{
//                cnt = 0;
//            }
//        }
//        cnt = 0;
//    }
//}
//
//
//int main(){
//    scanf("%d" , &n);
//    getchar();
//    //값 받기
//    for(int i = 0 ; i < n ; i++){
//        getline(cin,str);
//        for(int j = 0 ; j < n ; j++){
//            arr[i][j] = str[j];
//        }
//    }
//
//    for(int i = 0 ; i < n ; i++){
//        for(int j = 0 ; j < n-1 ; j++){
//            swap(arr[i][j], arr[i][j+1]);
//            check();
//            swap(arr[i][j], arr[i][j+1]);
//        }
//    }
//    for(int i = 0 ; i < n ; i++){
//        for(int j = 0 ; j < n-1 ; j++){
//            swap(arr[j+1][i], arr[j][i]);
//            check();
//            swap(arr[j+1][i], arr[j][i]);
//        }
//    }
//    printf("%d" , MAXX+1);
//}

