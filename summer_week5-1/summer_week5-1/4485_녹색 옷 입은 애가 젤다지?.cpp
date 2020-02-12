////  https://www.acmicpc.net/problem/4485
////  4485_녹색 옷 입은 애가 젤다지?.cpp
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
//
//using namespace std;
//
//int v,outNumber;
//int dist[130][130];
//int map[130][130];
//priority_queue<pair<int,pair<int, int>>> pq;
//int dx[4] = {1,-1,0,0};
//int dy[4] = {0,0,1,-1};
//
//
//bool isposs(int y ,int x){
//    return y>=0 && x>=0 && y<v && x<v;
//}
//
//void dij(int y,int x){
//    pq.push({-map[y][x],{y,x}});
//    while (!pq.empty()) {
//        int cost = -pq.top().first;
//        int X = pq.top().second.second;
//        int Y = pq.top().second.first;
//        pq.pop();
//
//        if(dist[Y][X] != -1) continue;
//        dist[Y][X] = cost;
//
//        for (int i = 0; i < 4; i++) {
//            int yy = Y+dy[i];
//            int xx = X+dx[i];
//            int ncost = map[yy][xx] + cost;
//            if(isposs(yy, xx) == false) continue;
//            if(dist[yy][xx] == -1) pq.push({-ncost,{yy,xx}});
//        }
//    }
//}
//
//int main(){
//    while (scanf("%d" , &v)) {
//        if(v == 0) break;
//        outNumber++;
//        for (int i = 0; i < v; i++) memset(dist[i],-1,sizeof(dist[i]));
//        
//        for (int i = 0 ; i < v; i++) {
//            for (int j = 0; j < v; j++) {
//                scanf("%d" , &map[i][j]);
//            }
//        }
//
//        dij(0,0);
//        printf("Problem %d: %d\n" , outNumber , dist[v-1][v-1]);
//    }
//}
//
//
