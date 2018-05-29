////
////  4963.cpp
////  111
////
////  Created by Hoon on 2018. 5. 22..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <cstring>
//
//using namespace std;
//
//int w,h,in,cnt;
//int arr[60][60];
//bool visited[60][60];
////좌상 상 우상 좌하 하 좌하  좌 우
////-1  0  1  -1  0  1  -1  1
////1   1  1  -1 -1 -1   0  0
//int xx[8] = {1,1,1,-1,-1,-1,0,0};
//int yy[8] = {1,0,-1,1,0,-1,1,-1};
//
//void dfs(int x, int y){
//    visited[x][y] = true;
//    for(int i = 0 ; i < 8 ; i++){
//        int dx = x+xx[i];
//        int dy = y+yy[i];
//
//        if(dx<0 || dy <0 || dx > h || dy > w) continue;
//        if(visited[dx][dy] == true) continue;
//        if(arr[dx][dy] == false) continue;
//        dfs(dx, dy);
//    }
//}
//
//int main(){
//    while (1) {
//        memset(arr, 0, sizeof(arr));
//        memset(visited, 0, sizeof(visited));
//        scanf("%d %d" , &w, &h);
//        if(w==0 && h==0) break;
//        for (int i = 0; i < h; i++) {
//            for(int j = 0 ; j < w ; j++){
//                scanf("%d" , &arr[i][j]);
//            }
//        }
//
//        for(int i = 0 ; i < h; i++){
//            for(int j = 0 ; j < w ; j++){
//                if(arr[i][j] == true && visited[i][j] == false){
//                    dfs(i, j);
//                    cnt++;
//                }
//            }
//        }
//
//        printf("%d\n" , cnt);
//        cnt = 0;
//    }
//}

