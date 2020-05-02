#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

// 처음은 오른쪽으로 향함 => 오른쪽으로 돌 때 dir 올려주기
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, K, L;
int dir, sy, sx, ey, ex, ans;
int map[110][110];
bool visit[110][110];
char oper[10010];

bool isOk(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= N;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d%d", &N, &K);
    for(int i = 0 ; i < K ; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    scanf("%d", &L);
    for(int i = 0 ; i < L ; ++i) {
        int a;
        char b;
        scanf("%d %c", &a, &b);
        oper[a] = b;
    }

    // 시작은 (1, 1) 에서
    sy = 1, sx = 1, ey = 1, ex = 1;
    queue<pair<int, int> > path;
    visit[sy][sx] = true;
    while(1) {
        ans++;
        sy += dy[dir];
        sx += dx[dir];
        
        if(isOk(sy, sx) == false || visit[sy][sx])
            break;

        visit[sy][sx] = true;
        path.push(make_pair(sy, sx));
        if(map[sy][sx] == 0) { // 노 사과
            visit[ey][ex] = false;
            ey = path.front().first;
            ex = path.front().second;
            path.pop();
        } else 
            map[sy][sx] = 0;

        if(oper[ans] == 'L') dir--;
        if(oper[ans] == 'D') dir++;
        if(dir < 0) dir += 4;
        dir %= 4;
    }
    printf("%d", ans);
}