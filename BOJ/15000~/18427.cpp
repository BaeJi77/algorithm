#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

const int mod = 10007;

int N, M, H;
vector<vector<int> > map;
int dp[60][1010];

int solve(int idx, int rest) {
    if(rest == 0)
        return 1;
    if(idx == N)
        return 0;
    
    int& ret = dp[idx][rest];
    if(ret != -1)
        return ret;
    
    ret = solve(idx + 1, rest) % mod;
    for(auto next : map[idx]) {
        if(rest - next >= 0)
            ret += solve(idx + 1, rest - next) % mod;
    }
    ret %= mod;
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    cin>>N>>M>>H;
    map.resize(N+1);
    for(int i = 0 ; i < N ; ++i) {
        while(1) {
            int k;
            cin>>k;
            map[i].push_back(k);

            if(getchar() != ' ')
                break;
        }
    }
    cout<<solve(0, H) % mod <<endl;
}