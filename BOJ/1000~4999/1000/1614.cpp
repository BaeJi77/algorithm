#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll injuerd, ableCnt;

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    scanf("%d", &injuerd);
    scanf("%d", &ableCnt);

    /*
    1: 1 9 17 25 => +8씩 증가함
    2: 2 8 10 16 => +6 +2 번가라가면서
    3: 3 7 11 15 => +4씩 증가함
    4: 4 6 12 14 => +2 +6 번가라가면서
    5: 5 13 21 29 => +8씩 증가함
    */
    ll ans = injuerd;
    if(ableCnt != 0)  {
        ll a = ableCnt % 2;
        switch (injuerd)
        {
        case 1:
            ans += ableCnt * 8;
            break;
        
        case 2:
            // ableCnt -= a;
            ans += ableCnt/2 * 8;
            if(a) ans += 6;
            break;
        
        case 3:
            ans += ableCnt * 4;
            break;

        case 4:
            // ableCnt -= a;
            ans += ableCnt/2 * 8;
            if(a) ans += 2;
            break;

        case 5:
            ans += ableCnt * 8;
            break;

        default:
            break;
        }
    }
    printf("%lld", ans - 1);
}