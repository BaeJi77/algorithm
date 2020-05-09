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

ll N, K;
ll totalLenght;
pair<ll, ll> map[100001];

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%lld %lld", &N, &K);
    for(ll i = 1 ; i <= N ; ++i) {
        ll k;
        scanf("%lld", &k);
        map[i] = make_pair(totalLenght, totalLenght + k);
        totalLenght += k;
    }

    if(K == 0) {
        printf("1");
        return 0;
    }
    if(K == totalLenght) {
        printf("%lld", N);
        return 0;
    }
    
    ll ans = 0;
    if(K > totalLenght) { // 돌아오는 경우
        K = totalLenght - K % totalLenght;
        bool isDuplicateLocated = false;
        for(ll i = 1 ; i <= N ; ++i) {
            ll left = map[i].first;
            ll right = map[i].second;
            if(left <= K && K <= right) {
                ans = i;
                break;
            }
        }
    } else { // 반환점으로 가는 경우
        bool isDuplicateLocated = false;
        for(ll i = 1 ; i <= N ; ++i) {
            ll left = map[i].first;
            ll right = map[i].second;
            if(K == right) {
                ans = i + 1;
                break;
            }
            if(left < K && K < right) {
                ans = i;
                break;
            }
        }
    }
    
    printf("%lld", ans);
}