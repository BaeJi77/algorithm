#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1 ,0, 0};

int N, M;
char map[60][60];
int seaMap[60][60];
bool visited[60][60];
int sy, sx;
queue<pair<int, int> > sea;

bool isPoss(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void seaBfs() {
    memset(seaMap, -1, sizeof(seaMap));
    int cnt = 0;
    while(int s = sea.size()) {
        while(s--) {
            int y = sea.front().first;
            int x = sea.front().second;
            sea.pop();
            seaMap[y][x] = cnt;

            for(int i = 0 ; i < 4 ; i++) {
                int yy = dy[i] + y;
                int xx = dx[i] + x;
                if(isPoss(yy, xx) == false) continue;
                if(visited[yy][xx]) continue;
                if(map[yy][xx] == 'D' || map[yy][xx] == 'X') continue;

                visited[yy][xx] = true;
                sea.push(make_pair(yy, xx));
            }
        }
        cnt++;
    }
}

int bfs() {
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > qu;

    visited[sy][sx] = true;
    qu.push(make_pair(sy, sx));
    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();

            if(map[y][x] == 'D') return cnt;

            for(int i = 0 ; i < 4; i++) {
                int yy = dy[i] + y;
                int xx = dx[i] + x;

                if(isPoss(yy, xx) == false) continue;
                if(visited[yy][xx]) continue;
                if(map[yy][xx] == 'X' || map[yy][xx] == '*') continue;
                if(seaMap[yy][xx] == -1 || seaMap[yy][xx] > cnt + 1 || map[yy][xx] == 'D') {
                    visited[yy][xx] = true;
                    qu.push(make_pair(yy, xx));
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M ; j++) {
            scanf("%c", &map[i][j]);
            if(map[i][j] == '*') {
                visited[i][j] = true;
                sea.push(make_pair(i, j));
            }
            if(map[i][j] == 'S') sy = i, sx = j;
        }
    }

    seaBfs();
    int ret = bfs();
    if(ret == -1) printf("KAKTUS");
    else printf("%d", ret);
}