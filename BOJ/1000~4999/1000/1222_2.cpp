#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX = 2e6;

ll N, ans;
ll arr[MAX+10];

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)  {
        int number;
        scanf("%d", &number);
        arr[number]++;
    }

    for(int i = 1 ; i < MAX + 1 ; i++) {
        ll cnt = 0;
        for(int j = i ; j < MAX + 1 ; j += i) {
            cnt += arr[j];
        }
        if(cnt >= 2) ans = max(ans, cnt * i);
    }
    
    printf("%lld", ans);
}