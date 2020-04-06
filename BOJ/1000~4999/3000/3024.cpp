#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N;
char map[40][40];

// 오른쪽 위, 오른쪽, 오른쪽아래, 아래, 왼쪽 아래
const int dy[] = {-1, 0, 1, 1, 1};
const int dx[] = {1, 1, 1, 0, -1};

bool isPoss(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

char checkGame(int sy, int sx) {
    char now = map[sy][sx];
    if(now == '.')
        return '.';

    for(int i = 0 ; i < 5; i++) {
        int y = sy;
        int x = sx;
        for(int j = 0 ; j < 2 ; j++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(isPoss(yy, xx) == false) break;
            if(map[yy][xx] != now) break;
            y = yy;
            x = xx;
            if(j == 1) return now;
        }
    }
    return '.';
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < N ; j++)
            scanf("%c", &map[i][j]);
    }

    char isFinished = '.';
    for(int i = 0 ; i < N ; i++) {
        if(isFinished != '.') break;
        for(int j = 0 ; j < N ; j++) {
            isFinished = checkGame(i, j);
            if(isFinished != '.') break;
        }
    }
    if(isFinished == '.') printf("ongoing");
    else printf("%c", isFinished);
}