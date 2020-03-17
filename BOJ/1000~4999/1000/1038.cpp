#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;

ll N, ans, cnt;
ll arr[1000010];

void countDecreaseNumber(ll preNumber, ll nowDigit) {
    ll lastDigitNumber = preNumber % 10;
    preNumber *= 10;
    if(nowDigit == 1) {
        for(ll i = 0 ; i < lastDigitNumber ; i++) {
            cnt++;
            // printf("%lld %lld\n", preNumber + i, cnt);
            arr[cnt] = preNumber + i;
            if(cnt == N) {
                ans = preNumber + i;
            }
        }
    } else {
        for(ll i = 0 ; i < lastDigitNumber ; i++) {
            ll nextNumber = preNumber + i;
            countDecreaseNumber(nextNumber, nowDigit - 1);
        }
    }
}


int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    scanf("%lld", &N);
    
    if(N < 10) {
        printf("%lld", N);
        return 0;
    }

    cnt = 9;
    ll digit = 2;
    while(1) {
        if(digit == 11) 
            break;
        
        for(ll i = digit - 1 ; i < 10 ; i++) {
            countDecreaseNumber(i, digit - 1);
        }
        digit++;
    }
    
    if(N > 1022) printf("-1");
    else printf("%lld", arr[N]);
}