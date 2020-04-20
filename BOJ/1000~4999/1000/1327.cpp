#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, K;
string str, ans;

int bfs(string in) {
    ans = str;
    sort(ans.begin(), ans.end());
    queue<string> qu;
    map<string, bool> mp;

    qu.push(in);
    mp[in] = true;
    int cnt = 0;
    while(int s = qu.size()) {
        while(s--) {
            string now = qu.front();
            qu.pop();
            // cout<<now<<endl;
            if(now == ans) {
                return cnt;
            }

            for(int i = 0 ; i < N - K + 1; ++i) {
                string next = now;
                reverse(next.begin() + i, next.begin() + i + K);
                // cout<<next<<endl;
                if(mp.find(next) == mp.end()) {
                    qu.push(next);
                    mp[next] = true;
                }
            }
        }
        cnt++;
    }

    return -1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N>>K;
    for(int i = 0 ; i < N ; i++) {
        char a;
        cin>>a;
        str += a;
    }
    cout<<bfs(str);
}