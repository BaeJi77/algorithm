#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N;
int dp[1010];
int jumps[1010];

int solve(int idx) {
    if(idx > N - 1)
        return INF;
    if(idx == N - 1)
        return 0;
    
    int& ret = dp[idx];
    if(ret != -1)
        return ret;
    
    ret = INF;
    for(int i = 1 ; i <= jumps[idx] ; i++)
        ret = min(ret, solve(idx + i) + 1);
    
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &jumps[i]);
    
    int ans = solve(0);
    if(ans == INF) printf("-1");
    else printf("%d", ans);
}