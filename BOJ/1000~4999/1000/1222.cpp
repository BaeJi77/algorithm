#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX = 2e6;

ll N, ans;
ll arr[MAX+10];
void cal(int number) {
    for(int j = 1 ; j * j <= number ; j++) {
        if(number % j == 0) {
            arr[j]++;
            if(j != number / j) arr[number / j]++;
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)  {
        int number;
        scanf("%d", &number);
        cal(number);
    }
    
    for(int i = 1 ; i < MAX+2 ; i++) {
        if(arr[i] < 2) continue;
        ans = max(ans, i * arr[i]);
    }
    printf("%lld", ans);
}