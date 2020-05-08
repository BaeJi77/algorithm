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

ll N, M;
ll members[1000001];

ll solve() {
    ll left = 1;
    ll right = 1e13;
    ll ans = 1e13 + 1;
    while(left <= right) {
        ll mid = (left + right) / 2; // 걸리는 시간
        ll cnt = 0;
        for(int i = 0 ; i < N ; ++i) 
            cnt += mid / members[i];
        
        if(cnt >= M) {
            ans = min(ans, mid);
            right = mid - 1;
        } else 
            left = mid + 1;
    }
    return ans;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; ++i)
        scanf("%lld", &members[i]);
    printf("%lld", solve());
}