#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int N, K;
int S, X, Y;
int map[210][210];
bool visited[210][210];
priority_queue<pair<pair<int, int>, pair<int, int> > > qu;

bool isPoss(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= N;
}

int bfs() {
    int time = 0;
    while(int s = qu.size()) {
        if(time == S)
            return map[Y][X];
        while(s--) {
            int nowTime = -qu.top().first.first;
            int color = -qu.top().first.second;
            int y = qu.top().second.first;
            int x = qu.top().second.second;
            qu.pop();

            for(int i = 0;  i < 4; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(isPoss(yy, xx) == false) continue;
                if(visited[yy][xx]) continue;
                if(map[yy][xx] != 0) continue;
                visited[yy][xx] = true;
                map[yy][xx] = color;
                qu.push(make_pair(make_pair(-(time + 1), -color), make_pair(yy, xx)));
            }
        }
        time++;
    }

    // S가 되기 전에 모든 경우를 다 봣을 수도 있음.
    return map[Y][X];
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    for(int i = 1 ; i <= N ; ++i) {
        for(int j = 1 ; j <= N ; ++j) {
            scanf("%d", &map[i][j]);
            if(map[i][j] != 0) {
                visited[i][j] = true;
                qu.push(make_pair(make_pair(0, -map[i][j]), make_pair(i, j)));
            }
        }
    }
    
    scanf("%d %d %d", &S, &Y, &X);
    printf("%d", bfs());
}