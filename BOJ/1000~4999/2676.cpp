#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;


int main() {
    freopen("input.txt","r",stdin);    
    ll test;
    scanf("%lld", &test);
    while(test--) {
        ll a,b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", 1 + (a - b) * b);
    }
}