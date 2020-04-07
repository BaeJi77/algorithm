#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

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

        ll ans = 1;
        for(ll i = 0 ; i < N-1 ; i++) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();

            ans *= (a * b) % mod;
            ans %= mod;
            pq.push(-((a * b)));
        }
        
        printf("%lld\n", ans % mod);
    }
}