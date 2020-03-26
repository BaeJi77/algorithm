#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int map[310];
int dp[310][10];

int solve(int idx, int conti) {
    if(idx == 0)
        return 0;
    if(idx < 0)
        return -987654321;
    if(conti == 3)
        return -987654321;
    
    int& ret = dp[idx][conti];
    if(ret != -1)
        return ret;
    
    ret = solve(idx - 2, 1) + map[idx - 2];
    ret = max(ret, solve(idx - 1, conti + 1) + map[idx - 1]);

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++) 
        scanf("%d", &map[i]);

    printf("%d", solve(N, 1) + map[N]);
}