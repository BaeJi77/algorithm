#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

ll N, M, K;
ll map[20][20];
ll dp[20][20][2];

ll dy[] = {0, 1};
ll dx[] = {1, 0};

bool isPoss(ll y, ll x) {
    return 1 <= y && y <= N && 1 <= x && x <= M;
}

ll solve(ll y, ll x, ll check) {
    if(y == N && x == M) {
        if(check || K == 0) return 1;
        return 0;
    }

    ll& ret = dp[y][x][check];
    if(ret != -1)
        return ret;

    ret = 0;
    for(ll i = 0 ; i < 2 ; i++) {
        ll yy = dy[i] + y;
        ll xx = dx[i] + x;

        if(!isPoss(yy, xx)) continue;
        if(map[yy][xx] == 1) ret += solve(yy, xx, 1);
        else ret += solve(yy, xx, check);
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%lld %lld %lld", &N, &M, &K);
    if(K % M == 0) map[K / M][M] = 1;
    else map[K / M + 1][K % M] = 1;
    printf("%lld", solve(1, 1, 0));
}