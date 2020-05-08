#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

const int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dx[] = {1, 0, -1, 1, -1, 1, 0, -1};

int N, M;
int map[501][501];
pair<int, int> dp[501][501];
int ans[501][501];

bool isPoss(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int finishOrMove(int y, int x) {
    int idx = -1;
    int minValue = 3e5 + 1;
    for(int i = 0 ; i < 8 ; ++i) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(isPoss(yy, xx) == false) continue;
        if(map[y][x] < map[yy][xx]) continue;
        if(minValue > map[yy][xx]) {
            minValue = map[yy][xx];
            idx = i;
        }
    }

    return idx;
}

pair<int, int> solve(int y, int x) {
    if(dp[y][x].first != -1 && dp[y][x].second != -1)
        return dp[y][x];

    int targetIdx = finishOrMove(y, x);
    if(targetIdx == -1) {
        return make_pair(y, x);
    } 

    return dp[y][x] = solve(y + dy[targetIdx], x + dx[targetIdx]);
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            dp[i][j] = make_pair(-1, -1);
        }
    }

    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            pair<int, int> now = solve(i, j);
            ans[now.first][now.second]++;
        }
    }

    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) 
            printf("%d ", ans[i][j]);
        puts("");
    }
}