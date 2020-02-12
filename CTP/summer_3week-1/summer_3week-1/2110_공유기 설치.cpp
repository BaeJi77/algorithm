////
////  2110_공유기 설치.cpp
////  summer_3week-1
////  https://www.acmicpc.net/problem/2110
////  Created by Hoon on 2018. 7. 16..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//typedef long long ll;
//
//ll n,c,left,right,ans,cnt;
//vector<ll> vt;
//
//
//int main(){
//    scanf("%lld %lld" , &n , &c);
//    for (int i = 0; i < n ; i++) {
//        ll a = 0;
//        scanf("%lld" , &a);
//        vt.push_back(a);
//    }
//    sort(vt.begin(),vt.end());
//    left = vt[0];
//    right = vt[0] + vt[vt.size()-1];
//    ll length = left+right;
//    while (left<=right) {
//        ll mid = (left+right)/2;
//        cnt = 1;
//        ll gap = vt[0];
//        for (int i = 0 ; i < n; i++) {
//            if(vt[i] - gap >= mid){
//                gap = vt[i];
//                cnt++;
//            }
//        }
//
//        if(cnt < c){
//            right = mid -1;
//        }else{
//            left = mid + 1;
//            ans = max(ans,mid);
//        }
//    }
//
//
//    printf("%lld" , ans);
//}

