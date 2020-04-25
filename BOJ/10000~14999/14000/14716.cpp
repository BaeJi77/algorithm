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
int map[260][260];
bool visited[260][260];

bool isInside(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void bfs(int sy, int sx) {
    queue<pair<int, int> > qu;
    visited[sy][sx] = true;

    qu.push(make_pair(sy, sx));
    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();
            // printf("%d %d %d %d\n", sy, sx ,y, x);

            for(int i = 0 ; i < 8 ; ++i) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(isInside(yy, xx) == false) continue;
                if(map[yy][xx] == 0) continue;
                if(visited[yy][xx]) continue;

                qu.push(make_pair(yy, xx));
                visited[yy][xx] = true;
            }
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            if(map[i][j] == 0) continue;
            if(visited[i][j]) continue;
            bfs(i, j);
            ans++;
        }
    }
    printf("%d", ans);
}