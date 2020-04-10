#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

bool primes[10010];

void init() {
    memset(primes, 1, sizeof(primes));
    primes[0] = false;
    primes[1] = false;
    for(int i = 2; i <= 10000 ; ++i) {
        if(primes[i]) {
            for(int j = i * i ; j <= 10000 ; j += i) 
                primes[j] = false;
        }
    }
}

int makeNextNumber(int preNumber) {
    int ret = 0;
    while(preNumber != 0) {
        int firstDigit = (preNumber % 10);
        ret += firstDigit * firstDigit;
        preNumber /= 10;
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    init();
    int t;
    scanf("%d", &t);
    while(t--) {
        int tc, M;
        scanf("%d %d", &tc, &M);
        printf("%d %d ", tc, M);
        if(primes[M]) {
            bool visited[10010] = {0,};
            int number = M;
            while(1) {
                if(visited[number]) {
                    printf("NO\n");
                    break;
                }
                if(number == 1) {
                    printf("YES\n");
                    break;
                }
                visited[number] = true;
                number = makeNextNumber(number);
            }
        } else {
            printf("NO\n");
        }
    }
}