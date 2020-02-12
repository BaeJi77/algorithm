////  https://www.acmicpc.net/problem/3273
////  3273_두 수의 합.cpp
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
//int n,x;
//int arr[100004];
//long long cnt,ans;
//
//int main(){
//    scanf("%d" , &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d" , &arr[i]);
//    }
//    scanf("%d" , &x);
//    sort(arr, arr+n);
//
//    for (int i = 0; i < n; i++) {
//        int indexNumber = arr[i];
//        int findNumber = x-indexNumber;
//        cnt = upper_bound(arr, arr+n, findNumber) - lower_bound(arr, arr+n, findNumber);
//        if(cnt != 0) {
//            ans += cnt;
//        }
//    }
//    printf("%lld" , ans/2);
//}

