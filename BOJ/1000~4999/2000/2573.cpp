#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int dy[] = {0, 0, 1 ,-1};
const int dx[] = {1, -1, 0, 0};

int N, M;
int map[310][310];
int tempMap[310][310];
bool visited[310][310];

void copyMap(int flag) {
    if(flag == 0) {
        for(int i = 1 ; i <= N ; i++) 
            for(int j = 1 ; j <= M ; j++) 
                tempMap[i][j] = map[i][j];
    } else {
        for(int i = 1 ; i <= N ; i++) 
            for(int j = 1 ; j <= M ; j++) 
                map[i][j] = tempMap[i][j];
    }
}

bool isPoss(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= M;
}

void bfs(int sy, int sx) {
    queue<pair<int ,int > > qu;
    qu.push(make_pair(sy, sx));
    visited[sy][sx] = true;

    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();
            
            int nearIceCnt = 0;
            for(int i = 0 ; i < 4 ; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(isPoss(yy, xx) == false || map[yy][xx] == 0) {
                    nearIceCnt++; 
                    continue;
                }
                if(visited[yy][xx]) continue;
                visited[yy][xx] = true;
                qu.push(make_pair(yy, xx));
            }
            if(tempMap[y][x] <= nearIceCnt) tempMap[y][x] = 0;
            else tempMap[y][x] -= nearIceCnt;
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1 ; i <= N ; i++) {
        for(int j = 1 ; j <= M ; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int ansYear = 0;
    while(1) {
        int cnt = 0;
        memset(visited,0,sizeof(visited));
        copyMap(0);
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= M ; j++) {
                if(map[i][j] != 0 && visited[i][j] == false) {
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        copyMap(1);

        if(cnt == 0) { // 다 녹음
            printf("0");
            return 0;
        }
        if(cnt >= 2) {
            printf("%d", ansYear);
            return 0;
        }
        ansYear++;
    }
}