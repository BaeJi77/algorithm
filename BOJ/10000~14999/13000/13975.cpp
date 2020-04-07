#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;

ll N;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    ll t;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &N);
        priority_queue<ll> pq;
        for(ll i = 0 ; i < N ; i++) {
            ll k;
            scanf("%lld", &k);
            pq.push(-k);
        }

        ll ans = 0;
        for(ll i = 0 ; i < N - 1; i++) {
            ll first = pq.top();
            pq.pop();
            ll second = pq.top();
            pq.pop();
            ans += -(first + second);
            pq.push(first + second);
        }

        printf("%lld\n", ans);
    }
}