#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
const int MAX = 1000000001;

int N, M, K;
int dp[110][110];
bool notOk = false;
string ans = "";

int solve(int a, int z) {
    if(a == 0 || z == 0)
        return 1;
    
    int& ret = dp[a][z];
    if(ret != -1)
        return ret;
    
    ret = min(solve(a - 1, z) + solve(a, z - 1), MAX);
    return ret;
}

void getWord(int a, int z, int k) {
    if(a == 0) {
        for(int i = 0 ; i < z ; ++i)
            ans += 'z';
        return;
    }

    if(z == 0) {
        for(int i = 0 ; i < a ; ++i)
            ans += 'a';
        return;
    }

    int aFirst = solve(a - 1, z);
    if(aFirst >= k) {
        ans += 'a';
        getWord(a - 1, z, k);
    } else if(aFirst < k < MAX) {
        ans += 'z';
        getWord(a, z - 1, k - aFirst);
    }
}


int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N>>M>>K;
    memset(dp, -1, sizeof(dp));
    if(solve(N, M) < K) {
        cout<<"-1";
        return 0;
    }
    getWord(N, M, K);
    cout<<ans<<"\n";
}