#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
int map[20][20];
int dp[17][1<<17];

int solve(int now, int bit) {
    if(bit == (1<<N) - 1) {
        if(map[now][0] == 0) return 1e9;
        else return map[now][0];
    }

    int& ret = dp[now][bit];
    if(ret != -1)
        return ret;
    
    ret = 1e9;
    for(int i = 0 ; i < N ; ++i) {
        if(map[now][i] == 0) continue;
        if(bit & 1<<i) continue;
        ret = min(ret, solve(i, bit | 1<<i) + map[now][i]);
    }
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d", solve(0, 1));
}