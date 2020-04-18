#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

ll N, K;
vector<vector<ll> > vt;

// 모든 학생은 자신과 반 등수의 차이가 K를 넘으면 친구가 아니라는거
// 친구와 좋은 친구 => 이름 길이가 같다.
// K보다 작거나 같음.
int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N>>K;
    vt.resize(21);
    for(ll i = 0 ; i < N ; i++) {
        string temp;
        cin>>temp;
        vt[temp.size()].push_back(i);
    }

    ll ans = 0;
    for(ll i = 2 ; i <= 20 ; i++) {
        if(vt[i].size() == 0) continue;
        ll left = 0;
        ll right = 1;
        while(right != vt[i].size()) {
            if(left == right) {
                right++;
                continue;
            }
            if(vt[i][left] + K < vt[i][right]) {
                ans += right - left - 1;
                left++;
            } else 
                right++;
        }
        // right == vt[i].size()
        // left == right까지 가도 K가 괜찮은거임.
        for(ll j = 1 ; j <= right - left - 1; ++j) {
            ans += j;
        }
    }
    cout<<ans;
}