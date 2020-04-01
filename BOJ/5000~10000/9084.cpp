#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N, K;
int coins[30];
int dp[30][10010];

bool comp(int a, int b) {
    return a > b;
}

int solve(int idx, int rest) {
    if(rest == 0)
        return 1;

    if(rest < 0 || idx >= N)
        return 0;

    int& ret = dp[idx][rest];
    if(ret != -1)
        return ret;
    
    ret = 0;
    for(int i = 0 ; i * coins[idx] <= rest ; i++) {
        ret += solve(idx + 1, rest - i * coins[idx]);
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--) {    
        memset(coins, 0, sizeof(coins));
        memset(dp, -1, sizeof(dp));
        scanf("%d", &N);
        for(int i = 0 ; i < N ; i++)
            scanf("%d", &coins[i]);
        sort(coins, coins + N, comp);
        scanf("%d", &K);

        printf("%d\n", solve(0, K));
    }
}