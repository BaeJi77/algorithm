#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
pair<int, int> map[20];
int dp[20];

int solve(int idx) {
    if(idx > N)
        return -987654321;
    if(idx == N)
        return 0;
    
    int& ret = dp[idx];
    if(ret != -1)
        return ret;
    
    ret = solve(idx + 1);
    if(idx + map[idx].first <= N) ret = max(ret, solve(idx + map[idx].first) + map[idx].second);

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d %d", &map[i].first, &map[i].second);

    printf("%d", solve(0));
}