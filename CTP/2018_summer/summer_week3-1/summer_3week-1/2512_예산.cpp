////  https://www.acmicpc.net/problem/2512
////  2512_예산.cpp
////  summer_3week-1
////
////  Created by Hoon on 2018. 7. 17..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//#define INF 2100000000
//ll n,m,left,right,btotal,maxx,bmax,ans,mid;
//ll arr[10004];
//
//ll function(){
//
//    left = 0;
//    right = INF;
//
//    while (left <= right) {
//        mid = (left+right)/2; // 상한액
//        ll sum = 0;
//        for (int i = 0; i < n; i++) {
//            if(mid >= arr[i]) sum += arr[i];
//            else sum += mid;
//        }
////        printf("%lld %lld %lld %lld\n" , left , right, mid , sum);
//        if(m < sum){ // 예산이 더 많다 => 상한액을 낮춰도 된다.
//            right = mid - 1;
//        }else {
//            left = mid + 1;
//            maxx = max(maxx,mid);
//        }
//    }
//    return maxx;
//}
//
//int main(){
//    scanf("%lld" , &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%lld" , &arr[i]);
//        btotal += arr[i];
//        bmax = max(bmax, arr[i]);
//    }
//    scanf("%lld" , &m);
//    if(btotal <= m){
//        ans = bmax;
//    }else {
//        ans = function();
//    }
//
//    printf("%lld" , ans);
//}
//
