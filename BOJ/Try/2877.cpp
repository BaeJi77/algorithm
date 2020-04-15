#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;

ll K, cnt;
// ll numbers[1000000010];
string ans;

void solve(ll digit, string number) {
    if(cnt > K) return;
    if(digit == 1) {
        // numbers[cnt] = number;
        if(cnt == K) ans = number;
        cnt++;
        return;
    }

    solve(digit - 1, number + "4");
    solve(digit - 1, number + "7");
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%lld", &K);
    cin>>K;
    if(K == 1) {
        cout<<4;
        return 0;
    } else if(K == 2) {
        cout<<7;
        return 0;
    } else {
        cnt = 3;
        ll digit = 2;
        while(1) {
            if(cnt > K) break;
            solve(digit, "4");
            solve(digit, "7");
            digit++;
        }
    }
    
    cout<<ans<<endl;
    // printf("%lld\n", numbers[K]);
}

// 4  7 44  47  74  77    444 447 474   477 777
// 1 10 11 100 101 110  110 111 1001  1100 1101
// 1 2  3   4   5