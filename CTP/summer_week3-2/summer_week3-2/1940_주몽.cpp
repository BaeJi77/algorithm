////  https://www.acmicpc.net/problem/1940
////  1940_주몽.cpp
////  summer_week3-2
////
////  Created by Hoon on 2018. 7. 20..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//
//int n,m,left,right,cnt;
//int arr[15004];
//
//int main(){
//    scanf("%d" , &n);
//    scanf("%d" , &m);
//    for (int i = 0 ; i < n; i++) scanf("%d" , &arr[i]);
//    sort(arr,arr+n);
//
//    for (int i = 0; i < n; i++) {
//        int indexNumber = arr[i];
//        int findNumber = m-indexNumber;
//        cnt += upper_bound(arr,arr+n,findNumber) - lower_bound(arr,arr+n,findNumber);
//    }
//
//    printf("%d" , cnt/2);
//}

