////  https://www.acmicpc.net/problem/1261
////  1261_알고스팟.cpp
////  summer_week5-1
////
////  Created by Hoon on 2018. 7. 31..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <cstring>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int n,m;
//string input;
//int map[104][104];
//int wall[104][104];
//int dy[4] = {0,0,1,-1};
//int dx[4] = {1,-1,0,0};
//priority_queue<pair<int, pair<int, int>>> pq;
//
//bool isposs(int y,  int x){
//    return x>=0 && y>=0 && x<m && y<n;
//}
//
//void dij(int y,int x){
//    pq.push({0,{y,x}});
//    while (!pq.empty()) {
//        int cost = -pq.top().first;
//        int Y = pq.top().second.first;
//        int X = pq.top().second.second;
//        pq.pop();
//
//        if(wall[Y][X] != -1) continue;
//        wall[Y][X] = cost;
//
//        for (int i = 0; i < 4; i++) {
//            int yy = Y + dy[i];
//            int xx = X + dx[i];
//            int ncost = cost;
//            if(map[yy][xx] == 1) ncost++;
//            if(isposs(yy,xx) == false) continue;
//
//            if(wall[yy][xx] == -1) pq.push({-ncost,{yy,xx}});
//        }
//    }
//}
//
//void init(){
//    for (int i = 0; i < n; i++) memset(wall[i], -1, sizeof(wall[i]));
//}
//
//int main(){
//    scanf("%d %d" , &m, &n);
//    init();
//    getchar();
//    for (int i = 0; i < n; i++) {
//        getline(cin,input);
//        for (int j= 0; j < m; j++) {
//            map[i][j] = input[j]-'0';
//        }
//    }
//
//    dij(0,0);
//
//    printf("%d" , wall[n-1][m-1]);
//}

