#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

char map[20][20];
bool globalVisited[20][20];

bool isPoss(int y, int x) {
    return 0 <= y && y < 12 && 0 <= x && x < 6;
}

int bfs(int sy, int sx, char color) {
    bool visited[20][20] = {0,};
    queue<pair<int, int > > qu;
    visited[sy][sx] = true;
    globalVisited[sy][sx] = true;
    qu.push(make_pair(sy, sx));

    int sameColorCnt = 0;
    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();
            sameColorCnt++;

            for(int i = 0 ; i < 4 ; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(isPoss(yy, xx) == false) continue;
                if(visited[yy][xx]) continue;
                if(map[yy][xx] != color) continue;

                globalVisited[yy][xx] = true;
                visited[yy][xx] = true;
                qu.push(make_pair(yy,xx));
            }
        }
    }

    if(sameColorCnt >= 4) {
        for(int i = 0 ; i < 12; i++) {
            for(int j = 0 ; j < 6 ; j++) {
                if(visited[i][j]) map[i][j] = '.';
            }
        }
        return 1;
    }
    return 0;
}

void clearMap() {
    for(int i = 0 ; i < 6 ; i++) {
        for(int j = 11 ; j >= 0 ; j--) {
            if(map[j][i] == '.') {
                int k = j;
                while(1) {
                    k--;
                    if(k == -1) break;

                    if(map[k][i] == '.') continue;
                    else {
                        map[j][i] = map[k][i];
                        map[k][i] = '.';
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    for(int i = 0 ; i < 12; i++) {
        for(int j = 0 ; j < 6 ; j++) {
            scanf("%c", &map[i][j]);
        }
        getchar();
    }

    int ans = 0;
    while(1) {
        bool isBoomed = false;
        memset(globalVisited, 0, sizeof(globalVisited));
        for(int i = 0 ; i < 12 ; i++) {
            for(int j = 0 ; j < 6 ; j++) {
                if(globalVisited[i][j] == false && map[i][j] != '.') {
                    if(bfs(i, j, map[i][j])) isBoomed = true;
                }
            }
        }

        if(isBoomed) {
            // 맵 정렬
            clearMap();
            ans++;
        }
        else break;
    }
    printf("%d\n", ans);
}