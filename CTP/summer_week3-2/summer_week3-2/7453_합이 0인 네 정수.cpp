////  https://www.acmicpc.net/problem/7453
////  7453_합이 0인 네 정수.cpp
////  summer_week3-2
////
////  Created by Hoon on 2018. 7. 19..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int n;
//long long cnt;
//int a[4004];
//int b[4004];
//int c[4004];
//int d[4004];
//vector<int> x;
//vector<int> y;
//
//int main(){
//    scanf("%d" , &n);
//    for (int i = 0 ; i < n; i++) {
//        scanf("%d %d %d %d" , &a[i] , &b[i] , &c[i] , &d[i]);
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0 ; j < n; j++) {
//            x.push_back(a[i] + b[j]);
//            y.push_back(c[i] + d[j]);
//        }
//    }
//    sort(x.begin(), x.end());
//    sort(y.begin(), y.end());
//
//    for (int i = 0; i < n*n; i++) {
//        cnt+= upper_bound(y.begin(), y.end(), -x[i]) - lower_bound(y.begin(), y.end(), -x[i]);
//    }
//    printf("%lld" , cnt);
//}

