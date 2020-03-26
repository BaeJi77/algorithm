#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int SIZE = 1e6;
const int MAX = 987654321;

int N;
int dp[SIZE + 10];

int solve(int num) {
    if(num < 1)
        return MAX;
    if(num == 1)
        return 0;

    int& ret = dp[num];
    if(ret != MAX)  
        return ret;
    
    if(num % 3 == 0) ret = min(ret, solve(num / 3) + 1);
    if(num % 2 == 0) ret = min(ret, solve(num / 2) + 1);
    if(num - 1 > 0) ret = min(ret, solve(num - 1) + 1);

    return ret;
}


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++) 
        dp[i] = MAX;
    printf("%d\n", solve(N));
}