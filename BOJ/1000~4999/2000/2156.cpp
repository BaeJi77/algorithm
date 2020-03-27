#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int wine[10010];
int dp[10010][5];

int solve(int idx, int conti) {
    if(idx == N)
        return 0;
    
    int& ret = dp[idx][conti];
    if(ret != -1)
        return ret;
    
    ret = solve(idx + 1, 0);
    if(conti != 2) ret = max(ret, solve(idx + 1, conti + 1) + wine[idx]);

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &wine[i]);
    
    printf("%d", solve(0, 0));
}