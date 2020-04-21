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
double M;
int dp[10001];
vector<pair<int, int> > candies;

int solve(int rest) {
    int& ret = dp[rest];
    if(ret != -1)
        return ret;
    
    ret = 0;
    for(int i = 0 ; i < N ; ++i) {
        if(rest < candies[i].second) continue;
        ret = max(ret, solve(rest - candies[i].second) + candies[i].first);
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    while(scanf("%d %lf", &N, &M)){
        if(N == 0 && M == 0) break;
        memset(dp, -1, sizeof(dp));
        candies.clear();

        for(int i = 0 ; i < N ; ++i) {
            int a;
            double b;
            scanf("%d %lf", &a, &b);
            candies.push_back(make_pair(a, (int)100 * b + 0.5));
        }

        printf("%d\n", solve((int)(100 * M + 0.5)));
    }
}