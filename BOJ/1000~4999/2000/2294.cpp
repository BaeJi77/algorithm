#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N,K;
int coins[110];
int dp[10010];

bool comp(int a, int b) {
    return a > b;
}

int findMinCoinCnt(int rest) {
    if(rest < 0)
        return 987654321;

    if(rest == 0)
        return 0;

    int& ret = dp[rest];
    if(ret != -1)
        return ret;
    
    ret = 987654321;
    for(int i = 0 ; i < N ; i++) {
        if(rest - coins[i] >= 0)
            ret = min(ret, findMinCoinCnt(rest - coins[i]) + 1);
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &N, &K);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &coins[i]);
    sort(coins, coins + N, comp);
    int ret = findMinCoinCnt(K);
    printf("%d", ret == 987654321 ? -1 : ret);
}