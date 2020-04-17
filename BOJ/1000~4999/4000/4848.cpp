#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

string dp[20];
int numbers[20];

string solve(int number) {
    if(number == 0)
        return "{}";
    
    string& ret = dp[number];
    if(ret != "")
        return ret;
    
    ret = "{";
    for(int i = 0 ; i < number; i++) {
        ret += solve(i);
        if(i != number - 1) ret += ",";
    }
    ret += "}";

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    int tc;
    cin>>tc;
    dp[0] = "{}";
    solve(15);
    while(tc--) {
        string a, b;
        cin>>a>>b;
        int aNumber, bNumber;
        for(int i = 0 ; i <= 15 ; ++i) {
            if(dp[i] == a) aNumber = i;
            if(dp[i] == b) bNumber = i;
        }
        int sum = aNumber + bNumber;
        cout<<dp[sum]<<"\n";
    }
}