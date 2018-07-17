////  https://www.acmicpc.net/problem/1654
////  1654_랜선 자르기.cpp
////  summer_3week-1
////
////  Created by Hoon on 2018. 7. 16..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <cmath>
//#include <limits.h>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//
//ll k,n,left,right,sum,ans;
//ll arr[10004];
//int main(){
//    scanf("%lld %lld" , &k,&n);
//    for (int i = 0; i < k; i++) {
//        scanf("%lld" , &arr[i]);
//    }
//    
//    left = 1;
//    right = INT_MAX;
//    while (left<=right) {
//        sum = 0;
//        ll mid = (left+right)/2;
//        for (int i = 0; i < k; i++) {
//            sum += arr[i]/mid;
//        }
//        
//        if(sum < n){
//            right = mid - 1;
//        }else {
//            left = mid + 1;
//            ans = max(ans,mid);
//        }
//    }
//    printf("%lld" , ans);
//}

