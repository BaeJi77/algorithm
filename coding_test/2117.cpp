#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int t, N, M;
int map[21][21];
bool visited[21][21];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool isposs(int y, int x) {
    return y >= 0 && x >= 0 && y < N && x < N;
}

int calCost(int k) {
    return k * k + (k-1) * (k-1);
}

int bfs(int y, int x) {
    int cnt = 0;
    int ret = -1;
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > qu;
    qu.push(make_pair(y, x));
    visited[y][x] = true;

    int k = 0;
    while(int s = qu.size()) {
        while(s--) {
            int yy = qu.front().first;
            int xx = qu.front().second;
            qu.pop();
            if(map[yy][xx] == 1)
                cnt++;

            for(int i = 0 ; i < 4; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if(!isposs(ny, nx) || visited[ny][nx])
                    continue;
                visited[ny][nx] = true;
                qu.push(make_pair(ny, nx));
            }
        }
        k++;
        int nowCost = calCost(k);
        if(nowCost <= cnt * M) {
            ret = cnt;
        }
    }

    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &t);
    for(int tc = 1; tc <= t ; tc++) {
        scanf("%d %d", &N, &M);
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int ans = -1;
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                ans = max(ans, bfs(i, j));
            }
        }

        printf("#%d %d\n", tc, ans);
    }
}