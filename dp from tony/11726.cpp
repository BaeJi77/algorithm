#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 10007;

int N;
int dp[1001];

int solve(int idx) {
    if(idx == 1)
        return 1;
    if(idx == 2)
        return 2;

    int &ret = dp[idx];
    if(ret != -1)
        return ret;
        
    ret = solve(idx - 1) % mod + solve(idx - 2) % mod;

    return ret % mod;
}

int main() {
    freopen("input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = 2;
    dp[0] = 0;
    printf("%d", solve(N) % mod);
}