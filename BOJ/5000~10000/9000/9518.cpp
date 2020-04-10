#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N, M, ans;

char map[60][60];

const int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dx[] = {-1, 0, 1, 1, -1, 1, 0, -1};

bool isPoss(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int solve(int y, int x) {
    int cnt = 0;
    for(int i = 0 ; i < 8 ; ++i) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(isPoss(yy, xx) == false) continue;
        if(map[yy][xx] == '.') continue;
        cnt++;
    }

    return cnt;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; ++i) {
        getchar();
        for(int j = 0 ; j < M ; ++j) {
            scanf("%c", &map[i][j]);
        }
    }

    int ret = 0;
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            int makeGood = solve(i, j);
            if(map[i][j] == 'o') {
                ret += makeGood;
            } else {
                ans = max(ans, makeGood);
            }
        }
    }

    printf("%d", ret / 2 + ans);
}