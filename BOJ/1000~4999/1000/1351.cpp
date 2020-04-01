#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;

ll N, P, Q;
map<ll, ll> dp;

ll solve(ll n) {
    if(n == 0)
        return 1;
    
    if(dp.find(n) != dp.end())
        return dp[n];

    return dp[n] = solve(n / P) + solve(n / Q);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%lld %lld %lld", &N, &P, &Q);
    printf("%lld", solve(N));
}