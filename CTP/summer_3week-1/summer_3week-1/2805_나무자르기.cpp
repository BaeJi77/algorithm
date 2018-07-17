////  https://www.acmicpc.net/problem/2805
////  2805_나무자르기.cpp
////  summer_3week-1
////
////  Created by Hoon on 2018. 7. 16..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//
//
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//
//ll left = 1;
//ll right = 2000000000;
//ll N,goal,sum,cut,maxx;
//ll arr[1000004];
//
//int main() {
//    scanf("%lld %lld" , &N , &goal);
//    for (ll i = 0; i < N; i++) scanf("%lld" , &arr[i]);
//    while (left<=right) {
//        sum = 0;
//        ll mid = (left+right)/2;
//
//        for (ll i = 0 ; i < N; i++) {
//            if(arr[i] - mid < 0) sum += 0;
//            else sum += arr[i] - mid;
//        }
//
//        if(sum < goal){
//            right = mid - 1;
//        }else {
//            left = mid + 1;
//            maxx = max(maxx, mid);
//        }
//    }
//
//    printf("%lld" , maxx);
//}

