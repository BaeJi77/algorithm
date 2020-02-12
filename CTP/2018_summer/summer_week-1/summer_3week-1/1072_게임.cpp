////  https://www.acmicpc.net/problem/1072
////  1072_게임.cpp
////  summer_3week-1
////
////  Created by Hoon on 2018. 7. 16..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <algorithm>
//#define INF 9999999999
//using namespace std;
//typedef long long ll;
//
//
//ll x,y,z,left,right,ans;
//int main(){
//    while (scanf("%lld %lld" , &x,&y) != EOF) {
//        ans = INF;
//        z = y*100/x;
//        left = 1;
//        right = 1000000000;
//        while (left <= right) {
//            ll mid = (left+right)/2;
//            ll change = (y+mid) * 100/ (x+mid) ;
//            if(change > z){ //기존보다 10게임했는데 승률이 바뀜. (승률이 더 높다) => right를 줄여주자
//                right = mid - 1;
//                ans = min(ans,mid);
//            }else {
//                left = mid + 1;
//            }
//        }
//
//        if(ans == INF) printf("-1\n");
//        else printf("%lld\n" , ans);
//    }
//}
//
//
