#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, ans = -987654321;
int numbers[100010];
int dp[100010]; // 현재 idx에서 가장 큰 값

int solve(int idx) {
    if(idx == N)
        return 0;
    
    int& ret = dp[idx];
    if(ret != -987654321)
        return ret;
    
    ret = numbers[idx];
    ret = max(ret, solve(idx + 1) + numbers[idx]);
    ans = max(ret, ans);

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    fill(dp, dp + N, -987654321);
    for(int i = 0 ; i < N ; ++i) 
        scanf("%d", &numbers[i]);
    solve(0);
    printf("%d\n", ans);
}