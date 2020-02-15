#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int map[101][101]; // W == 1, B == 0
bool visited[101][101];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1,0 , 0};
int maxWhiteCnt, maxBlueCnt;

priority_queue<int> white, blue;

bool isposs(int y, int x) {
    return y>=0&&x>=0&&y<N&&x<M;
}

void checkPower(int y, int x) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(y, x));
    int color = map[y][x];
    int peopleCnt = 0;
    visited[y][x] = true;
    while(int s = qu.size()) {
        while(s--) {
            int yy = qu.front().first;
            int xx = qu.front().second;
            qu.pop();
            peopleCnt++;

            for(int i = 0 ; i < 4; i++ ){
                int ddy = yy + dy[i];
                int ddx = xx + dx[i];
                
                if(!isposs(ddy, ddx)) continue;
                if(color != map[ddy][ddx]) continue;
                if(visited[ddy][ddx]) continue;
                
                visited[ddy][ddx] = true;
                qu.push(make_pair(ddy,ddx));
            }
        }
    }

    if(color == 1) maxWhiteCnt += peopleCnt*peopleCnt;
    else maxBlueCnt += peopleCnt*peopleCnt;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &M ,&N);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M ; j++ ){
            char input = getchar();
            if(input == 'W')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            if(!visited[i][j]) {
                checkPower(i, j);
            }
        }
    }

    printf("%d %d", maxWhiteCnt, maxBlueCnt);
}