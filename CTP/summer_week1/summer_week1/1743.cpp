////
////  1743.cpp
////  summer_week1
////
////  Created by Hoon on 2018. 7. 4..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <cstring>
//using namespace std;
//int map[110][110];
//int n,m,k,mmax,cnt; //n은 세로 m은 가로
//int a,b;
//int dx[4] = {1,-1,0,0};
//int dy[4] = {0,0,1,-1};
//bool visited[110][110];
//
//void dfs(int y,int x){
//    visited[y][x] = true;
//    cnt++;
//    for (int i = 0 ; i < 4; i++) {
//        int yy = dy[i] + y;
//        int xx = dx[i] + x;
//        if(xx < 0 || yy < 0 || xx > m || y > n) continue;
//        if(visited[yy][xx] == true) continue;
//        if(map[yy][xx] == false) continue;
//        dfs(yy,xx);
//    }
//}
//
//int main(){
//    scanf("%d %d %d",&n,&m,&k);
//    while (k--) {
//        scanf("%d %d" , &a,&b);
//        map[a][b] = 1;
//    }
//    
//    for (int i = 1 ; i <= n; i++) {
//        for (int j = 1 ; j <= m; j++) {
//            if(map[i][j] == true && visited[i][j] == false){
//                dfs(i,j);
//                if(cnt > mmax) {
//                    mmax = max(cnt,mmax);
//                }
//                cnt = 0;
//            }
//        }
//    }
//    printf("%d" , mmax);
//}

