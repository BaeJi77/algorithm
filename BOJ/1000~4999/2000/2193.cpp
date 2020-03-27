#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll N;
ll dp[100][2]; // 이전 값.

ll solve(ll idx, ll pre) {
    if(idx == 0)
        return 1;
    
    ll& ret = dp[idx][pre];
    if(ret != -1)
        return ret;

    ret = solve(idx - 1, 0);
    if(pre != 1) ret += solve(idx - 1, 1);

    return ret;
}

// N자리 이친수
int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    
    printf("%lld", N == 1 ? 1 : solve(N - 1, 1));
}