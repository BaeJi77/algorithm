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

ll N, total;
ll map[1001][1001];

ll solve() {
    ll left = 0;
    ll right = 1e10;
    ll ans = 1e11;
    while(left <= right) {
        ll mid = (left + right) / 2; // 서버실이 중간이 켜지는데 걸리는 시간
        ll computerCnt = 0;
        for(ll i = 0 ; i < N ; ++i) {
            for(ll j = 0 ; j < N ; ++j) {
                if(mid >= map[i][j]) computerCnt += map[i][j];
                else computerCnt += mid;
            }
        }

        if(computerCnt * 2 >= total) {
            right = mid - 1;
            ans = min(ans, mid);
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(ll i = 0 ; i < N ; ++i) {
        for(ll j = 0 ; j < N ; ++j) {
            scanf("%lld", &map[i][j]);
            total += map[i][j];
        }
    }
    printf("%lld", solve());
}