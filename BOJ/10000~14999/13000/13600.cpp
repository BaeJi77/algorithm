#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;
const int MAX = 1e5 + 1;

int N;
int dp[10][100010];
vector<int> vt;

int solve(int idx, int val) {
    if(val < 0) return MAX;

    if(val == 0) 
        return 0;

    int& ret = dp[idx][val];
    if(ret != MAX)
        return ret;
    
    for(int i = idx ; i < vt.size() ; ++i) {
        if(val >= vt[i])
            ret = min(ret, solve(i, val - vt[i]) + 1);
    }

    return ret;
}

void init() {
    scanf("%d", &N);
    for(int i = 0 ;  i < 10 ; ++i)
        fill(dp[i], dp[i] + 100010, MAX);

    for(int i = 1 ; i < 10 ; ++i) {
        int temp = 1;
        for(int j = i ; j >= 1 ; --j) {
            temp *= j;
        }
        vt.push_back(temp);
    }
    reverse(vt.begin(), vt.end());
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    init();
    printf("%d", solve(0, N));
}