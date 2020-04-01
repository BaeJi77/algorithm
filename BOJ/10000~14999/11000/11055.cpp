#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int numbers[1010];
int dp[1010][1010];

int solve(int idx, int lastNumber) {
    if(idx == N)
        return 0;

    int& ret = dp[idx][lastNumber];
    if(ret != -1)
        return ret;

    ret = solve(idx + 1, lastNumber);
    if(lastNumber < numbers[idx]) ret = max(ret, solve(idx + 1, numbers[idx]) + numbers[idx]);

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &numbers[i]);
    printf("%d", solve(0, 0));
}