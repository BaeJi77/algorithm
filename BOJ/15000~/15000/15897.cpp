#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int N;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    if(N == 1) {
        printf("1");
        return 0;
    } else if (N == 2) {
        printf("3");
        return 0;
    }

    ll i = 2;
    ll newAns = N + 1;
    while(1) {
        ll nextI = ((N-1)/((N-1)/i)) + 1;
        newAns += ((N-1) / i + 1) * (nextI - i);
        
        i = nextI;

        if(i == N)
            break;
    }
    
    // int maxJumb = N-1;
    // int jump = N-1;
    // int blockCnt = 1;
    // while(1) {
    //     if(jump == 0)
    //         break;
        
    //     newAns += ((jump / blockCnt) + 1) * (N - 1 / ((jump/blockCnt) + 1));
    //     jump /= blockCnt;
    //     blockCnt++;
    // }

    // 수학 공식
    // printf("log(N+1), N+1: %lf %d\n", (double)log(N+1), N-1);
    // printf("%lf\n", (double)(N-1) * log(N+1) + (double)N);
    printf("%lld\n", newAns);
}