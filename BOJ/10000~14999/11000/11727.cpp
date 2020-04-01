#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int mod = 10007;

int N;
int dp[1010];

int solve(int idx) {
    if(idx > N)
        return 0;
    if(idx == N)
        return 1;
    
    int& ret = dp[idx];
    if(ret != -1)
        return ret;

    ret = solve(idx + 1) + (solve(idx + 2) % mod * 2) % mod;
    ret %= mod;
    
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    printf("%d", solve(0) % mod);
}