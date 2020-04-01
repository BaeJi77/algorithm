#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int dy[] = {0, 0, 0, 0, 1, -1};
const int dx[] = {0, 0, 1, -1, 0, 0};
const int dh[] = {1, -1, 0, 0, 0, 0};

int N, M, H;
int map[110][110][110];
bool visited[110][110][110];
queue<pair<int, pair<int, int> > > qu;

bool isPoss(int h, int y, int x) {
    return 0 <= h && h < H && 0 <= y && y < N && 0 <= x && x < M;
}

int bfs() {
    int cnt = 0;
    while(int s = qu.size()) {
        while(s--) {
            int nowh = qu.front().first;
            int nowy = qu.front().second.first;
            int nowx = qu.front().second.second;
            qu.pop();

            for(int i = 0 ; i < 6 ; i++) {
                int h = nowh + dh[i];
                int y = nowy + dy[i];
                int x = nowx + dx[i];

                if(isPoss(h, y, x) == false) continue;
                if(visited[h][y][x]) continue;
                if(map[h][y][x] != 0) continue;

                visited[h][y][x] = true;
                qu.push(make_pair(h, make_pair(y, x)));
            }
        }
        cnt++;
    }

    return cnt - 1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d %d", &M, &N, &H);
    for(int i = 0 ; i < H ; i++) {
        for(int j = 0 ; j < N ; j++) {
            for(int k = 0 ; k < M ; k++) {
                scanf("%d", &map[i][j][k]);
                if(map[i][j][k] == 1) {
                    qu.push(make_pair(i, make_pair(j, k)));
                    visited[i][j][k] = true;
                }
            }
        }
    }

    int ans = bfs();
    
    for(int i = 0 ; i < H ; i++) {
        for(int j = 0 ; j < N ; j++) {
            for(int k = 0 ; k < M ; k++) {
                if(map[i][j][k] == 0 && visited[i][j][k] == false) {
                    printf("-1");
                    return 0;
                }
            }
        }
    }

    printf("%d", ans);
}