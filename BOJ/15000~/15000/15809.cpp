#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

ll N, M;
ll p[100001];

ll find(ll x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(ll a, ll b) {
    ll aa = find(a);
    ll bb = find(b);
    p[aa] += p[bb];
    p[bb] = aa;
}

void diffMerge(ll a, ll b) {
    ll aa = find(a);
    ll bb = find(b);
    ll aPower = -p[aa];
    ll bPower = -p[bb];
    if(p[aa] == p[bb]) { // 둘 다 죽여
        p[aa] = 0;
        p[bb] = 0;
    }
    
    if(aPower > bPower) { // a가 더 큰 경우
        p[aa] = -(aPower - bPower);
        p[bb] = aa;
    }

    if(bPower > aPower) { // b가 더 큰 경우
        p[bb] = -(bPower - aPower);
        p[aa] = bb;
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%lld %lld", &N, &M);
    for(ll i = 1 ; i <= N ; ++i) {
        ll a;
        scanf("%lld", &a);
        p[i] = -a;
    }

    for(ll i = 0 ; i < M ; ++i) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a == 1) {
            merge(b, c);
        }
        if(a == 2) {
            diffMerge(b, c);
        }
    }

    vector<ll> ans;
    for(ll i = 1 ; i <= N ; ++i) {
        if(p[i] < 0) ans.push_back(-p[i]);
    }

    sort(ans.begin(), ans.end());
    printf("%lld\n", ans.size());
    for(auto val : ans) 
        printf("%lld ", val);
}