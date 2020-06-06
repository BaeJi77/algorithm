#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> vt;

ll N, T;
ll ans;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    
    scanf("%lld %lld", &N, &T);

    for(int i = 0 ; i < N ; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        vt.push_back({a, b});
    }

    sort(vt.begin(), vt.end(), [](pair<ll, ll> x, pair<ll, ll> y) -> bool {
        if(x.second != y.second) return x.second > y.second;
        return x.first > y.first;
    });

    for(ll i = 0 ; i < N ; i++) {
        ans += (T - 1 - i) * vt[i].second + vt[i].first;
    }

    printf("%lld\n", ans);
}