#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll mod = 1234567891;
const ll r = 31;

ll N;
ll arr[51];

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%lld", &N);
    ll ans = 0;
    ll product = 1;
    getchar();
    for(ll i = 0 ; i < N ; i++) {
        char k;
        scanf("%c", &k);
        ll charToll = k - 'a' + 1;
        ans += (charToll * product) % mod;
        ans %= mod;
        product *= r;
        product %= mod;
    }
    printf("%lld", ans);
}