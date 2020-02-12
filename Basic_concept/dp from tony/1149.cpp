#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1000;

int N;
int cost[MAX+1][3];
int dp[MAX+1][3];

int solve(int idx, int status) {
    if(idx == 0)
        return 0;

    int &ret = dp[idx][status];
    if(ret != -1)
        return ret;
    ret = cost[idx][status];

    if(status == 0)
        ret += min(solve(idx - 1, 1), solve(idx - 1, 2));
    else if(status == 1)
        ret += min(solve(idx - 1, 0), solve(idx - 1, 2));
    else 
        ret += min(solve(idx - 1, 0), solve(idx - 1, 1));

    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    memset(dp,-1,sizeof(dp));
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    printf("%d", min(solve(N, 2), min(solve(N, 0), solve(N, 1))));
}