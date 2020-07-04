#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

const int MAX = 2000001;

typedef long long ll;

bool check[MAX];
vector<ll> primes;

void era() {
    for(int i = 2 ; i * i < MAX ; i++) {
        if(check[i] == false) {
            for(int j = i * i ; j < MAX ; j += i) {
                check[j] = true;
            }
        }
    }

    for(int i = 2 ; i < MAX ; i++)
        if(check[i] == false) primes.push_back(i);
}

bool isPrime(ll number) {
    for(int i = 0 ; i < primes.size(); ++i) {
        if(sqrt(number) < primes[i]) break;
        if(number % primes[i] == 0) return false;
    }
    return true;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    era();    

    int t;
    scanf("%d", &t);
    while(t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll sum = a + b;

        if(sum < 4) {
            printf("NO\n");
            continue;
        }
        if(sum % 2 == 0) {
            printf("YES\n");
            continue;
        }

        sum -= 2;
        if(isPrime(sum)) printf("YES\n");
        else printf("NO\n");
    }
}