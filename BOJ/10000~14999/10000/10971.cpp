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

int solve(int now, int bit, int start) {
    if(bit == (1<<N) - 1) {
        if(map[now][start] != 0) return map[now][start];
        return 1e9;
    }

    int ret = 1e9;
    for(int i = 0 ; i < N ; ++i) {
        if(bit & 1<<i) continue;
        if(map[now][i] == 0) continue;
        ret = min(ret, solve(i, bit | 1<<i, start) + map[now][i]);
    }
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    int ans = 1e9;
    for(int i = 0 ; i < N ; ++i) {
        ans = min(ans, solve(i, 1<<i, i));
    }

    printf("%d", ans);
}