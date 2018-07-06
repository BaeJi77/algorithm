////
////  2178.cpp
////  111
////
////  Created by Hoon on 2018. 6. 1..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//#include <queue>
//using namespace std;
//
//int n, m;
//char box[110][110];
//int dist = 0;
//int dy[4] = { 1,0,-1,0 };
//int dx[4] = { 0,1,0,-1 };
//
//bool ispossible(int y, int x) {
//    return (x >= 0) && (y >= 0) && (x < m) && (y < n);
//}
//void bfs(int y, int x) {
//    
//    queue<pair<int, int>> qu;
//    qu.push({ y,x });
//    while (int s = qu.size()) {
//        while (s--) {
//            int yv = qu.front().first;
//            int xv = qu.front().second;
//            
//            if (yv == n - 1 && xv == m - 1)
//            return;
//            
//            qu.pop();
//            for (int i = 0; i < 4; i++) {
//                int ny = yv + dy[i];
//                int nx = xv + dx[i];
//                if (ispossible(ny, nx) && box[ny][nx] == '1') {
//                    box[ny][nx] = '0';
//                    qu.push({ ny,nx });
//                }
//            }
//        }
//        dist++;
//    }
//}
//int main() {
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; i++) {
//        getchar();
//        for (int j = 0; j < m; j++) {
//            scanf("%c", &box[i][j]);
//        }
//    }
//    bfs(0, 0);
//    printf("%d", dist+1);
//}

