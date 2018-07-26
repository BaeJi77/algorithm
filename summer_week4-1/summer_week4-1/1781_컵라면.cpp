////
////  1781_컵라면.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 24..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <queue>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int n,Time,nowPriority,maxx,sum;
//priority_queue<int> pq;
//vector<pair<int, int>> vt;
//int main(){
//    scanf("%d" , &n);
//    for (int i = 0; i < n; i++) {
//        int a,b;
//        scanf("%d %d" , &a,&b);
//        vt.push_back({a,b});
//    }
//    
//    sort(vt.begin(), vt.end());
//    
//    for (int i = 0; i < n; i++) {
//        int DL = vt[i].first;
//        int cup = vt[i].second;
//        pq.push(-cup);
//        
//        while (pq.size() > DL) {
//            pq.pop();
//        }
//    }
//    
//    while (!pq.empty()) {
//        sum += -pq.top();
//        pq.pop();
//    }
//    
//    
//    printf("%d" , sum);
//}

