#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll N, ans;
vector<ll> money;

bool comp (ll a, ll b) {
    return a > b;    
}

void init() {
    ll product = 1;
    for(ll i = 0 ; i < 15 ; i++) {
        money.push_back(product);
        product *= 10;
    }

    ll product2 = 25;
    for(ll i = 0 ; i < 7 ; i++) {
        money.push_back(product2);
        product2 *= 100;
    }
}

void sol(ll idx, ll restNumber, ll cnt) {
    if(idx > 22) return;
    // printf("%lld %lld %lld\n", idx, restNumber ,cnt);
    if(restNumber == 0 || idx == 22) {
        if(restNumber != 0) return;

        ans = min(ans, cnt);
        return;
    }

    ll newNumber = restNumber / money[idx];
    if(idx == 21) {
        sol(idx + 1, restNumber % money[idx], cnt + newNumber);
    } else {
        if(newNumber == 0) sol(idx + 1 , restNumber, cnt);
        else {
            for(int i = 1 ; i <= newNumber ; i++) {
                sol(idx + 1, restNumber - i * money[idx], cnt + i);
            }
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    init();
    sort(money.begin(), money.end(), comp);
    // printf("%d\n", money[20]);
    ll t;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &N);
        ans = 1e15;
        sol(0, N, 0);
        // ll printNumber = 
        // for(ll i = 0 ; i < money.size() ; i++) {
        //     if(N / money[i]) {
        //         ans += N / money[i];
        //         N %= money[i];
        //     }
        // }
        printf("%lld\n", ans);
    }
}