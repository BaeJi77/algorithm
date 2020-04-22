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

ll N;
ll binary() {
    ll left = 1;
    ll right = 1e9;
    ll ans = 0;
    while(left <= right) {
        ll mid = (left + right) / 2;
        ll cal = mid * (mid + 1) / 2;
        if(cal <= N) {
            left = mid + 1;
            ans = max(ans, mid);
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%lld", &N);
        printf("%lld\n", binary());
    }
}