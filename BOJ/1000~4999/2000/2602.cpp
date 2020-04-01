#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int N;
string target;
string up;
string down;
int dp[30][110][2]; // dp[i][j][k] => i = target idx, j = 다리 위치, k는 위 / 아래

int solve(int targetIdx, int brigePos, int state) {
    if(brigePos == N) {
        if(targetIdx == target.size()) return 1;
        return 0;
    }

    int& ret = dp[targetIdx][brigePos][state];
    if(ret != -1)
        return ret;
    
    ret = solve(targetIdx, N, state);
    if(state == 0) {
        for(int i = brigePos; i < N ; i++) {
            if(target[targetIdx] == up[i]) {
                ret += solve(targetIdx + 1, i + 1, 1);
            }
        }
    } else {
        for(int i = brigePos; i < N ; i++) {
            if(target[targetIdx] == down[i]) {
                ret += solve(targetIdx + 1, i + 1, 0);
            }
        }
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    cin>>target>>up>>down;
    N = up.size();
    cout<<solve(0, 0, 0) + solve(0, 0, 1)<<endl;
}