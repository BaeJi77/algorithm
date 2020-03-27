#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<vector<int> > vt;
int dp[510][510];

int solve(int y, int x) {
    if(y == N)
        return 0;
    
    int& ret = dp[y][x];
    if(ret != -1)
        return ret;

    // y는 항상 1씩 증가함. x는 두개중에 하나 선택하겠지.
    ret = max(solve(y+1 ,x), solve(y+1, x+1)) + vt[y][x];

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    vt.resize(N+1);
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            int k;
            scanf("%d", &k);
            vt[i].push_back(k);
        }
    }

    printf("%d", solve(0, 0));
}