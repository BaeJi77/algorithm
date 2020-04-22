#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, K;
int dp[101][100001];
vector<pair<int, int> > bag;

int solve(int idx, int rest) {
    if(idx == N) {
        return 0;
    }

    int& ret = dp[idx][rest];
    if(ret != -1)
        return ret;
    
    ret = solve(idx + 1, rest);
    if(rest >= bag[idx].first)
        ret = max(ret, bag[idx].second + solve(idx + 1, rest - bag[idx].first));

    return ret;
}


int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    memset(dp,-1,sizeof(dp));
    scanf("%d %d", &N, &K);
    for(int i = 0 ; i < N ; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        bag.push_back(make_pair(a,b));
    }


    printf("%d", solve(0, K));
}