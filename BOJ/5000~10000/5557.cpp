#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

ll N;
ll numbers[110];
ll dp[110][30];

ll solve(ll idx, ll nowSum) {
    if(idx == N - 1) {
        if(nowSum == numbers[N-1]) return 1;
        return 0;
    }
    
    ll& ret = dp[idx][nowSum];
    if(ret != -1)
        return ret;
    
    ret = 0;
    if(nowSum + numbers[idx] <= 20) ret += solve(idx + 1, nowSum + numbers[idx]);
    if(nowSum - numbers[idx] >= 0) ret += solve(idx + 1, nowSum - numbers[idx]);
    
    return ret;
}

// 처음 0에 대한 반례 => + / - 상관 없음
int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &N);
    for(ll i = 0 ; i < N ; i++)
        scanf("%lld", &numbers[i]);
    printf("%lld", solve(1, numbers[0]));
}