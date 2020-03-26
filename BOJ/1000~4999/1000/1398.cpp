#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
const int MAX = 987654321;

ll N;
int dp[101];
int arr[] = {1, 10, 25};

int solve(int don) {
    if(don < 0)
        return MAX;
    if(don == 0) {
        return 0;
    }

    int& ret = dp[don];
    if(ret != MAX)
        return ret;
    
    for(int i = 0 ; i < 3 ; i++) {
        ret = min(ret, solve(don - arr[i]) + 1);
    }

    return ret;
}

// 동전마다 쓰거나 안쓰거나 이런 개념이 아님. 
// 1, 10, 25 / 100 1000 2500 / ... => 각 단계별로 사용되는 동전이 똑같음. 
// 그래서 계속 레벨을 작은 단위로 낮춰서 필요한 동전 수를 추가함.
int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    ll t;
    scanf("%lld", &t);
    for(int i = 0 ; i < 101; i++)
        dp[i] = MAX;
    solve(100);
    dp[0] = 0;
    while(t--) {
        scanf("%lld", &N);
        ll ans = 0;
        while(1) {
            if(N == 0) break;
            ans += dp[N % 100];
            N /= 100;
        }
        printf("%lld\n", ans);
    }
}