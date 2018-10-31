// https://www.acmicpc.net/problem/2098
// 외판원 순회

#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>

int N,dp[20][10000],W[20][20];
int ended = pow(2,N);

int solve(int cur,int bit){
    if(bit == ended)
        return 0;
    
    int &ret = dp[cur][bit];
    if(ret != -1)
        return ret;
    
    ret = 0;

    return ret;
}

int main(){
    scanf("%d" , &N);
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d" , &W[i][j]);
        }
    }

    int minn = INT_MAX;
    for(int i = 0 ; i < N ; i++){
        minn = solve(i,1<<i);
    }
}