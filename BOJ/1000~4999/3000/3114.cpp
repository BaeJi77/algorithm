#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int R,C;
int aSum[1510][1510];
int bSum[1510][1510];
pair<char, int> map[1510][1510];
int dp[1510][1510];

const int dy[] = {0, 1, 1};
const int dx[] = {1, 0, 1};

bool isPoss(int y, int x) {
    return y >= 1 && y <= R && x >= 1 && x <= C;
}

int solve(int y, int x) {
    if(y == R && x == C) {
        return 0;
    }

    int& ret = dp[y][x];
    if(ret != -1)
        return ret;

    ret = 0;
    for(int i = 0 ; i < 3 ; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!isPoss(yy, xx)) continue;

        // 0: x이동 1: y이동 2: x, y 이동
        if(i == 0) {
            ret = max(ret, solve(yy, xx) + bSum[yy-1][xx]);
        } else if(i == 1) {
            ret = max(ret, solve(yy, xx) + aSum[yy][xx-1]);
        } else if(i == 2) {
            ret = max(ret, solve(yy, xx) + bSum[yy-1][xx] + aSum[yy][xx-1]);
        }
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &R, &C);
    getchar();
    for(int i = 1 ; i <= R ; i++) {
        int apre = 0;
        int bpre = 0;
        for(int j = 1 ; j <= C ; j++) {
            char team;
            int score;
            scanf("%c%d ", &team, &score);
            map[i][j] = make_pair(team, score);
            if(team == 'A') apre+=score;
            aSum[i][j] = apre;
        }
    }

    for(int i = 1 ; i <= C ; i++) {
        int tempSum = 0;
        for(int j = 1 ; j <= R ; j++) {
            if(map[j][i].first == 'B') tempSum += map[j][i].second;
            bSum[j][i] = tempSum;
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("%d", solve(0, 0));
}