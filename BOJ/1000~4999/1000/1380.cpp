#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    int tc = 1;
    while(1) {
        int N;
        cin>>N;
        if(N == 0) break;

        vector<string> vt;
        string ans;

        getchar();
        for(int i = 0 ; i < N ; ++i) {
            string girl;
            getline(cin, girl);
            vt.push_back(girl);
        }

        int cnt[101] = {0,};
        for(int i = 0 ; i < (2 * N) - 1; ++i) {
            int number;
            char alphabet;
            cin>>number>>alphabet;
            cnt[number - 1]++;
        }

        for(int i = 0 ; i < N ; ++i) {
            if(cnt[i] == 1) ans = vt[i];
        }

        cout<<tc<<" "<<ans<<"\n";
        tc++;
    }
}