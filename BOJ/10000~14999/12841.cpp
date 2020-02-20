#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll MAX = 1000000;

ll N;
ll crossCost[MAX+1];
ll leftCost[MAX+1];
ll tempRightCost[MAX+1];
ll rightCost[MAX+1];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%lld", &N);
    for(ll i = 0 ; i < N ; i++) {
        scanf("%lld", &crossCost[i]);
    }

    ll tempSum = 0;
    for(ll i = 1 ; i < N ; i++) {
        ll a;
        scanf("%lld", &a);
        tempSum += a;
        leftCost[i] = tempSum;
    }
    
    for(ll i = 0 ; i < N-1 ; i++) {
        scanf("%lld", &tempRightCost[i]);
    }

    tempSum = 0;
    for(ll i = N-2 ; i >= 0 ; i--) {
        tempSum += tempRightCost[i];
        rightCost[i] = tempSum;
    }

    ll minValue = 10000000000;
    ll minIndex = -1;
    for(ll i = 0 ; i < N ; i++) {
        ll nowCost = crossCost[i] + leftCost[i] + rightCost[i];
        if(nowCost < minValue) {
            minValue = nowCost;
            minIndex = i;
        }
    }

    printf("%lld %lld", minIndex + 1, minValue);
}