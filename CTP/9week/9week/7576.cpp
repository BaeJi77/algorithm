//
//  7576.cpp
//  111
//
//  Created by Hoon on 2018. 6. 2..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;
int n, m;
int box[1100][1100];
int days = -1;
queue<pair<int, int>> qu;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int notegg;

bool ispossible(int y, int x) {
    return (y >= 0) && (x >= 0) && (y < n) && (x < m);
}

void bfs() {
    while (int s = qu.size()) {
        while (s--) {
            int yv = qu.front().first;
            int xv = qu.front().second;
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int ny = yv + dy[i];
                int nx = xv + dx[i];
                if (ispossible(ny, nx) && box[ny][nx] == 0) {
                    notegg--;
                    box[ny][nx] = 1;
                    qu.push({ ny,nx });
                }
            }
        }
        days++;
    }
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &box[i][j]);

            if (box[i][j] == 1)
            qu.push({ i,j });

            else if (box[i][j] == 0)
            notegg++;
        }
    }

    bfs();

    if (notegg != 0) {
        puts("-1");
        return 0;
    }

    printf("%d", days);
}

