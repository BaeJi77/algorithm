#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll N, P, Q, X, Y;
unordered_map<ll, ll> dp;

ll solve(ll x) {
    if(x <= 0)
        return 1;
    
    if(dp.find(x) != dp.end())
        return dp[x];

    return dp[x] = solve(x / P - X) + solve(x / Q - Y);
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%lld %lld %lld %lld %lld", &N, &P, &Q, &X, &Y);
    dp[1] = 2;
    printf("%lld", solve(N));
}