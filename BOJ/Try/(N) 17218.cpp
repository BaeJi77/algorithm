#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int N, M;
int maxStringSize;
string ans;
string first, second;
string dp[50][50];

string solve(int nIdx, int mIdx) {
    printf("%d %d\n", nIdx, mIdx);
    if(nIdx == N) {
        // if(maxStringSize < str.size()) {
        //     ans = str;
        //     maxStringSize = str.size();
        // }
        return "";
    }

    string& ret = dp[nIdx][mIdx];
    if(ret != "a")
        return ret;

    ret = solve(nIdx + 1, mIdx);
    for(int i = mIdx ; i < M ; i++) {
        string newRet = ret;
        if(first[nIdx] == second[i]) {
            newRet.push_back(second[i]);
            newRet.append(solve(nIdx + 1, i + 1));
        }

        // printf("%d %d\n", nIdx, mIdx);
        // cout<<ret<<" "<<newRet<<endl;
        
        if(ret.size() < newRet.size()) {
            ret = newRet;
        }
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>first>>second;
    N = first.size();
    M = second.size();

    for(int i = 0 ; i < N ; i++) {
        for(int j =0 ; j < M ; j++){
            dp[i][j] = "a";
        }
    }
    cout<<solve(0, 0)<<endl;
    // // cout<<solve(0, 0, "");
    // cout<<ans;
}