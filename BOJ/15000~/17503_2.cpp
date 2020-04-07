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
vector<pair<ll, ll> > vt;
priority_queue<ll> pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%lld %lld %lld", &N, &M, &K);
    for(ll i = 0 ; i < K ; i++) {
        ll a,b;
        scanf("%lld %lld", &a, &b);
        vt.push_back(make_pair(b, a));
    }
    sort(vt.begin(), vt.end());

    int sum = 0; // 선호도 합
    for(int i = 0 ; i < vt.size() ; i++) {
        if(pq.size() == N) {
            sum += pq.top();
            pq.pop();
        }

        sum += vt[i].second;
        pq.push(-vt[i].second);        
        
        if(pq.size() == N && sum >= M) {
            printf("%lld\n", vt[i].first);
            return 0;
        }
    }
    printf("-1\n");
}