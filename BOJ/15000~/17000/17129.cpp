#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int N, M;
queue<pair<int, int>> qu;
int sy, sx;
int map[3010][3010];
bool visited[3010][3010];

bool isPoss(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int bfs() {
    visited[sy][sx] = true;
    qu.push({sy, sx});

    int cnt = 0;
    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;  
            qu.pop();

            if(map[y][x] == 3 || map[y][x] == 4 || map[y][x] == 5) {
                return cnt;
            }

            for(int i = 0 ; i < 4 ; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(isPoss(yy, xx) == false) continue;
                if(visited[yy][xx]) continue;
                if(map[yy][xx] == 1) continue;
                qu.push({yy, xx});
                visited[yy][xx] = true;
            }
        }
        cnt++;
    }

    return -1;
}


int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M ; j++) {
            char input;
            scanf("%c", &input);
            map[i][j] = input - '0';
            if(map[i][j] == 2) {
                sy = i;
                sx = j;
            }
        }
    }

    int ans = bfs();
    if(ans == -1) printf("NIE");
    else printf("TAK\n%d", ans);
}