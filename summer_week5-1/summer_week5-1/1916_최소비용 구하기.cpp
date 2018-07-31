////  https://www.acmicpc.net/problem/1916
////  1916_최소비용 구하기.cpp
////  summer_week5-1
////
////  Created by Hoon on 2018. 7. 30..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//int v,e,start,ended;
//int dist[1004];
//vector<vector<pair<int, int>>> vt;
//priority_queue<pair<int,int>> pq;
//
//
//void dijkstra(int start){
//    pq.push({0,start});
//    while (!pq.empty()) {
//        int here = pq.top().second;
//        int cost = -pq.top().first;
//        pq.pop();
//
//        if(dist[here] != -1) continue;
//        dist[here] = cost;
//
//        for (int i = 0; i < vt[here].size(); i++) {
//            int there = vt[here][i].first;
//            int ncost = vt[here][i].second + cost;
//            if(dist[there] == -1) pq.push({-ncost,there});
//        }
//    }
//}
//
//int main(){
//    scanf("%d %d" , &v,&e);
//    vt.resize(v+1);
//    for (int i = 0; i < e; i++) {
//        int a,b,c;
//        scanf("%d %d %d" , &a,&b,&c);
//        vt[a].push_back({b,c});
//    }
//    scanf("%d %d" , &start , &ended);
//
//    memset(dist,-1,sizeof(dist));
//    dijkstra(start);
//
//    printf("%d" , dist[ended]);
//
//}

