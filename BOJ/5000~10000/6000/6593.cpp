#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int L, R, C;
int sh,sy,sx,eh,ey,ex;
char map[50][50][50];

const int dh[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dx[] = {0, 0, 0, 0, 1, -1};

bool isPoss(int h, int y, int x) { 
    return 0 <= h && h < L && 0 <= y && y < R && 0 <= x && x < C;
}

int bfs() {
    bool visited[50][50][50] = {0,};
    queue<pair<int, pair<int, int> > > qu;
    qu.push(make_pair(sh, make_pair(sy, sx)));
    visited[sh][sy][sx] = true;

    int cnt = 0;
    while(int s = qu.size()) {
        while(s--) {
            int h = qu.front().first;
            int y = qu.front().second.first;
            int x = qu.front().second.second;
            qu.pop();

            if(h == eh && y == ey && x == ex) return cnt;

            for(int i = 0; i < 6; i++) {
                int hh = h + dh[i];
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(isPoss(hh, yy, xx) == false) continue;
                if(visited[hh][yy][xx]) continue;
                if(map[hh][yy][xx] == '#') continue;

                visited[hh][yy][xx] = true;
                qu.push(make_pair(hh, make_pair(yy, xx)));
            }
        }
        cnt++;
    }
    return -1;
}


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    while(scanf("%d %d %d", &L, &R, &C)) {
        if(L == 0 && R == 0 && C == 0) break;
        for(int i = 0 ; i < L ; i++) {
            for(int j = 0 ; j < R ; j++) {
                getchar();
                for(int k = 0 ; k < C ; k++) {
                    scanf("%c", &map[i][j][k]);
                    if(map[i][j][k] == 'S') sh = i, sy = j, sx = k;
                    if(map[i][j][k] == 'E') eh = i, ey = j, ex = k;
                }
            }
            getchar();
        }
        int ret = bfs();
        if(ret == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", ret);
    }
}