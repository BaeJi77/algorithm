////  https://www.acmicpc.net/problem/10282
////  10282_해킹.cpp
////  summer_week5-1
////
////  Created by Hoon on 2018. 7. 30..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int test,v,e,start;
//int dist[10004];
//vector<vector<pair<int, int>>> vt;
//priority_queue<pair<int,int>> pq;
//
//void dijkstra(int start){
//    pq.push({0,start});
//    while (!pq.empty()) {
//        int here = pq.top().second;
//        int cost = -pq.top().first;
//        pq.pop();
//        if(dist[here] != -1) continue;
//        dist[here] = cost;
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
//    scanf("%d" , &test);
//    while (test--) {
//        scanf("%d %d %d" , &v,&e,&start);
//        vt.clear();
//        vt.resize(v+1);
//        memset(dist,-1,sizeof(dist));
//        while (pq.size()) pq.pop();
//        for (int i = 0; i < e; i++) {
//            int a,b,c;
//            scanf("%d %d %d" , &a,&b,&c);
//            vt[b].push_back({a,c});
//        }
//
//        dijkstra(start);
//        int cnt = 0;
//        int maxx = 0;
//        for (int i = 1; i <= v; i++) {
//            if(dist[i] != -1) cnt++;
//            maxx = max(maxx , dist[i]);
//        }
//        printf("%d %d\n" , cnt,maxx);
//    }
//}

