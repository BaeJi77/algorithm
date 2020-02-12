////  https://www.acmicpc.net/problem/12015
////  12015_가장 긴 증가하는 부분 수열 2.cpp
////  summer_week3-2
////
////  Created by Hoon on 2018. 7. 19..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <limits.h>
//#include <algorithm>
//using namespace std;
//
//int n;
//int arr[1000004];
//vector<int> vt;
//
//int main(){
//    scanf("%d" , &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d",&arr[i]);
//    }
//    vt.push_back(INT_MAX);
//    for (int i = 0; i < n; i++) {
//        if(arr[i] > vt.back()) vt.push_back(arr[i]);
//        else{
//            int index = lower_bound(vt.begin(), vt.end(), arr[i]) - vt.begin();
//            vt[index] = arr[i];
//        }
//    }
//
//    printf("%d" , vt.size());
//}

