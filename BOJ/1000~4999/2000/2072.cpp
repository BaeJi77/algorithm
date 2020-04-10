#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N;
int map[20][20]; // 흑은 1, 백은 0

bool isPoss(int y, int x) {
    return 1 <= y && y <= 19 && 1 <= x && x <= 19;
}

int goLeft (int color, int ny, int nx) {
    if(isPoss(ny, nx) == false) return 0;
    if(map[ny][nx] != color) return 0;
    return 1 + goLeft(color, ny, nx - 1);
}

int goRight (int color, int ny, int nx) {
    if(isPoss(ny, nx) == false) return 0;
    if(map[ny][nx] != color) return 0;
    return 1 + goRight(color, ny, nx + 1);
}

int goUp (int color, int ny, int nx) {
    if(isPoss(ny, nx) == false) return 0;
    if(map[ny][nx] != color) return 0;
    return 1 + goUp(color, ny - 1, nx);
}

int goDown (int color, int ny, int nx) {
    if(isPoss(ny, nx) == false) return 0;
    if(map[ny][nx] != color) return 0;
    return 1 + goDown(color, ny + 1, nx);
}

int goLeftUp (int color, int ny, int nx) {
    if(isPoss(ny, nx) == false) return 0;
    if(map[ny][nx] != color) return 0;
    return 1 + goLeftUp(color, ny - 1, nx - 1);
}

int goLeftDown (int color, int ny, int nx) {
    if(isPoss(ny, nx) == false) return 0;
    if(map[ny][nx] != color) return 0;
    return 1 + goLeftDown(color, ny + 1, nx - 1);
}

int goRightUp (int color, int ny, int nx) {
    if(isPoss(ny, nx) == false) return 0;
    if(map[ny][nx] != color) return 0;
    return 1 + goRightUp(color, ny - 1, nx + 1);
}

int goRightDown (int color, int ny, int nx) {
    if(isPoss(ny, nx) == false) return 0;
    if(map[ny][nx] != color) return 0;
    return 1 + goRightDown(color, ny + 1, nx + 1);
}

bool checkFinishedGame(int color, int sy, int sx) {
    // 옆으로, 위아래로, 대각선으로
    int horizon = goLeft(color, sy, sx) + goRight(color, sy, sx + 1);
    int vertical = goUp(color, sy, sx) + goDown(color, sy + 1, sx);
    int diagonal1 = goLeftUp(color, sy, sx) + goRightDown(color, sy + 1, sx + 1);
    int diagonal2 = goLeftDown(color, sy, sx) + goRightUp(color, sy - 1, sx + 1);
    if(horizon == 5 || vertical == 5 || diagonal1 == 5 || diagonal2 == 5) return true;
    return false;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    memset(map, -1, sizeof(map));

    int ans = -1;
    for(int i = 1 ; i <= N ; i++) {
        // 홀수는 흑, 짝수는 백
        int a,b;
        scanf("%d %d", &a, &b);
        map[a][b] = i % 2;
        if(checkFinishedGame(map[a][b], a, b)) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
}