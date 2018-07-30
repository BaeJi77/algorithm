////
////  4991_로봇 청소기.cpp
////  summer_week1
////
////  Created by Hoon on 2018. 7. 29..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//
//// 문제점.... 메모리 초과!!!
//
//#include <stdio.h>
//#include <vector>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//char map[24][24];
//int w,h,sx,sy,cnt,ans;
//bool imposs;
//int dx[8] = {1,1,1,0,0,-1,-1,-1};
//int dy[8] = {1,0,-1,1,-1,1,0,-1};
//bool visited[24][24];
//vector<pair<int, int> > vt;
//queue<pair<int , int> > qu;
//
//bool isposs(int y,int x){
//    return x>=0 && y>=0 && x<w && y<h;
//}
//
//bool dirt(int y, int x){
//
//    for (int i = 0 ; i < vt.size(); i++) {
//        int yy = vt[i].first;
//        int xx = vt[i].second;
//
//
//        if(yy == y && xx == x) {
////            printf("%d %d %d %d\n" , yy ,xx ,y ,x);
//            vt.erase(vt.begin()+i);
//            return true;
//        }
//    }
//    return false;
//}
//
//void bfs(int y, int x){
//    cnt = 0;
//    if(vt.size() == 0) return;
//    memset(visited,0,sizeof(visited));
//    while (qu.size()) qu.pop();
//    visited[y][x] = true;
//    qu.push({y,x});
//    while (int s = qu.size()) {
//        while (s--) {
//            int Y = qu.front().first;
//            int X = qu.front().second;
//            qu.pop();
//
//            if(dirt(Y, X)) {
//                ans += cnt;
//                bfs(Y, X);
//                return;
//            }
//
//            for (int i = 0; i < 8; i++) {
//                int yy = Y + dy[i];
//                int xx = X + dx[i];
//
//                if(isposs(yy, xx) == false) continue;
//                if(map[yy][xx] != 'x'&& visited[yy][xx] == false){
//                    visited[yy][xx] = true;
//                    qu.push({yy,xx});
//                }
//            }
//        }
//        cnt++;
//    }
//    imposs = true;
//}
//
//
//int main(){
//    while (scanf("%d %d" , &w ,&h)) {
//        if(w==0 && h==0) break;
//        ans = 0;
//        vt.clear();
//        while (qu.size()) qu.pop();
//
//        for (int i = 0; i < h; i++) {
//            getchar();
//            for (int j = 0; j < w; j++) {
//                scanf("%c" , &map[i][j]);
//                if(map[i][j] == 'o') {
//                    sy = i;
//                    sx = j;
////                    map[i][j] = '.';
//                }else if(map[i][j] =='*'){
//                    vt.push_back(make_pair(i, j));
//                }
//            }
//        }
//
//        bfs(sy,sx);
//
//        if(imposs) printf("%d" , -1);
//        else printf("%d\n" , ans);
//    }
//}

