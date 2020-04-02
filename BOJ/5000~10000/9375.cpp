#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, int> mp;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        mp.clear();
        cin>>N;
        for(int i = 0 ; i < N ; i++) {
            string a,b;
            cin>>a>>b;
            mp[b]++;
        }

        int ans = 1;
        for(auto i : mp) {
            ans *= (i.second + 1);
        }

        cout<<ans - 1<<"\n";
    }
}