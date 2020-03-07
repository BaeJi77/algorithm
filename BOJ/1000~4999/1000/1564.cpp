#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1e12;

int N;

int numberOfFive2(ll num) {
    if(num % 10 == 0)
        return 0;
    if((num * 2) % 10 != 0)
        return 0;

    int ret = 0;
    while(1) {
        if(num == 0)
            break;
        if(num % 5 == 0) {
            ret++;
        } else {
            break;
        }
        num /= 5;
    }
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    ll ans = 1;
    
    for(int i = 1 ; i <= N ; i++) {
        ll newProduct = i;
        while(1) {
            if((newProduct % 10) == 0)
                newProduct /= 10;
            else
                break;
        }
        ans *= newProduct;

        ll fiveCnt = numberOfFive2(newProduct);
        for(int i = 0 ; i < fiveCnt ; i++)
            ans /= 10;
        
        ans %= mod;
    }
    printf("%05lld", ans % 100000);
}

/*
9499 150272 * 9500 => 1427584000
      50272 * 9500 =>  477584000
9500 477584000
*/