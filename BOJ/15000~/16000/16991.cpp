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
vector<pair<int, int> > vt;
double map[20][20];
double dp[17][1<<17];

double solve(int now, int bit) {
    if(bit == (1<<N) - 1) {
        if(map[now][0] == 0) return 1e9;
        else return map[now][0];
    }

    double& ret = dp[now][bit];
    if(ret != -1.0)
        return ret;
    
    ret = 1e9;
    for(int i = 0 ; i < N ; ++i) {
        if(map[now][i] == 0) continue;
        if(bit & 1<<i) continue;
        ret = min(ret, solve(i, bit | 1<<i) + map[now][i]);
    }
    return ret;
}

double calDistance(int x1, int x2, int y1, int y2) {
    int x = x1 - x2;
    int y = y1 - y2;
    return sqrt(x * x + y * y);
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < 1<<N ; j++) {
            dp[i][j] = -1;
        }
    }
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            int a, b;
            scanf("%d %d", &a, &b);
            vt.push_back(make_pair(a, b));
        }
    }

    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            map[i][j] = calDistance(vt[i].first, vt[j].first, vt[i].second, vt[j].second);
        }
    }
    printf("%.6f", solve(0, 1));
}