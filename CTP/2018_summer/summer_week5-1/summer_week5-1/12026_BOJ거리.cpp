////
////  12026_BOJ거리.cpp
////  summer_week5-1
////
////  Created by Hoon on 2018. 8. 1..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//#include <vector>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//int n;
//int inputToNumber[1004];
//int dist[1004];
//vector<vector<pair<int, int>>> vt;
//priority_queue<pair<int, int>> pq;
//
//void dij(){
//    pq.push({0,0});
//    while (!pq.empty()) {
//        int here = pq.top().second;
//        int cost = -pq.top().first;
//        pq.pop();
//
//        if(dist[here] != -1)continue;
//        dist[here] = cost;
//
//        for (int i = 0; i < vt[here].size(); i++) {
//            int there = vt[here][i].first;
//            int ncost = vt[here][i].second + cost;
//
//            if(dist[there] == -1) pq.push({-ncost,there});
//        }
//    }
//}
//
//int main(){
//    scanf("%d" , &n);
//    getchar();
//    vt.resize(n+1);
//    memset(dist,-1,sizeof(dist));
//    for (int i = 0; i < n; i++) {
//        char input;
//        scanf("%c" , &input);
//        if(input =='B') inputToNumber[i] = 0;
//        if(input =='O') inputToNumber[i] = 1;
//        if(input == 'J') inputToNumber[i] = 2;
//    }
//
//    for (int i = 0; i < n-1; i++) {
//        int energy = 0;
//        for (int j = i+1; j < n; j++) {
//            energy++;
//            if(inputToNumber[i] == 0 && inputToNumber[j] == 1){
//                vt[i].push_back({j,energy*energy});
//            }else if(inputToNumber[i] == 1 && inputToNumber[j] == 2){
//                vt[i].push_back({j,energy*energy});
//            }else if(inputToNumber[i] == 2 && inputToNumber[j] == 0){
//                vt[i].push_back({j,energy*energy});
//            }
//        }
//    }
//
//    dij();
//
//    printf("%d" , dist[n-1]);
//}
//
