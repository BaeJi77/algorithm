////  https://www.acmicpc.net/problem/1753
////  1753_최단경로.cpp
////  summer_week5-1
////
////  Created by Hoon on 2018. 7. 30..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//int v,e,k;
//int dist[20004];
//vector<vector<pair<int, int>>> vt;
//priority_queue<pair<int , int>> pq;
//
//void dijkstra(){
//    pq.push({0,k});
//    while (!pq.empty()) {
//        int cost = -pq.top().first;
//        int here = pq.top().second;
//        pq.pop();
//
//        if(dist[here] != -1) continue;
//        dist[here] = cost;
//        for (int i = 0; i < vt[here].size(); i++) {
//            int there = vt[here][i].first;
//            int ncost = vt[here][i].second + cost;
//            if(dist[there] == -1) pq.push({-ncost,there});
//        }
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    scanf("%d %d" , &v, &e);
//    scanf("%d", &k);
//    vt.resize(v+1);
//    memset(dist,-1,sizeof(dist));
//
//    for (int i = 0; i < e; i++) {
//        int a, b, c;
//        scanf("%d %d %d" , &a,&b,&c);
//        vt[a].push_back({b,c});
//    }
//
//    dijkstra();
//
//    for (int i = 1 ; i <= v; i++) {
//        if(dist[i] != -1)printf("%d\n" , dist[i]);
//        else cout<<"INF\n";
//    }
//}

