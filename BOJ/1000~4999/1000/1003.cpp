#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int dp0[50];
int dp1[50];

int solve0(int num) {
    if(num == 0)
        return 1;
    if(num == 1)
        return 0;
    
    int& ret = dp0[num];
    if(ret != -1)
        return ret;
    
    return ret = solve0(num - 1) + solve0(num - 2);
}

int solve1(int num) {
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    
    int& ret = dp1[num];
    if(ret != -1)
        return ret;
    
    return ret = solve1(num - 1) + solve1(num - 2);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp0, -1, sizeof(dp0));
    memset(dp1, -1, sizeof(dp1));
    int t;
    scanf("%d", &t);
    while(t--) {
        int N;
        scanf("%d", &N);
        printf("%d %d\n", solve0(N), solve1(N));
    }
}