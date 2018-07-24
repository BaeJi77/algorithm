////  https://www.acmicpc.net/problem/1946
////  1946_신입 사원.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 23..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <stack>
//#include <iostream>
//using namespace std;
//typedef pair<int, int> pii;
//int T,n,cnt,checkCnt,ans;
//vector<pair<int, int>> vt;
//stack<int> stk;
//
//int main(){
//    scanf("%d" ,&T);
//    while (T--) {
//        vt.clear();
//        ans = 0;
//        while (!stk.empty()) stk.pop();
//        scanf("%d" , &n);
//        for (int i = 0; i < n; i++) {
//            int a,b;
//            scanf("%d %d", &a , &b);
//            vt.push_back({a,b});
//        }
//        sort(vt.begin(), vt.end());
//
//        for (int i = 0; i < n; i++) {
//            checkCnt = 0;
//            for (int j = 0; j < i; j++) {
//                if(vt[i].second < vt[j].second) checkCnt++;
//            }
//            if(checkCnt == i) {
//                ans++;
//            }
//        }
//
//        printf("%d\n" , ans);
//    }
//}
//
