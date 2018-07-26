////
////  1049_기타 줄.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 25..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <limits.h>
//#include <queue>
//#include <cmath>
//using namespace std;
//
//int n,m,sum;
//int minn = INT_MAX;
//vector<pair<int, int>> vt;
//vector<pair<int, double>> sixMoney;
//vector<pair<int, int>> oneMoney;
//priority_queue<int> pq;
//int main(){
//    scanf("%d %d" , &n,&m);
//    for (int i = 0; i < m; i++) {
//        int six,one;
//        scanf("%d %d" , &six,&one);
//        vt.push_back({six,one});
//        sixMoney.push_back({six , (n/6)*six});
//        oneMoney.push_back({one, (n%6)*one});
//    }
//
//    //3가지 경우 => 1. 온니 세트 2. 세트+낫개 3. 온니 낫개
//    for (int i = 0; i < m; i++) {
//        double temp = ((double)n/(double)6);
//        int set = (int)ceil(temp)*vt[i].first;
//        pq.push(-set);
//    }
//
//    for (int i = 0; i < m; i++) {
//        pq.push(-vt[i].second*n);
//    }
//
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < m; j++) {
//            int insert = (n/6)*vt[i].first + (n%6)*vt[j].second;
//            pq.push(-insert);
//        }
//    }
//
//    printf("%d" , -pq.top());
//}

