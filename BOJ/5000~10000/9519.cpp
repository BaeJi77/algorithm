#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int X;
string first;
vector<string> vt;

string makeStringBeforEyeFlush(string afterString) {
    string ret = "";
    int addLength = 0;
    if(afterString.size() % 2 == 1) addLength++;
    for(int i = 0 ; i < afterString.size()/2 + addLength; i++) {
        ret.push_back(afterString[2*i]);
    }

    for(int i = afterString.size()/2 - 1 ; i >= 0 ; i--) {
        ret.push_back(afterString[2*i + 1]);
    }
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>X;
    cin>>first;
    vt.push_back(first);
    string preString = vt[0];
    while(1) {
        string nowString = makeStringBeforEyeFlush(preString);
        vt.push_back(nowString);
        preString = nowString;

        if(preString == vt[0])
            break;
    }

    vt.pop_back();
    int mod = vt.size();
    int newX = X % mod;
    cout<<vt[newX];
}