////  https://www.acmicpc.net/problem/2343
////  2343_기타 레슨.cpp
////  summer_3week-1
////
////  Created by Hoon on 2018. 7. 17..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <algorithm>
//#define INF 999999999
//using namespace std;
//
//int n,m,basicSum,left,right,minn,cnt;
//int arr[100004];
//
//int function(){
//    left = 1;
//    right = basicSum;
//    minn = INF;
//    while (left<=right) {
//        cnt = 0;
//        int mid = (left+right)/2;
//        int temp = 0;
//
//        for (int i = 0; i < n; i++) {
//            if(m != cnt){
//                temp += arr[i];
//                if(temp+arr[i+1] > mid) {
//                    temp = 0;
//                    cnt++;
//                }
//            }
//        }
//
//        if(cnt < m){ // cnt < m => 크게 짤랐다. right를 줄이자
//            right = mid - 1;
//            minn = min(minn,mid);
//        }else{
//            left = mid + 1;
//        }
//    }
//    return minn;
//}
//
//int main(){
//    scanf("%d %d" , &n,&m);
//    for (int i = 0 ; i < n; i++) {
//        scanf("%d" , &arr[i]);
//        basicSum += arr[i];
//    }
//
//    int ans = function();
//    printf("%d" , ans);
//}
//
