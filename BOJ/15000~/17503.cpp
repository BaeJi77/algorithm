#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;
typedef long long ll;

const ll MAX = 2147483647;

ll N, M, K;
vector<pair<int, int> > vt;

ll solve() {
    ll left = 0;
    ll right = MAX;
    while(left <= right) {
        ll mid = (left + right) / 2;
        
        vector<ll> temp;
        ll cnt = 0;
        for(int i = 0 ; i < vt.size() ; i++) {
            ll dosoo = vt[i].second;
            ll like = vt[i].first;
            if(mid < dosoo) continue;
            temp.push_back(like);
        }

        if(temp.size() < N) {
            left = mid + 1;
            continue;
        }

        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        ll totalLike = 0;
        for(int i = 0 ; i < N ; i++) totalLike += temp[i];

        if(totalLike >= M) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return (left == MAX + 1) ? -1 : left;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%lld %lld %lld", &N, &M, &K);
    ll tempSum = 0;
    for(ll i = 0 ; i < K ; i++) {
        ll a,b;
        scanf("%lld %lld", &a, &b);
        vt.push_back(make_pair(a, b));
    }

    printf("%lld", solve());
}