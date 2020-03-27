#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int arr[1010];
int dp[1010][1010]; // 현재 인덱스에서 마지막까지 최장 긴가 부분 수열 길이

int solve(int idx, int nowValue) {
    if(idx == N + 1)
        return 0;
    
    int& ret = dp[idx][nowValue];
    if(ret != -1)
        return ret;
    
    ret = solve(idx + 1, nowValue);
    if(arr[idx + 1] > nowValue) ret = max(ret, solve(idx + 1, arr[idx + 1]) + 1);

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++)
        scanf("%d", &arr[i]);

    printf("%d", solve(0, 0));
}