////  https://www.acmicpc.net/problem/5427
////  5427_불.cpp
////  summer_week1
////
////  Created by Hoon on 2018. 7. 29..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//queue<pair<int, int>> people;
//queue<pair<int, int>> fire;
//int t,w,h,TIME,sw,sh;
//string line;
//int map[1004][1004];
//bool visited[1004][1004];
//bool firevisited[1004][1004];
//int dx[4] = {0,0,-1,1};
//int dy[4] = {1,-1,0,0};
//
//bool out(int y, int x){
//    return y == 0 || y == h-1 || x == 0 || x == w - 1;
//}
//
//bool poss(int y, int x){
//    return y>=0 && y<h && x>=0 && x<w;
//}
//
//int bfs(int y, int x){
//    memset(visited,0,sizeof(visited));
//    memset(firevisited,0,sizeof(firevisited));
//    TIME = 0;
//    visited[y][x] = true;
//    people.push({y,x});
//    while (int s = people.size()) {
//        int fireSize = fire.size();
//        while (fireSize--) {
//            int Y = fire.front().first;
//            int X = fire.front().second;
//            fire.pop();
//
//            for (int i = 0; i < 4; i++) {
//                int yy = Y+dy[i];
//                int xx = X+dx[i];
//
//                if(poss(yy, xx) == false) continue;
//                //1은 벽 => 벽만 아니고 비짓만 안되있으면 모두 불로 만든다.
//                if(map[yy][xx] != 1 && firevisited[yy][xx] == false){
//                    firevisited[yy][xx] = true;
//                    map[yy][xx] = 3;
//                    fire.push({yy,xx});
//                }
//            }
//        }
//
//        while (s--) {
//            int Y = people.front().first;
//            int X = people.front().second;
//            people.pop();
//
//            //현재 위치가 이동가능한 공간이고 가장자리면 리턴
//            if(map[Y][X] == 0 && out(Y,X)) return TIME;
//
//            for (int i = 0; i < 4; i++) {
//                int yy = Y + dy[i];
//                int xx = X + dx[i];
//
//                if(poss(yy, xx) == false) continue;
//
//                //0은 이동가능한 공간 => 그 공간만 인간이 갈 수 있다.
//                if (map[yy][xx] == 0 && visited[yy][xx] == false) {
//                    visited[yy][xx] = true;
//                    map[yy][xx] = 2;
//                    people.push({yy,xx});
//                }
//            }
//        }
//        TIME++;
//    }
//    return -1;
//}
//
//int main(){
//    scanf("%d" , &t);
//    while (t--) {
//        while(fire.size()) fire.pop();
//        while(people.size()) people.pop();
//        scanf("%d %d" , &w , &h);
//        getchar();
//        for (int i = 0; i < h; i++) {
//            getline(cin,line);
//            for (int j = 0; j < w; j++) {
//                char letter = line[j];
//                if(letter == '.'){ //이동가능한 공간
//                    map[i][j] = 0;
//                }else if(letter == '#'){ //벽
//                    map[i][j] = 1;
//                }else if(letter == '@'){ //현재 나의 위치
//                    map[i][j] = 2;
//                    sh = i;
//                    sw = j;
//                }else{                  // 불
//                    map[i][j] = 3;
//                    fire.push({i,j});
//                    visited[i][j] = true;
//                }
//            }
//        }
//
//        int ans = bfs(sh,sw);
//        if(ans == -1) cout<<"IMPOSSIBLE\n";
//        else printf("%d\n" , ans);
//    }
//}

