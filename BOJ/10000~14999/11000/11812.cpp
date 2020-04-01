#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;
typedef long long ll;

ll N,K,Q;

vector<ll> findParents(ll start) {
    vector<ll> ret;
    ret.push_back(start);
    while(start > 1) {
        ll nowParent = ((start + K - 2)/ K);
        ret.push_back(nowParent);
        start = nowParent;
    }
    return ret;
}

ll calDist(ll a, ll b) {
    vector<ll> aPar = findParents(a); 
    vector<ll> bPar = findParents(b);
    
    ll firstSamePar = 0;
    ll aIdx = -1;
    ll bIdx = -1;
    vector<ll> samePar;
    for(ll i = 0 ; i < aPar.size() ; i++) {
        for(ll j = 0 ; j < bPar.size() ; j++) {
            if(aPar[i] == bPar[j]) {
                if(firstSamePar == 0) {
                    firstSamePar = aPar[i];
                    aIdx = i;
                    bIdx = j;
                }
            }
        }
    }

    ll ans = aIdx + bIdx;;
    return ans;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%lld %lld %lld", &N, &K, &Q);
    for(ll i = 0 ; i < Q ; i++) {
        ll a,b;
        scanf("%lld %lld", &a, &b);
        if(K == 1) 
            printf("%lld\n", a > b ? a - b : b - a);
        else 
            printf("%lld\n", calDist(a, b));
    }
}