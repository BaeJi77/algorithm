////
////  3896.cpp
////  summer_week2
////  https://www.acmicpc.net/problem/3896
////  Created by Hoon on 2018. 7. 9..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//int def = 2000000;
//bool arr[2000000];
//vector<int> vt;
//int input,t;
//void p(){
//    for (int i = 2; i < sqrt(2000000) ; i++) {
//        if(arr[i] == true) continue;
//        for (int j = i+i; j < def ; j+=i) {
//            arr[j] = true;
//        }
//    }
//    for (int i = 2; i < def; i++) {
//        if(arr[i] == false) {
//            vt.push_back(i);
//        }
//    }
//}
//
//int main(){
//    p();
//    scanf("%d" , &t);
//    while (t--) {
//        scanf("%d" , &input);
//        for (int i = 0; i < vt.size(); i++) {
//            if(input < vt[i]){
//                printf("%d\n" , vt[i]-vt[i-1]);
//                break;
//            }else if(input == vt[i]){
//                printf("0\n");
//                break;
//            }
//        }
//    }
//}

