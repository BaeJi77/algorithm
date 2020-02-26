#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll F (ll N) {
    ll ret = 0;
    ll tenProduct = 1;
    ll tempN = N;
    for(ll i = 1 ; i <= N ; i *= 10) {
        i == 1 ? tenProduct = 1 : tenProduct *= 10;
        ll restNowNumber = tempN % 10;
        tempN /= 10;
        ll notN = 9 - restNowNumber;
        ret += notN * tenProduct;
    }
    
    return ret;
}

ll cal(ll N) {
    ll goodN = 0;
    ll tempN = N;
    ll tenNumber = 0;
    ll topDigitNumber = 0;
    while(tempN != 0) {
        if(tempN / 10 == 0) 
            topDigitNumber = tempN;
        tempN /= 10;
        tenNumber++;
    }

    if(topDigitNumber < 5)
        goodN = N;
    if(topDigitNumber >= 5) {
        goodN = 5;
        for(int i = 0 ; i < tenNumber - 1 ; i++) {
            goodN *= 10;
        }
    }

    return goodN;
}

// 규착: 
// 1. 10일때는 5가 가장 100일때는 50이 가장 하지만 100일때 50전까지는 항상 가장 높았던 수가 가장 사랑스러움

int main() {
    freopen("input.txt","r",stdin);
    ll t;
    scanf("%lld", &t);
    while(t--) {
        ll N;
        scanf("%lld", &N);
    
        ll newN = cal(N);
        ll newRet = newN * F(newN);

        printf("%lld\n", newRet);
    }
}
 