////  https://www.acmicpc.net/problem/1911
////  1911_흙길 보수하기.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 23..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int n,l,cnt,space;
//vector<pair<int, int>> vt;
//
//
//int main(){
//    scanf("%d %d" , &n ,&l);
//    for (int i = 0; i < n; i++) {
//        int first , second = 0;
//        scanf("%d %d" , &first , &second);
//        vt.push_back({first,second});
//    }
//
//    sort(vt.begin(), vt.end());
//    for (int i = 0; i < n; i++) {
//        int start = vt[i].first;
//        int end = vt[i].second;
//        int block = 0;
//        if(start > space){ //포장을 새로 해야된다.
//            if((end-start)%l == 0) block = (end-start)/l;
//            else block = (end-start)/l+1;
//            cnt += block;
//            space = start + l*block;
//        }else{ //겹치는 부분이 있다 => 1. 완전히 겹치는지 2. 더 깔아야되는지
//            int newStart = space;
//            if(newStart > end) continue;
//            else{
//                if((end-newStart)%l == 0) block = (end-newStart)/l;
//                else block = (end-newStart)/l+1;
//                cnt += block;
//                space = newStart + l*block;
//            }
//        }
//    }
//    printf("%d" , cnt);
//}
//
//
//
//
