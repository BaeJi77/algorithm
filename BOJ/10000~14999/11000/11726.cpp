#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int mod = 10007;

int N;
int dp[1010]; // 이전 상태가 있어야 함. ㅁ

int solve(int num) {
    if(num < 0)
        return 0;
    // 기저 사례
    if(num == 0)
        return 1;

    int& ret = dp[num];
    if(ret != -1)
        return ret;
    
    ret = 0;
    // 재귀 호출
    ret += (solve(num - 2) + solve(num - 1)) % mod;

    // 값 반환
    ret %= mod;
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    printf("%d", solve(N) % mod);
}