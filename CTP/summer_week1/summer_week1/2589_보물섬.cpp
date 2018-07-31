////
////  2589_보물섬.cpp
////  summer_week1
////
////  Created by Hoon on 2018. 7. 30..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <queue>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//int n,m,maxx;
//string input;
//char map[54][54];
//bool visited[54][54];
//queue<pair<int, int>> qu;
//int dx[4] = {1,-1,0,0};
//int dy[4] = {0,0,1,-1};
//
//bool isposs(int y ,int x){
//    return x>=0 && y >=0 && y<n && x<m;
//}
//
//int bfs(int y , int x){
//    int cnt = 0;
//    visited[y][x] = true;
//    qu.push({y,x});
//    while (int s = qu.size()) {
//        while (s--) {
//            int Y = qu.front().first;
//            int X = qu.front().second;
//            qu.pop();
//
//            for (int i = 0; i < 4; i++) {
//                int yy = Y + dy[i];
//                int xx = X + dx[i];
//
//
//                if(isposs(yy, xx) == false) continue;
//                if(map[yy][xx] == 'L' && visited[yy][xx] == false){
//                    visited[yy][xx] = true;
//                    qu.push({yy,xx});
//                }
//            }
//        }
//        cnt++;
//    }
//    return cnt;
//}
//
//
//int main(){
//    scanf("%d %d" , &n,&m);
//    getchar();
//    for (int i = 0; i < n; i++) {
//        getline(cin,input);
//        for (int j = 0 ; j < m; j++) {
//            map[i][j] = input[j];
//        }
//    }
//
//    for (int i = 0 ; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            memset(visited,0,sizeof(visited));
//            if(map[i][j] == 'L' && visited[i][j] == false){
//                int ans = bfs(i,j);
//                maxx = max(maxx , ans);
//            }
//        }
//    }
//    printf("%d" , maxx-1);
//}

