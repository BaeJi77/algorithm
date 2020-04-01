#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int N;
bool visited[110][110];
char map[110][110];

bool isPoss(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

void bfs(int sy, int sx, char color, int base) {
    queue<pair<int ,int> > qu;
    visited[sy][sx] = true;
    qu.push(make_pair(sy, sx));

    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();

            for(int i = 0 ; i < N ; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(isPoss(yy, xx) == false) continue;
                if(visited[yy][xx]) continue;
                if(base == 0) { // No색약
                    if(map[yy][xx] != color) continue;
                } else if (base == 1) { // Yes색약
                    if(color == 'B' && (map[yy][xx] == 'R' || map[yy][xx] == 'G')) continue;
                    if(map[yy][xx] == 'B' && color != 'B') continue;
                }
                
                visited[yy][xx] = true;
                qu.push(make_pair(yy, xx));
            }
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < N ; j++) {
            scanf("%c", &map[i][j]);
        }
    }

    int normalCnt = 0;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            if(visited[i][j] == false) {
                bfs(i, j, map[i][j], 0);
                normalCnt++;
            }
        }
    }

    int oddCnt = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            if(visited[i][j] == false) {
                bfs(i, j, map[i][j], 1);
                oddCnt++;
            }
        }
    }

    printf("%d %d", normalCnt, oddCnt);
}