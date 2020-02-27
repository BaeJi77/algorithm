#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;
const int MAX = 5e4;

int N, cnt;
int dp[MAX+1];

int sol(int n) {
    if(n == 1)
        return 1;
    if(n == 0)
        return 0;
    
    int& ret = dp[n];
    if(ret != INT_MAX)
        return ret;
    
    for(int i = sqrt(n) ; i >= 1 ; i--) {
        ret = min(ret, sol(n - i * i) + 1);
    }

    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    // memset(dp, 3xff, sizeof(dp));
    for(int i = 0 ; i < MAX ; i++)
        dp[i] = INT_MAX;

    scanf("%d", &N);
    printf("%d", sol(N));
}