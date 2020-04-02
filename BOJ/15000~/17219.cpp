#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int N, M;
map<string, string> mp;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++) {
        string a,b;
        cin>>a>>b;
        mp[a] = b;
    }

    for(int i = 0 ; i < M ; i++) {
        string a;
        cin>>a;
        cout<<mp[a]<<"\n";
    }
}