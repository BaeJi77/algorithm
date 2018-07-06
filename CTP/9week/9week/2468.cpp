//
//  2468.cpp
//  111
//
//  Created by Hoon on 2018. 6. 3..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int box[110][110];
int maxval = 0;
int ans = 1;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool ispossible(int y, int x) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < n);
}
bool visited[110][110];
void dfs(int y, int x,int rain) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ispossible(ny, nx) &&!visited[ny][nx] && (box[ny][nx] - rain > 0))
        dfs(ny, nx,rain);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &box[i][j]);
            maxval = max(maxval, box[i][j]);
        }
    }

    for (int i = 1; i < maxval; i++) {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (!visited[j][k] && (box[j][k] - i>0)) {
                    dfs(j, k, i);
                    cnt++;
                }
            }
        }
        ans = max(cnt, ans);
    }

    printf("%d", ans);

}

