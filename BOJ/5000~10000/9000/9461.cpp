#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

ll N;
ll dp[110];

ll solve(ll idx) {
    ll& ret = dp[idx];
    if(ret != -1)
        return ret;

    return ret = solve(idx - 1) + solve(idx - 5);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    ll t;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &N);
        printf("%lld\n", solve(N));
    }
}