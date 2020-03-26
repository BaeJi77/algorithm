#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX = 987654321;

int N;
int map[1010][3];
int dp[1010][3];

int solve(int idx, int now) {
    if(idx == 0)
        return 0;
    
    int& ret = dp[idx][now];
    if(ret != MAX)
        return ret;

    for(int i = 0 ; i < 3 ; i++) {
        if(now != i) ret = min(ret, solve(idx - 1, i) + map[idx - 1][i]);
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < 3; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i = 0 ; i < 1010 ; i++) 
        for(int j = 0 ; j < 3; j++)
            dp[i][j] = MAX;
    

    printf("%d", min(solve(N, 0), min(solve(N, 1), solve(N, 2))));
}